#include "shell.h"

/**
 * viqu_string_concat - Function to concatenate two strings up to a byte
 * @viqu_dest: The first string to be concatenated.
 * @viqu_src: The second string to be concatenated.
 * @viqu_num: The maximum number of bytes to be used.
 *
 * Return: A pointer to the resulting string (@viqu_dest).
 */
char *viqu_string_concat(char *viqu_dest, char *viqu_src, int viqu_num)
{
	char *viqu_result = viqu_dest;
	int viqu_index = 0, viqu_index2 = 0;

	while (viqu_dest[viqu_index] != '\0')
		viqu_index++;

	while (viqu_src[viqu_index2] != '\0' && viqu_index2 < viqu_num)
	{
		viqu_dest[viqu_index] = viqu_src[viqu_index2];
		viqu_index++;
		viqu_index2++;
	}

	if (viqu_index2 < viqu_num)
		viqu_dest[viqu_index] = '\0';

	return (viqu_result);
}
