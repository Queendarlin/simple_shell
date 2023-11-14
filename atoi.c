#include "shell.h"

/**
 *viqu_atoi - converts a string to an integer
 * @viqu_s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int viqu_atoi(char *viqu_s)
{
	int viqu_i, viqu_sign = 1, flag = 0, viqu_output;
	unsigned int viqu_result = 0;

	for (viqu_i = 0; viqu_s[viqu_i] != '\0' && flag != 2; viqu_i++)
	{
		if (viqu_s[viqu_i] == '-')
			viqu_sign *= -1;

		if (viqu_s[viqu_i] >= '0' && viqu_s[viqu_i] <= '9')
		{
			flag = 1;
			viqu_result *= 10;
			viqu_result += (viqu_s[viqu_i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}
	if (viqu_sign == -1)
		viqu_output = -viqu_result;
	else
		viqu_output = viqu_result;

	return (viqu_output);
}

#include "shell.h"

/**
 * viqu_isalpha - checks for alphabetic character
 * @viqu_c: The character to input
 * Return: 1 if viqu_c is alphabetic, 0 otherwise
 */

int viqu_isalpha(int viqu_c)
{
	if ((viqu_c >= 'a' && viqu_c <= 'z') || (viqu_c >= 'A' && viqu_c <= 'Z'))
		return (1);
	else
		return (0);
}


#include "shell.h"

/**
 * viqu_is_delim - checks if character is a delimeter
 * @viqu_c: the char to check
 * @viqu_delim: the delimeter string
 * Return: 1 if true, 0 if false
 */

int viqu_is_delim(char viqu_c, char *viqu_delim)
{
	while (*viqu_delim)
		if (*viqu_delim++ == viqu_c)
			return (1);
	return (0);
}


#include "shell.h"

/**
 * viqu_interactive - returns true if shell is interactive mode
 * @viqu_info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int viqu_interactive(info_t *viqu_info)
{
	return (isatty(STDIN_FILENO) && viqu_info->viqu_readfd <= 2);
}
