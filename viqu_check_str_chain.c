#include "shell.h"

/**
 * viqu_check_str_chain - Checks if we should continue
 * chaining based on last status.
 * @viqu_info: Pointer to the structure containing shell information.
 * @viqu_buf: Char buffer storing the command line.
 * @viqu_p: Address of the current position in the buffer.
 * @viqu_index: Starting position in the buffer.
 * @viqu_len: Length of the buffer.
 * Return: ..
 */

void viqu_check_str_chain(info_t *viqu_info, char *viqu_buf, size_t *viqu_p,
		size_t viqu_index, size_t viqu_len)
{
	size_t viqu_j = *viqu_p;

	if (viqu_info->viqu_cmd_buffer_type == VIQU_INSTRUCT_AND)
	{
		if (viqu_info->viqu_status)
		{
			viqu_buf[viqu_index] = 0;
			viqu_j = viqu_len;
		}
	}
	if (viqu_info->viqu_cmd_buffer_type == VIQU_INSTRUCT_OR)
	{
		if (!viqu_info->viqu_status)
		{
			viqu_buf[viqu_index] = 0;
			viqu_j = viqu_len;
		}
	}
	*viqu_p = viqu_j;
}
