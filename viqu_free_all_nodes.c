#include "shell.h"

/**
 * viqu_free_all_nodes - Function to free all nodes in a linked list
 * along with the memory occupied
 * @viqu_head_ptr: A pointer to the head of the list.
 * Return: ..
 */

void viqu_free_all_nodes(list_t **viqu_head_ptr)
{
	list_t *viqu_node, *viqu_next_node, *viqu_head;

	if (!viqu_head_ptr || !*viqu_head_ptr)
		return;

	viqu_head = *viqu_head_ptr;
	viqu_node = viqu_head;

	while (viqu_node)
	{
		viqu_next_node = viqu_node->viqu_next;
		free(viqu_node->viqu_string);
		free(viqu_node);

		viqu_node = viqu_next_node;
	}

	*viqu_head_ptr = NULL;
}
