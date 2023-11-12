#include “shell.h”

/**
 * viqu_buffer_input - Function to get input in the buffer
 * @viqu_info: The parameter for the structure
 * @viqu_buf: Pointer to the buffer containing input
 * @viqu_len: Pointer to the size of the buffer
 *
 * Return: The bytes read from the input command
 */
ssize_t viqu_buffer_input(info_t *viqu_info, char **viqu_buf, size_t *viqu_len)
{
	ssize_t viqu_r = 0;
	size_t viqu_len_p = 0;

	if (!*viqu_len)
	{
		free(*viqu_buf);
		*viqu_buf = NULL;
		signal(SIGINT, viqu_get_command_prompt);
#if VIQU_USE_GET_LINE
		viqu_r = getline(viqu_buf, &viqu_len_p, stdin);
#else
		viqu_r = viqu_getsline(viqu_info, viqu_buf, &viqu_len_p);
#endif
		if (viqu_r > 0)
		{
			if ((*viqu_buf)[viqu_r - 1] == '\n')
			{
				(*viqu_buf)[viqu_r - 1] = '\0';
				viqu_r--;
			}
			viqu_info->viqu_linecount_flag = 1;
			viqu_comment_sign_removal(*viqu_buf);
			viqu_enter_hist_list(viqu_info, *viqu_buf, viqu_info->viqu_hist_count++);
			{
				*viqu_len = viqu_r;
				viqu_info->viqu_cmd_buf = viqu_buf;
			}
		}
	}
	return (viqu_r);
}
