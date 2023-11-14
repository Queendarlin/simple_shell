#include "shell.h"

/**
 * viqu_string_start - To check if the substring starts with a certain string
 * @viqu_hey: The string to search.
 * @viqu_n: The substring to find.
 *
 * Return: The address of the next character in viqu_haystack if viqu_n
 * starts with viqu_hey, or NULL otherwise.
 */


char *viqu_string_start(const char *viqu_hey, const char *viqu_n)
{
	while (*viqu_n)
		if (*viqu_n++ != *viqu_hey++)
			return (NULL);
	return ((char *)viqu_hey);
}
