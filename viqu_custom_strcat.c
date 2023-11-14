#include "shell.h"

/**
 * viqu_string_concat - Function to concatenate two strings up to a byte
 * @viqu_dest: The first string to be concatenated.
 * @viqu_src: The second string to be concatenated.
 *
 * Return: A pointer to the resulting string.
 */

char *viqu_custom_strcat(char *viqu_dest, char *viqu_src)
{
	char *viqu_result = viqu_dest;

	while (*viqu_dest)
		viqu_dest++;

	while (*viqu_src)
		*viqu_dest++ = *viqu_src++;
	*viqu_dest = *viqu_src;

	return (viqu_result);
}
