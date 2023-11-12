#include “shell.h”

/**
 * viqu_is_alpha - Checks if a character is alphabetic.
 * @viqu_char: The character to be evaluated.
 * Return: (1) if viqu_char is an alphabetic character, (0) otherwise.
 */
int viqu_is_alpha(int viqu_char)
{
	if ((viqu_char >= 'a' && viqu_char <= 'z') ||
			(viqu_char >= 'A' && viqu_char <= 'Z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

