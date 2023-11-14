#include "shell.h"

/**
 * viqu_input_buf - buffers chained commands
 * @viqu_info: parameter struct
 * @viqu_adbfr: address of buffer
 * @viqu_len: address of len var
 *
 * Return: bytes read
 */
ssize_t viqu_input_buf(info_t *viqu_info, char **viqu_adbfr, size_t *viqu_len)
{
	ssize_t viqu_r = 0;
	size_t viqu_lptr = 0;

	if (!*viqu_len)
	{
		free(*viqu_adbfr);
		*viqu_adbfr = NULL;
		signal(SIGINT, sigintHandler);
#if USE_GETLINE
		viqu_r = getline(viqu_adbfr, &viqu_lptr, stdin);
#else
		r = viqu_getline(viqu_info, viqu_adbfr, &viqu_lptr);
#endif
		if (viqu_r > 0)
		{
			if ((*viqu_adbfr)[viqu_r - 1] == '\n')
			{
				(*viqu_adbfr)[viqu_r - 1] = '\0';
				viqu_r--;
			}
			viqu_info->viqu_linecount_flag = 1;
			viqu_remove_comments(*viqu_adbfr);
			viqu_build_history_list(viqu_info, *viqu_adbfr, viqu_info->viqu_histcount++);
			{
				*viqu_len = viqu_r;
				viqu_info->viqu_cmd_buf = viqu_adbfr;
			}
		}
	}
	return (viqu_r);
}


#include "shell.h"

/**
 * viqu_get_input - gets a line minus the newline
 * @viqu_info: parameter struct
 *
 * Return: bytes read
 */

ssize_t viqu_get_input(info_t *viqu_info)
{
	static char *viqu_buf;
	static size_t viqu_i, viqu_j, viqu_len;
	ssize_t viqu_r = 0;
	char **viqu_buf_p = &(viqu_info->viqu_arg), *viqu_p;

	viqu_putchar(BUF_FLUSH);
	viqu_r = viqu_input_buf(viqu_info, &viqu_buf, &viqu_len);
	if (viqu_r == -1)
		return (-1);
	if (viqu_len)
	{
		viqu_j = viqu_i;
		p = viqu_buf + viqu_i;

		viqu_check_chain(viqu_info, viqu_buf, &viqu_j, viqu_i, viqu_len);
		while (viqu_j < viqu_len)
		{
			if (viqu_is_chain(viqu_info, viqu_buf, &viqu_j))
				break;
			viqu_j++;
		}

		viqu_i = viqu_j + 1;
		if (viqu_i >= viqu_len)
		{
			viqu_i = viqu_len = 0;
			viqu_info->viqu_cmd_buf_type = CMD_NORM;
		}

		*viqu_buf_p = viqu_p;
		return (viqu_strlen(viqu_p));
	}

	*viqu_buf_p = viqu_buf;
	return (viqu_r);
}

#include "shell.h"

/**
 * viqu_read_buf - reads a buffer
 * @viqu_info: parameter struct
 * @viqu_buf: buffer
 * @viqu_i: size
 *
 * Return: r
 */
ssize_t read_buf(info_t *viqu_info, char *viqu_buf, size_t *viqu_i)
{
	ssize_t viqu_r = 0;

	if (*viqu_i)
		return (0);
	viqu_r = read(viqu_info->viqu_readfd, viqu_buf, READ_BUF_SIZE);
	if (viqu_r >= 0)
		*viqu_i = viqu_r;
	return (viqu_r);
}

#include "shell.h"

/**
 * viqu_getline - gets the next line of input from STDIN
 * @viqu_info: parameter struct
 * @viqu_ptr: address of pointer to buffer, preallocated or NULL
 * @viqu_length: size of preallocated ptr buffer if not NULL
 *
 * Return: s
 */
int viqu_getline(info_t *viqu_info, char **viqu_ptr, size_t *viqu_length)
{
	static char viqu_buf[READ_BUF_SIZE];
	static size_t viqu_i, viqu_len;
	size_t viqu_k;
	ssize_t viqu_r = 0, viqu_s = 0;
	char *viqu_p = NULL, *viqu_new_p = NULL, *viqu_c;

	viqu_p = *viqu_ptr;
	if (viqu_p && viqu_length)
		viqu_s = *viqu_length;
	if (viqu_i == viqu_len)
		viqu_i = viqu_len = 0;

	viqu_r = viqu_read_buf(viqu_info, viqu_buf, &viqu_len);
	if (viqu_r == -1 || (viqu_r == 0 && viqu_len == 0))
		return (-1);
	viqu_c = viqu_strchr(viqu_buf + viqu_i, '\n');
	viqu_k = viqu_c ? 1 + (unsigned int)(viqu_c - viqu_buf) : viqu_len;
	viqu_new_p = viqu_realloc(viqu_p, viqu_s, viqu_s ? viqu_s + viqu_k :viqu_ k + 1);
	if (!viqu_new_p)
		return (viqu_p ? free(viqu_p), -1 : -1);

	if (viqu_s)
		viqu_strncat(viqu_new_p, viqu_buf + viqu_i, viqu_k - i);
	else
		viqu_strncpy(viqu_new_p, viqu_buf + viqu_i, viqu_k - viqu_i + 1);

	viqu_s += viqu_k - viqu_i;
	viqu_i = viqu_k;
	viqu_p = viqu_new_p;

	if (viqu_length)
		*viqu_length = viqu_s;
	*viqu_ptr = viqu_p;
	return (viqu_s);
}

#include "shell.h"

/**
 * viqu_sigintHandler - blocks ctrl-C
 * @viqu_sig_num: the signal number
 *
 * Return: void
 */

void viqu_sigintHandler(__attribute__((unused))int viqu_sig_num)
{
	viqu_puts("\n");
	viqu_puts("$ ");
	viqu_putchar(BUF_FLUSH);
}
