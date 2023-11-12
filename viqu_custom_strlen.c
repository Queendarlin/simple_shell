#include "shell.h"

/**
 * viqu_custom_strlen - Function that calculates the length of a string.
 * @viqu_string: The string to measure.
 * Return: The length of the string.
 */
int viqu_custom_strlen(char *viqu_string)
{
	int viqu_index = 0;

	if (!viqu_string)
		return (0);

	while (viqu_string[viqu_index])
		viqu_index++;

	return (viqu_index);
}
