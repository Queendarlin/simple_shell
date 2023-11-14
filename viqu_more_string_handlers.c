#include "shell.h"

/**
 * viqu_strlen - Function to determine a string length
 * @viqu_s: The string the length will be determined
 *
 * Return: Result of the string’s length
 */
int viqu_strlen(char *viqu_s)
{
	int viqu_i = 0;

	if (!viqu_s)
		return (0);

	while (*viqu_s++)
		viqu_i++;

	return (viqu_i);
}


/**
 * viqu_strcmp - Function for comparing two strings
 * @viqu_s1: One of the string to compare
 * @viqu_s2: Another string to compare
 *
 * Return: When s1 is greater than s2, negative if less positive
 * and 0 if equal.
 */
int viqu_strcmp(char *viqu_s1, char *viqu_s2)
{
	while (*viqu_s1 && *viqu_s2)
	{
		if (*viqu_s1 != *viqu_s2)
			return (*viqu_s1 - *viqu_s2);
		viqu_s1++;
		viqu_s2++;
	}

	if (*viqu_s1 == *viqu_s2)
		return (0);
	else
		return (*viqu_s1 < *viqu_s2 ? -1 : 1);
}

/**
 * viqu_starts_with - Function to check if a string starts with another
 * @viqu_main: String to search.
 * @viqu_search: The string after
 *
 * Return: viqu_main
 */
char *viqu_starts_with(const char *viqu_main, const char *viqu_search)
{
	while (*viqu_search)
		if (*viqu_search++ != *viqu_main++)
			return (NULL);
	return ((char *)viqu_main);
}


/**
 * viqu_strcat - Function to join two strings.
 * @viqu_dest: String to receive the other string for joining.
 * @viqu_src: The string that will be joined
 *
 * Return: The recipient
 */
char *viqu_strcat(char *viqu_dest, char *viqu_src)
{
	char *viqu_ret = viqu_dest;

	while (*viqu_dest)
		viqu_dest++;

	while (*viqu_src)
		*viqu_dest++ = *viqu_src++;

	*viqu_dest = *viqu_src;

	return (viqu_ret);
}
