#include "shell.h"

/**
 * viqu_print_str_element - Function that traverses a linked list and
 * prints the 'str' element
 * @viqu_head: A pointer to the linked list  first node.
 * If 'str' is NULL, it prints "(nil)".
 * Return: The linked list size
 */
size_t viqu_print_str_element(const list_t *viqu_head)
{
	size_t viqu_index = 0;

	while (viqu_head)
	{
		viqu_puts(viqu_head->viqu_str ? viqu_head->viqu_str : "(nil)");
		viqu_puts("\n");
		viqu_head = viqu_head->next;
		viqu_index++;
	}

	return (viqu_index);
}
