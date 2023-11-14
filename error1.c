#include "shell.h"

/**
 * viqu_erratoi - converts a string to an integer
 * @viqu_ss: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 * -1 on error
 */

int viqu_erratoi(char *viqu_ss)
{
	int viqu_idx = 0;
	unsigned long int viqu_score = 0;

	if (*viqu_ss == '+')
		viqu_ss++;
	for (viqu_idx = 0;  viqu_ss[viqu_idx] != '\0'; viqu_idx++)
	{
		if (viqu_ss[viqu_idx] >= '0' && viqu_ss[viqu_idx] <= '9')
		{
			viqu_score *= 10;
			viqu_score += (viqu_ss[viqu_idx] - '0');
			if (viqu_score > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (viqu_score);
}


/**
 * viqu_print_error - prints an error message
 * @viqu_info: the parameter & return info struct
 * @viqu_estr: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 * -1 on error
 */

void viqu_print_error(info_t *viqu_info, char *viqu_estr)
{
	viqu_eputs(viqu_info->viqu_fname);
	viqu_eputs(": ");
	viqu_print_d(viqu_info->viqu_line_count, STDERR_FILENO);
	viqu_eputs(": ");
	viqu_eputs(viqu_info->viqu_argv[0]);
	viqu_eputs(": ");
	viqu_eputs(viqu_estr);
}


/**
 * viqu_print_d - function prints a decimal (integer) number (base 10)
 * @viqu_insert: the input
 * @viqu_filedes: the file descriptor to write to
 *
 * Return: number of characters printed
 */

int viqu_print_d(int viqu_insert, int viqu_filedes)
{
	int (*viqu__putchar)(char) = viqu_putchar;
	int viqu_idx, viqu_dig = 0;
	unsigned int viqu_t, viqu_current;

	if (viqu_filedes == STDERR_FILENO)
		viqu__putchar = viqu_eputchar;
	if (viqu_insert < 0)
	{
		viqu_t = -viqu_insert;
		viqu__putchar('-');
		viqu_dig++;
	}
	else
		viqu_t = viqu_insert;
	viqu_current = viqu_t;
	for (viqu_idx = 1000000000; viqu_idx > 1; viqu_idx /= 10)
	{
		if (viqu_t / viqu_idx)
		{
			viqu__putchar('0' + viqu_current / viqu_idx);
			viqu_dig++;
		}
		viqu_current %= viqu_idx;
	}
	viqu__putchar('0' + viqu_current);
	viqu_dig++;

	return (viqu_dig);
}

/**
 * viqu_convert_number - converter function, a clone of itoa
 * @viqu_num: number
 * @viqu_base: base
 * @viqu_flags: argument flags
 *
 * Return: string
 */
char *viqu_convert_number(long int viqu_num, int viqu_base, int viqu_flags)
{
	static char *viqu_array;
	static char viqu_buffer[50];
	char viqu_sign = 0;
	char *viqu_ptr;
	unsigned long viqu_n = viqu_num;

	if (!(viqu_flags & CONVERT_UNSIGNED) && viqu_num < 0)
	{
		viqu_n = -viqu_num;
		viqu_sign = '-';

	}
	viqu_array = viqu_flags & CONVERT_LOWERCASE ?
		"0123456789abcdef" : "0123456789ABCDEF";
	viqu_ptr = &viqu_buffer[49];
	*viqu_ptr = '\0';

	do {
		*--viqu_ptr = viqu_array[viqu_n % viqu_base];
		viqu_n /= viqu_base;
	} while (viqu_n != 0);

	if (viqu_sign)
		*--viqu_ptr = viqu_sign;
	return (viqu_ptr);
}

/**
 * viqu_remove_comments - function replaces first instance of '#' with '\0'
 * @viqu_adstr: address of the string to modify
 *
 * Return: Always 0;
 */
void viqu_remove_comments(char *viqu_adstr)
{
	int viqu_idx;

	for (viqu_idx = 0; viqu_adstr[viqu_idx] != '\0'; viqu_idx++)
		if (viqu_adstr[viqu_idx] == '#' &&
				(!viqu_idx || viqu_adstr[viqu_idx - 1] == ' '))
		{
			viqu_adstr[viqu_idx] = '\0';
			break;
		}
}
