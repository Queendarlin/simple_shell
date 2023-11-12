#include "shell.h"

/**
 * viqu_rep_alias - Replaces an alias in the tokenized string.
 * @viqu_info: Pointer to the structure containing shell information.
 *
 * Return: 1 if replaced, 0 otherwise.
 */

int viqu_rep_alias(info_t *viqu_info)
{
	int viqu_index;
	list_t *viqu_node;
	char *viqu_p;

	for (viqu_index = 0; viqu_index < 10; viqu_index++)
	{
		viqu_node = viqu_prefix_node(viqu_info->viqu_alias,
				viqu_info->viqu_argv[0], '=');
		if (!viqu_node)
			return (0);

		free(viqu_info->viqu_argv[0]);

		viqu_p = viqu_get_str_char(viqu_node->viqu_str, '=');
		if (!viqu_p)
			return (0);
		viqu_p = viqu_custom_strdup(viqu_p + 1);
		if (!viqu_p)
			return (0);

		viqu_info->viqu_argv[0] = viqu_p;
	}
	return (1);
}
