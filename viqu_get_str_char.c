#include "shell.h"

/**
 * viqu_get_str_char - Function searches for the first occurrence of a char
 * @viqu_string: The string to check for the character.
 * @viqu_character: The character to look for in the string.
 *
 * Return: A pointer to the first occurrence of @viqu_character in
 * @viqu_string, or NULL if @viqu_character is not found.
 */
char *viqu_get_str_char(char *viqu_string, char viqu_character)
{
	do {
		if (*viqu_string == viqu_character)
			return (viqu_string);
	} while (*viqu_string++ != '\0');

	return (NULL);
}
