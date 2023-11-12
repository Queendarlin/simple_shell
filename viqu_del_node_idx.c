#include "shell.h"

/**
 * viqu_del_node_idx - Function to delete the node at the
 * specified index in a linked list
 * @viqu_head: A double pointer
 * @viqu_index: The to delete the node
 * Return: 1 when successful or 0 on failure.
 */

int viqu_del_node_idx(list_t **viqu_head, unsigned int viqu_index)
{
	list_t *viqu_node, *viqu_prev_node;
	unsigned int viqu_i = 0;

	if (!viqu_head || !*viqu_head)
		return (0);

	if (!viqu_index)
	{
		viqu_node = *viqu_head;
		*viqu_head = (*viqu_head)->next;
		free(viqu_node->viqu_str);
		free(viqu_node);
		return (1);
	}

	viqu_node = *viqu_head;
	while (viqu_node)
	{
		if (viqu_i == viqu_index)
		{
			viqu_prev_node->viqu_next = viqu_node->viqu_next;
			free(viqu_node->viqu_str);
			free(viqu_node);
			return (1);
		}
		viqu_i++;
		viqu_prev_node = viqu_node;
		viqu_node = viqu_node->viqu_next;
	}

	return (0);
}
