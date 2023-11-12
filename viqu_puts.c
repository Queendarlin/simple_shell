#include "shell.h"

/**
 * viqu_puts - Function to print a string to the standard output.
 * @viqu_str: Pointer to the string to be printed.
 *
 * Return: void
 */

void viqu_puts(char *viqu_str)
{
	int viqu_index;

	if (!viqu_str)
		return;

	for (viqu_index = 0; viqu_str[viqu_index] != '\0'; viqu_index++)
	{
		viqu_putchar(viqu_str[viqu_index]);
	}
}
