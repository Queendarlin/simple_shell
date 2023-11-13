#include "shell.h"

/**
 * viqu_string_start - To check if the substring starts with a certain string
 * @viqu_haystack: The string to search.
 * @viqu_needle: The substring to find.
 *
 * Return: The address of the next character in viqu_haystack if viqu_needle
 * starts with viqu_haystack, or NULL otherwise.
 */

char *viqu_string_start(const char *viqu_haystack, const char *viqu_needle)
{
	while (*viqu_needle)
		if (*viqu_needle++ != *viqu_haystack++)
			return (NULL);
	return ((char *)viqu_haystack);
}
