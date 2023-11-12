#include "shell.h"


/**
 * viqu_getsline - Function that gets the next line of input
 * @viqu_info: The parameter for the structure
 * @viqu_ptr: The pointer to the buffer containing the input.
 * @viqu_length: The size of the buffer
 *
 * Return: The whole lines of the input
 */

int viqu_getsline(info_t *viqu_info, char **viqu_ptr, size_t *viqu_length)
{
	static char viqu_buf[VIQU_GET_BUFFER_SIZE];
	static size_t viqu_i, viqu_len;
	size_t viqu_k;
	ssize_t viqu_r = 0, viqu_size = 0;
	char *viqu_p = NULL, *viqu_new_p = NULL, *viqu_c;

	viqu_p = *viqu_ptr;
	if (viqu_p && viqu_length)
		viqu_size = *viqu_length;
	if (viqu_i == viqu_len)
		viqu_i = viqu_len = 0;

	viqu_r = viqu_buffer_read(viqu_info, viqu_buf, &viqu_len);
	if (viqu_r == -1 || (viqu_r == 0 && viqu_len == 0))
		return (-1);

	viqu_c = viqu_get_str_char(viqu_buf + viqu_i, '\n');
	viqu_k = viqu_c ? 1 + (unsigned int)(viqu_c - viqu_buf) : viqu_len;
	viqu_new_p = viqu_custom_realloc(viqu_p, viqu_size,
			viqu_size ? viqu_size + viqu_k : viqu_k + 1);
	if (!viqu_new_p)
		return (viqu_p ? free(viqu_p), -1 : -1);

	if (viqu_size)
		viqu_string_concat(viqu_new_p, viqu_buf + viqu_i, viqu_k - viqu_i);
	else
		viqu _copy_string(viqu_new_p, viqu_buf + viqu_i, viqu_k - viqu_i + 1);

	viqu_size += viqu_k - viqu_i;
	viqu_i = viqu_k;
	viqu_p = viqu_new_p;

	if (viqu_length)
		*viqu_length = viqu_size;
	*viqu_ptr = viqu_p;
	return (viqu_size);
}
