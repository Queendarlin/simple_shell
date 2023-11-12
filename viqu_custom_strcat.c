#include "shell.h"

/**
 * viqu_custom_strcat -  Function to concatenate two strings
 * @viqu_dest: The destination string.
 * @viqu_src: The source string to be append
 * Return: A pointer to the resulting concatenated string (@viqu_dest).
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
