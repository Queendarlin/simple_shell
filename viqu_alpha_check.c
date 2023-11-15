#include "shell.h"

/**
 * viqu_alpha_check - Function to check if a character is an alphabetic letter.
 *
 * @viqu_letter: The character to be checked.
 *
 * Return: 1 if @viqu_letter is an alphabetic letter, 0 otherwise.
 */

int viqu_alpha_check(int viqu_letter)
{
	if ((viqu_letter >= 'a' && viqu_letter <= 'z') ||
			(viqu_letter >= 'A' && viqu_letter <= 'Z'))
		return (1);
	else
		return (0);
}
