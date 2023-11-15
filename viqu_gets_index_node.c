#include "shell.h"

/**
 * viqu_gets_index_node - A function that gets the index of a node in
 * a linked list.
 * @viqu_head: The main pointer to the list head.
 * @viqu_node: The singular pointer to the node.
 *
 * Return: Index of the node when successful or -1 when the node is not found.
 */

ssize_t viqu_gets_index_node(list_t *viqu_head, list_t *viqu_node)
{
	size_t viqu_index = 0;

	while (viqu_head)
	{
		if (viqu_head == viqu_node)
			return (viqu_index);

		viqu_head = viqu_head->viqu_next;
		viqu_index++;
	}

	return (-1);
}
