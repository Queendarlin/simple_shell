#include "shell.h"

/**
 * viqu_affix_node - Function that adds a node to the beginning of a
 * linked list.
 * @viqu_head: A pointer to the head node of the list.
 * @viqu_string: The string value to be stored in the new node.
 * @viqu_n: An integer value used as an index in history.
 *
 * Return: A pointer to the newly created node, or NULL on failure.
 */

list_t *viqu_affix_node(list_t **viqu_head, const char *viqu_string,
		int viqu_n)
{
	list_t *viqu_new_head;

	if (!viqu_head)
		return (NULL);
	viqu_new_head = malloc(sizeof(list_t));
	if (!viqu_new_head)
		return (NULL);
	viqu_memory_set((void *)viqu_new_head, 0, sizeof(list_t));
	viqu_new_head->viqu_num = viqu_n;

	if (viqu_string)
	{
		viqu_new_head->viqu_str = viqu_custom_strdup(viqu_string);
		if (!viqu_new_head->viqu_str)
		{
			free(viqu_new_head);
			return (NULL);
		}
	}

	viqu_new_head->viqu_next = *viqu_head;
	*viqu_head = viqu_new_head;

	return (viqu_new_head);
}
