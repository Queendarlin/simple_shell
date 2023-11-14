#include "shell.h"

/**
 * viqu_get_environ - returns the string array copy of our environ
 * @viqu_info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */

char **viqu_get_environ(info_t *viqu_info)
{
	if (!viqu_info->environ || viqu_info->viqu_env_changed)
	{
		viqu_info->environ = viqu_list_to_strings(viqu_info->viqu_env);
		viqu_info->viqu_env_changed = 0;
	}

	return (viqu_info->environ);
}



/**
 * viqu_unsetenv - Remove an environment variable
 * @viqu_info: Structure containing potential arguments
 *  Return: 1 on delete, 0 otherwise
 * @viqu_var: the string env var property
 */
int viqu_unsetenv(info_t *viqu_info, char *viqu_var)
{
	list_t *viqu_node = viqu_info->viqu_env;
	size_t viqu_i = 0;
	char *viqu_p;

	if (!viqu_node || !viqu_var)
		return (0);

	while (viqu_node)
	{
		viqu_p = viqu_starts_with(viqu_node->viqu_str, viqu_var);
		if (viqu_p && *viqu_p == '=')
		{
			viqu_info->viqu_env_changed =
				viqu_delete_node_at_index(&(viqu_info->viqu_env), viqu_i);
			viqu_i = 0;
			viqu_node = viqu_info->viqu_env;
			continue;
		}
		viqu_node = viqu_node->viqu_next;
		viqu_i++;
	}
	return (viqu_info->viqu_env_changed);
}



/**
 * viqu_setenv - Initialize a new environment variable,
 * @viqu_info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * @viqu_var: the string env var property
 * @viqu_value: the string env var value
 *  Return: Always 0
 */
int viqu_setenv(info_t *viqu_info, char *viqu_var, char *viqu_value)
{
	char *viqu_buf = NULL;
	list_t *viqu_node;
	char *viqu_p;

	if (!viqu_var || !viqu_value)
		return (0);

	viqu_buf = malloc(viqu_strlen(viqu_var) +
			viqu_strlen(viqu_value) + 2);
	if (!viqu_buf)
		return (1);
	viqu_strcpy(viqu_buf, viqu_var);
	viqu_strcat(viqu_buf, "=");
	viqu_strcat(viqu_buf, viqu_value);
	viqu_node = viqu_info->viqu_env;
	while (viqu_node)
	{
		viqu_p = viqu_starts_with(viqu_node->viqu_str, viqu_var);
		if (viqu_p && *viqu_p == '=')
		{
			free(viqu_node->viqu_str);
			viqu_node->viqu_str = viqu_buf;
			viqu_info->viqu_env_changed = 1;
			return (0);
		}
		viqu_node = viqu_node->viqu_next;
	}
	viqu_add_node_end(&(viqu_info->viqu_env), viqu_buf, 0);
	free(viqu_buf);
	viqu_info->viqu_env_changed = 1;
	return (0);
}
