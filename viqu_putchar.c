#include “shell.h”

/**
 * viqu_putchar - Writes the character viqu_c to stdout
 * @viqu_c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int viqu_putchar(char viqu_c)
{
	static int viqu_index;
	static char viqu_buf[VIQU_PUT_BUFFER_SIZE];

	if (viqu_c == VIQU_FLUSH_BUFFER || viqu_index >= VIQU_PUT_BUFFER_SIZE)
	{
		write(1, viqu_buf, viqu_index);
		viqu_index = 0;
	}

	if (viqu_c != VIQU_FLUSH_BUFFER)
		viqu_buf[viqu_index++] = viqu_c;

	return (1);
}
