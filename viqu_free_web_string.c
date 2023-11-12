#include "shell.h"

/**
 * viqu_free_web_string - Function to free a web of strings.
 * @viqu_str_free: The web of strings to be freed.
 * Return: ..
 */

void viqu_free_web_string(char **viqu_str_free)
{
	char **viqu_a = viqu_str_free;

	if (!viqu_str_free)
		return;
	while (*viqu_str_free)
		free(*viqu_str_free++);

	free(viqu_a);
}
