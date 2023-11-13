#include "shell.h"

/**
 * viqu_string_concat - Function to concatenate two strings up to a byte
 * @viqu_dest: The first string to be concatenated.
 * @viqu_src: The second string to be concatenated.
 * @viqu_num: The maximum number of bytes to be used.
 *
 * Return: A pointer to the resulting string (@viqu_dest).
 */

char *viqu_string_concat(char *viqu_dest, char *viqu_src)
{
	char *viqu_result = viqu_dest;

	while (*viqu_dest)
		viqu_dest++;

	while (*viqu_src)
		*viqu_dest++ = *viqu_src++;
	*viqu_dest = *viqu_src;

	return (viqu_result);
}
