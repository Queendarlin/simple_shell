#include "shell.h"
/**
 * viqu_receive_input - Function that receives input without the newline
 * @viqu_info: The parameter for the structure
 *
 * Return: All the bytes that has been read
 */

ssize_t viqu_receive_input(info_t *viqu_info)
{
	static char *viqu_buf;
	static size_t viqu_i, viqu_j, viqu_len;
	ssize_t viqu_r = 0;
	char **viqu_buf_p = &(viqu_info->viqu_arg), *viqu_p;

	viqu_putchar(VIQU_FLUSH_BUFFER);
	viqu_r = viqu_buffer_input(viqu_info, &viqu_buf, &viqu_len);
	if (viqu_r == -1)
		return (-1);
	if (viqu_len)
	{
		viqu_j = viqu_i;
		viqu_p = viqu_buf + viqu_i;

		viqu_check_str_chain(viqu_info, viqu_buf, &viqu_j, viqu_i, viqu_len);
		while (viqu_j < viqu_len)
		{
			if (viqu_test_chain_delimiter(viqu_info, viqu_buf, &viqu_j))
				break;
			viqu_j++;
		}

		viqu_i = viqu_j + 1;
		if (viqu_i >= viqu_len)
		{
			viqu_i = viqu_len = 0;
			viqu_info->viqu_cmd_buffer_type = VIQU_INSTRUCT_NORMAL;
		}

		*viqu_buf_p = viqu_p;
		return (viqu_custom_strlen(viqu_p));
	}

	*viqu_buf_p = viqu_buf;
	return (viqu_r);
}
