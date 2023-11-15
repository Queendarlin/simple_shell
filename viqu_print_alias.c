#include "shell.h"

/**
 * viqu_print_alias - Function that prints the content of an alias string.
 * @viqu_node: The alias node to be printed.
 *
 * Return: 0 when successful or 1 on error.
 */
int viqu_print_alias(list_t *viqu_node)
{
	char *viqu_p = NULL, *viqu_a = NULL;

	if (viqu_node)
	{
		viqu_p = viqu_get_str_char(viqu_node->viqu_str, '=');

		for (viqu_a = viqu_node->viqu_str; viqu_a <= viqu_p; viqu_a++)
		viqu_putchar(*viqu_a);
		viqu_putchar('\'');
		viqu_puts(viqu_p + 1);
		viqu_puts("'\n");

		return (0);
	}
	return (1);
}
