#include “shell.h”

/**
 * viqu_custom_strcpy - Function to copy a source string to a destination
 * @viqu_dest: Pointer to the destination string.
 * @viqu_src: Pointer to the source string.
 *
 * Return: Returns a pointer to the destination string
 */
char *viqu_custom_strcpy(char *viqu_dest, char *viqu_src)
{
	int viqu_index;

	for (viqu_index = 0; viqu_src[viqu_index] != '\0'; viqu_index++)
		viqu_dest[viqu_index] = viqu_src[viqu_index];
	viqu_dest[viqu_index] = '\0';
	return (viqu_dest);
}
