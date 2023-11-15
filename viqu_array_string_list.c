#include "shell.h"

/**
 * viqu_array_string_list - Function to return an array of strings from the
 * list nodes.
 * @viqu_head: The pointer to the initial node in the linked list.
 *
 * Return: The complete array of strings.
 */

char **viqu_array_string_list(list_t *viqu_head)
{
	list_t *viqu_node = viqu_head;
	size_t viqu_i = viqu_length_of_list(viqu_head), viqu_j;
	char **viqu_strs;
	char *viqu_str;

	if (!viqu_head || !viqu_i)
		return (NULL);

	viqu_strs = malloc(sizeof(char *) * (viqu_i + 1));
	if (!viqu_strs)
		return (NULL);

	for (viqu_i = 0; viqu_node; viqu_node = viqu_node->viqu_next,
			viqu_i++)
	{
		viqu_str = malloc(viqu_custom_strlen(viqu_node->viqu_str) + 1);
		if (!viqu_str)
		{
			for (viqu_j = 0; viqu_j < viqu_i; viqu_j++)
				free(viqu_strs[viqu_j]);
			free(viqu_strs);
			return (NULL);
		}

		viqu_str = viqu_custom_strcpy(viqu_str, viqu_node->viqu_str);

		viqu_strs[viqu_i] = viqu_str;
	}
	viqu_strs[viqu_i] = NULL;

	return (viqu_strs);
}
