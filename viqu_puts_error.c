#include "shell.h"

/**
 * viqu_puts_error - Function to print the input string to the stdout
 * @viqu_string: The string to be printed.
 */

void viqu_puts_error(char *viqu_string)
{
	int viqu_index = 0;

	if (!viqu_string)
		return;

	while (viqu_string[viqu_index] != '\0')
	{
		viqu_putchar_error(viqu_string[viqu_index]);
		viqu_index++;
	}
}

