#include "shell.h"

/**
 * viqu_putchar_error - Function that writes a character to the stderr
 * @viqu_char: The character to be written.
 *
 * Return: 1 when successful.
 */

int viqu_putchar_error(char viqu_char)
{
	static int viqu_index;
	static char viqu_buf[VIQU_PUT_BUFFER_SIZE];

	if (viqu_char == VIQU_FLUSH_BUFFER || viqu_index >= VIQU_PUT_BUFFER_SIZE)
	{
		write(2, viqu_buf, viqu_index);
		viqu_index = 0;
	}

	if (viqu_char != VIQU_FLUSH_BUFFER)
	{
		viqu_buf[viqu_index++] = viqu_char;
	}

	return (1);
}

