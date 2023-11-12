#include "shell.h"

/**
 * viqu_rep_variables - Performs variable substitution within the
 * tokenized string.
 * @viqu_info: Pointer to the structure containing shell information.
 *
 * Return: 1 if replacements were successfully made; otherwise, returns 0.
 */
int viqu_rep_variables(info_t *viqu_info)
{
	int viqu_index = 0;
	list_t *viqu_node;

	for (viqu_index = 0; viqu_info->viqu_argv[viqu_index]; viqu_index++)
	{
		if (viqu_info->viqu_argv[viqu_index][0] != '$' ||
				!viqu_info->viqu_argv[viqu_index][1])
			continue;
		if (!viqu_custom_strcmp(viqu_info->viqu_argv[viqu_index], "$?"))
		{
			viqu_rep_str(&(viqu_info->viqu_argv[viqu_index]),
					viqu_custom_strdup(viqu_int_to_string(viqu_info->viqu_status, 10, 0)));
			continue;
		}
		if (!viqu_custom_strcmp(viqu_info->viqu_argv[viqu_index], "$$"))
		{
			viqu_rep_str(&(viqu_info->viqu_argv[viqu_index]),
					viqu_custom_strdup(viqu_int_to_string(viqu_getpid(), 10, 0)));
			continue;
		}
		viqu_node = viqu_prefix_node
			(viqu_info->viqu_env, &(viqu_info->viqu_argv[viqu_index][1]), '=');
		if (viqu_node)
		{
			viqu_rep_str(&(viqu_info->viqu_argv[viqu_index]),
					viqu_custom_strdup(viqu_get_str_char(viqu_node->viqu_str, '=') + 1));
			continue;
		}
		viqu_rep_str(&(viqu_info->viqu_argv[viqu_index]), viqu_custom_strdup(""));
	}
	return (0);
}
