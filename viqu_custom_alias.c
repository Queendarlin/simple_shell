#include "shell.h"

/**
 * viqu_custom_alias - Function to emulate the behavior of the alias command.
 * @viqu_info: Structure containing potential arguments
 *
 * Return: Return 0 when successful.
 */
int viqu_custom_alias(info_t *viqu_info)
{
	int viqu_index = 0;
	char *viqu_ptr = NULL;
	list_t *viqu_current_node = NULL;

	if (viqu_info->viqu_argc == 1)
	{
		viqu_current_node = viqu_info->viqu_alias;
		while (viqu_current_node)
		{
			viqu_print_alias(viqu_current_node);
			viqu_current_node = viqu_current_node->next;
		}
		return (0);
	}
	for (viqu_index = 1; viqu_info->viqu_argv[viqu_index]; viqu_index++)
	{
		viqu_ptr = viqu_get_str_char(viqu_info->viqu_argv[viqu_index], '=');
		if (viqu_ptr)
			viqu_set_alias(viqu_info, viqu_info->viqu_argv[viqu_index]);
		else
			viqu_print_alias(viqu_prefix_node(viqu_info->viqu_alias,
						viqu_info->viqu_argv[viqu_index], '='));
	}

	return (0);
}
