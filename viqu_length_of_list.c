#include "shell.h"

/**
 * viqu_length_of_list - Function to decide the length of a linked list.
 * @viqu_h: The actual pointer to the first node of the linked list.
 *
 * Return: The specific size of the linked list.
 */

size_t viqu_length_of_list(const list_t *viqu_h)
{
	size_t viqu_index = 0;

	while (viqu_h)
	{
		viqu_h = viqu_h->viqu_next;
		viqu_index++;
	}

	return (viqu_index);
}
