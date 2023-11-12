#include "shell.h"

/**
 * viqu_display_decimal - Functio to output a decimal in base 10.
 * @viqu_input: The input integer number.
 * @viqu_fd: The file descriptor used for output.
 *
 * Return: The count of characters printed.
 */
int viqu_display_decimal(int viqu_input, int viqu_fd)
{
	int (*viqu_putchar)(char) = viqu_putchar;
	int viqu_index, viqu_num = 0;
	unsigned int viqu_abs, viqu_current;

	if (viqu_fd == STDERR_FILENO)
		viqu_putchar = viqu_putchar_error;

	if (viqu_input < 0)
	{
		viqu_abs = -viqu_input;
		viqu_putchar('-');
		viqu_num++;
	}
	else
	{
		viqu_abs = viqu_input;
	}
	viqu_current = viqu_abs;

	for (viqu_index = 1000000000; viqu_index > 1; viqu_index /= 10)
	{
		if (viqu_abs / viqu_index)
		{
			viqu_putchar('0' + viqu_current / viqu_index);
			viqu_num++;
		}
		viqu_current %= viqu_index;
	}
	viqu_putchar('0' + viqu_current);
	viqu_num++;

	return (viqu_num);
}
