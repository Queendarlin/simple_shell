#include “shell.h”

/**
 * viqu_put_file_d - Write a character to the specified file descriptor.
 * @viqu_char: The character to be written.
 * @viqu_file_d: The file descriptor to write to.
 *
 * Return: 1 when succesful, or On error, returns -1
 */
int viqu_put_file_d(char viqu_char, int viqu_file_d)
{
	static int viqu_index;
	static char viqu_buffer[VIQU_PUT_BUFFER_SIZE];

	if (viqu_char == VIQU_FLUSH_BUFFER || viqu_index >= VIQU_PUT_BUFFER_SIZE)
	{
		write(viqu_file_d, viqu_buffer, viqu_index);
		viqu_index = 0;
	}

	if (viqu_char != VIQU_FLUSH_BUFFER)
	{
		viqu_buffer[viqu_index++] = viqu_char;
	}

	return (1);
}
