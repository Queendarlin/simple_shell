#include "shell.h"

/**
 * viqu_custom_strcmp - This function compares two strings
 * @viqu_string1: One of the string to compare
 * @viqu_string2: The other string to compare
 *
 * Return: Returns a negative value if viqu_s1 is less than viqu_s2,
 * a positive value if viqu_s1 is greater than viqu_s2, and 0 if both
 * strings are equal.
 */
int viqu_custom_strcmp(char *viqu_string1, char *viqu_string2)
{
	while (*viqu_string1 && *viqu_string2)
	{
		if (*viqu_string1 != *viqu_string2)
			return (*viqu_string1 - *viqu_string2);

		viqu_string1++;
		viqu_string2++;
	}

	if (*viqu_string1 == *viqu_string2)
		return (0);
	else
		return (*viqu_string1 < *viqu_string2 ? -1 : 1);
}
