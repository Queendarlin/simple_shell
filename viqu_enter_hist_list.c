#include "shell.h"

/**
 * viqu_enter_hist_list - Function to enter the history of a linked list.
 * @viqu_info: Parameter for maintaining argument structure.
 * @viqu_buf: The parameter for the buffer
 * @viqu_linecount: Parameter to count history based on the lines.
 *
 * Return: 0 when successful.
 */

int viqu_enter_hist_list(info_t *viqu_info, char *viqu_buf, int viqu_linecount)
{
	list_t *viqu_node = NULL;

	if (viqu_info->viqu_history)
		viqu_node = viqu_info->viqu_history;

	viqu_suffix_node(&viqu_node, viqu_buf, viqu_linecount);

	if (!viqu_info->viqu_history)
		viqu_info->viqu_history = viqu_node;

	return (0);
}
