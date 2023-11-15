#include "shell.h"

/**
 * viqu_string_concat - Function to join two strings together
 * @viqu_dest: first string to the joined
 * @viqu_src: second string to join to the first
 * @viqu_n: volume of bytes to be maximally used
 *
 * Return: viqu_dest
 */

char *viqu_string_concat(char *viqu_dest, char *viqu_src, int viqu_n)
{
	int viqu_i, viqu_t;
	char *viqu_s = viqu_dest;

	viqu_i = 0;
	viqu_t = 0;
	while (viqu_dest[viqu_i] != '\0')
		viqu_i++;
	while (viqu_src[viqu_t] != '\0' && viqu_t < viqu_n)
	{
		viqu_dest[viqu_i] = viqu_src[viqu_t];
		viqu_i++;
		viqu_t++;
	}
	if (viqu_t < viqu_n)
		viqu_dest[viqu_i] = '\0';
	return (viqu_s);
}
