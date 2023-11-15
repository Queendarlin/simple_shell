#include "shell.h"

/**
 * viqu_custom_strdup - Function to create a duplicate of a given string.
 * @viqu_str: Pointer to the string to be duplicated.
 *
 * Return: A pointer to the duplicated string. Returns NULL if @viqu_str is
 * NULL or if memory allocation fails.
 *
 */
char *viqu_custom_strdup(const char *viqu_str)
{
	int viqu_length = 0;
	char *viqu_ret;

	if (viqu_str == NULL)
		return (NULL);
	while (*viqu_str++)
		viqu_length++;
	viqu_ret = malloc(sizeof(char) * (viqu_length + 1));
	if (!viqu_ret)
		return (NULL);
	for (viqu_length++; viqu_length--;)
		viqu_ret[viqu_length] = *--viqu_str;
	return (viqu_ret);
}
