#include "shell.h"

/**
 * viqu_suffix_node - Function that adds a node to the end of the linked list.
 * @viqu_head: A pointer to the head node of the linked list.
 * @viqu_string: The string value to be stored in the new node.
 * @viqu_n: An integer value used as an index in history.
 * Return: A pointer to the newly created node, or NULL on failure.
 */

list_t *viqu_suffix_node(list_t **viqu_head, const char *viqu_string,
		int viqu_n)
{
	list_t *viqu_new_node, *viqu_current_node;

	if (!viqu_head)
		return (NULL);

	viqu_current_node = *viqu_head;
	viqu_new_node = malloc(sizeof(list_t));
	if (!viqu_new_node)
		return (NULL);

	viqu_memory_set((void *)viqu_new_node, 0, sizeof(list_t));
	viqu_new_node->viqu_n = viqu_n;

	if (viqu_string)
	{
		viqu_new_node->viqu_string = viqu_custom_strdup(viqu_string);
		if (!viqu_new_node->viqu_string)
		{
			free(viqu_new_node);
			return (NULL);
		}
	}

	if (viqu_current_node)
	{
		while (viqu_current_node->viqu_next)
			viqu_current_node = viqu_current_node->viqu_next;

		viqu_current_node->viqu_next = viqu_new_node;
	}
	else
	{
		*viqu_head = viqu_new_node;
	}

	return (viqu_new_node);
}
