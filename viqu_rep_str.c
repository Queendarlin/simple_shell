#include "shell.h"

/**
 * viqu_rep_str - Function that replaces a string with a new value.
 * @viqu_old: Address of the original string.
 * @viqu_new: Pointer to the new string.
 *
 * This function frees the memory occupied by the original string and updates
 * it with the new string.
 *
 * Return: 1 if the string is successfully replaced, 0 otherwise.
 */

int viqu_rep_str(char **viqu_old, char *viqu_new)
{
	free(*viqu_old);

	*viqu_old = viqu_new;

	return (1);
}
