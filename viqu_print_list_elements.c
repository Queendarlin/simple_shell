#include "shell.h"

/**
 * viqu_print_list_elements - Function to print all elements of a list_t
 * linked list.
 * @viqu_h: The actual pointer to the first node of the linked list.
 *
 * Return: The correct size of the linked list.
 */

size_t viqu_print_list_elements(const list_t *viqu_h)
{
	size_t viqu_index = 0;

	while (viqu_h)
	{
		viqu_puts(viqu_int_to_string(viqu_h->viqu_num, 10, 0));
		viqu_putchar(':');
		viqu_putchar(' ');

		viqu_puts(viqu_h->viqu_str ? viqu_h->viqu_str : "(nil)");

		viqu_puts("\n");

		viqu_h = viqu_h->viqu_next;
		viqu_index++;
	}

	return (viqu_index);
}
