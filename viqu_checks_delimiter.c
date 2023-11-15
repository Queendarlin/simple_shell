#include "shell.h"

/**
 * viqu_checks_delimiter - Function to verify if a character is a delimiter.
 * @viqu_c: The character to be checked.
 * @viqu_delim: The string containing delimiters.
 *
 * Return: (1) if the character is a delimiter, otherwise (0).
 */

int viqu_checks_delimiter(char viqu_c, char *viqu_delim)
{
	while (*viqu_delim)
	{
		if (*viqu_delim++ == viqu_c)
		{
			return (1);
		}
	}
	return (0);
}
