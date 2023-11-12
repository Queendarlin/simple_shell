#include "shell.h"

/**
 * viqu_renum_hist_list - Function to renumber the linked list’s history
 * @viqu_info: Parameter for maintaining argument structure.
 *
 * Return: The modified number of the history.
 */
int viqu_renum_hist_list(info_t *viqu_info)
{
	list_t *viqu_node = viqu_info->viqu_history;
	int viqu_idx = 0;

	while (viqu_node)
	{
		viqu_node->viqu_num = viqu_idx++;
		viqu_node = viqu_node->viqu_next;
	}

	return (viqu_info->viqu_hist_count = viqu_idx);
}

