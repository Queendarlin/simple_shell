#include "shell.h"

/**
 * viqu_puts_file_d - Function to write input string to the file descriptor.
 * @viqu_string: The string to be written.
 * @viqu_file_des: The file descriptor to write to.
 *
 * Return: The number of characters written.
 */
int viqu_puts_file_d(char *viqu_string, int viqu_file_des)
{
	int viqu_index = 0;

	if (!viqu_string)
		return (0);

	while (*viqu_string)
	{
		viqu_index += viqu_put_file_d(*viqu_string++, viqu_file_des);
	}

	return (viqu_index);
}
