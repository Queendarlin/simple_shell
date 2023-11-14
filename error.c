#include "shell.h"

/**
 * viqu_eputs - prints an input string
 * @viqu_str: the string to be printed
 *
 * Return: Nothing
 */
void viqu_eputs(char *viqu_str)
{
	int viqu_i = 0;

	if (!viqu_str)
		return;
	while (viqu_str[viqu_i] != '\0')
	{
		viqu_eputchar(viqu_str[viqu_i]);
		viqu_i++;
	}
}

/**
 * viqu_eputchar - writes the character c to stderr
 * @viqu_c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int viqu_eputchar(char viqu_c)
{
	static int viqu_i;
	static char viqu_buf[WRITE_BUF_SIZE];

	if (viqu_c == BUF_FLUSH || viqu_i >= WRITE_BUF_SIZE)
	{
		write(2, viqu_buf, viqu_i);
		viqu_i = 0;
	}
	if (viqu_c != BUF_FLUSH)
		viqu_buf[viqu_i++] = viqu_c;
	return (1);
}

/**
 * viqu_putfd - writes the character c to given fd
 * @viqu_c: The character to print
 * @viqu_fd: The file descriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int viqu_putfd(char viqu_c, int viqu_fd)
{
	static int viqu_i;
	static char viqu_buf[WRITE_BUF_SIZE];

	if (viqu_c == BUF_FLUSH || viqu_i >= WRITE_BUF_SIZE)
	{
		write(viqu_fd, viqu_buf, viqu_i);
		viqu_i = 0;
	}
	if (viqu_c != BUF_FLUSH)
		viqu_buf[viqu_i++] = viqu_c;
	return (1);
}


/**
 * viqu_putsfd - prints an input string
 * @viqu_str: the string to be printed
 * @viqu_fd: the file descriptor to write to
 *
 * Return: the number of chars put
 */

int viqu_putsfd(char *viqu_str, int viqu_fd)
{
	int viqu_i = 0;

	if (!viqu_str)
		return (0);
	while (*viqu_str)
	{
		viqu_i += viqu_putfd(*viqu_str++, viqu_fd);
	}
	return (viqu_i);
}
