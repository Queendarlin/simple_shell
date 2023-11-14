#include "shell.h"

/**
 * viqu_strcpy - Function to copy a string.
 * @viqu_dest: The string to receive the copy.
 * @viqu_src: The string to copy.
 *
 * Return: The result of dest.
 */
char *viqu_strcpy(char *viqu_dest, char *viqu_src)
{
	int viqu_i = 0;

	if (viqu_dest == viqu_src || viqu_src == 0)
		return (viqu_dest);

	while (viqu_src[viqu_i])
	{
		viqu_dest[viqu_i] = viqu_src[viqu_i];
		viqu_i++;
	}
	viqu_dest[viqu_i] = 0;

	return (viqu_dest);
}


/**
 * viqu_strdup - Function to make a string double.
 * @viqu_str: The string to double.
 *
 * Return: The doubled string
 */
char *viqu_strdup(const char *viqu_str)
{
	int viqu_length = 0;
	char *viqu_ret;

	if (viqu_str == NULL)
		return (NULL);

	while (*viqu_str++)
		viqu_length++;

	viqu_ret = malloc(sizeof(char) * (viqu_length + 1));

	if (!viqu_ret)
		return (NULL);

	for (viqu_length++; viqu_length--;)
		viqu_ret[viqu_length] = *--viqu_str;

	return (viqu_ret);
}

/**
 * viqu_puts - Function for printing string.
 * @viqu_str: String for printing
 *
 */
void viqu_puts(char *viqu_str)
{
	int viqu_i = 0;

	if (!viqu_str)
		return;

	while (viqu_str[viqu_i] != '\0')
	{
		viqu_putchar(viqu_str[viqu_i]);
		viqu_i++;
	}
}


/**
 * viqu_putchar - Function for writing characters
 * @viqu_c: The character that needs to be written
 *
 * Return: 1 when successful. -1 if error occured
 */
int viqu_putchar(char viqu_c)
{
	static int viqu_i;
	static char viqu_buf[WRITE_BUF_SIZE];

	if (viqu_c == BUF_FLUSH || viqu_i >= WRITE_BUF_SIZE)
	{
		write(1, viqu_buf, viqu_i);
		viqu_i = 0;
	}

	if (viqu_c != BUF_FLUSH)
		viqu_buf[viqu_i++] = viqu_c;

	return (1);
}
