#include "shell.h"

/**
 * viqu_delete_env - Function to remove an environment variable
 * @viqu_info: A structure hold potential arguments.
 * @viqu_var: The string property of an environment variable to be removed.
 * Return: 1 when successful, and 0 when it fails.
 */

int viqu_delete_env(info_t *viqu_info, char *viqu_var)
{
	list_t *viqu_node = viqu_info->viqu_env;
	size_t viqu_idx = 0;
	char *viqu_ptr;

	if (!viqu_node || !viqu_var)
		return (0);

	while (viqu_node)
	{
		viqu_ptr = viqu_string_start(viqu_node->viqu_str, viqu_var);
		if (viqu_ptr && *viqu_ptr == '=')
		{
			viqu_info->viqu_env_changed =
				viqu_del_node_idx(&(viqu_info->viqu_env), viqu_idx);
			viqu_idx = 0;
			viqu_node = viqu_info->viqu_env;
			continue;
		}
		viqu_node = viqu_node->viqu_next;
		viqu_idx++;
	}

	return (viqu_info->viqu_env_changed);
}
