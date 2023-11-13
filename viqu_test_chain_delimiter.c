#include "shell.h"

/**
 * viqu_test_chain_delimiter - Function to test if the current character in
 * the buffer is a chain delimiter.
 * @viqu_info: Pointer to the structure containing shell information.
 * @viqu_buf: Char buffer storing the command line.
 * @viqu_p: Address of the current position in the buffer.
 *
 * Return: 1 if the current character is a chain delimiter, 0 otherwise.
 */

int viqu_test_chain_delimiter(info_t *viqu_info, char *viqu_buf,
		size_t *viqu_p)
{
	size_t viqu_j = *viqu_p;

	if (viqu_buf[viqu_j] == '|' &&
			viqu_buf[viqu_j + 1] == '|')
	{
		viqu_buf[viqu_j] = 0;
		viqu_j++;
		viqu_info->viqu_cmd_bufffer_type = VIQU_INSTRUCT_OR;
	}
	else if (viqu_buf[viqu_j] == '&' && viqu_buf[viqu_j + 1] == '&')
	{
		viqu_buf[viqu_j] = 0;
		viqu_j++;
		viqu_info->viqu_cmd_buffer_type = VIQU_INSTRUCT_AND;
	}
	else if (viqu_buf[viqu_j] == ';')
	{
		viqu_buf[viqu_j] = 0;
		viqu_info->viqu_cmd_buffer_type = VIQU_INSTRUCT_CHAIN;
	}
	else
		return (0);
	*viqu_p = viqu_j;
	return (1);
}
