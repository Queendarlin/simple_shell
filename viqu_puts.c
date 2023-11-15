#include "shell.h"

/**
 * viqu_puts - Function to print a string to the standard output.
 * @viqu_str: Pointer to the string to be printed.
 *
 */

void viqu_puts(char *viqu_str)
{
	int viqu_index = 0;

	if (!viqu_str)
		return;

	while (viqu_str[viqu_index] != '\0')
	{
		viqu_putchar(viqu_str[viqu_index]);
		viqu_index++;
	}
}
