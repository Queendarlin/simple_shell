#include “shell.h”
/**
 * viqu_create_env - Function to create a new or modify environment variable.
 * @viqu_info: A structure to hold potential arguments.
 * @viqu_var: The string property of an environment variable.
 * @viqu_value: The value of the environment variable.
 * Return: 0 when successful.
 */
int viqu_create_env(info_t *viqu_info, char *viqu_var, char *viqu_value)
{
	char *viqu_buf = NULL;
	list_t *viqu_node;
	char *viqu_ptr;

	if (!viqu_var || !viqu_value)
		return (0);
	viqu_buf = malloc(viqu_custom_strlen(viqu_var) +
			viqu_custom_strlen(viqu_value) + 2);
	if (!viqu_buf)
		return (1);

	viqu_custom_strcpy(viqu_buf, viqu_var);
	viqu_custom_strcat(viqu_buf, "=");
	viqu_custom_strcat(viqu_buf, viqu_value);

	viqu_node = viqu_info->viqu_env;
	while (viqu_node)
	{
		viqu_ptr = viqu_string_start(viqu_node->viqu_str, viqu_var);
		if (viqu_ptr && *viqu_ptr == '=')
		{
			free(viqu_node->viqu_str);
			viqu_node->viqu_str = viqu_buf;
			viqu_info->viqu_env_changed = 1;
			return (0);
		}
		viqu_node = viqu_node->viqu_next;
	}

	viqu_suffix_node(&(viqu_info->viqu_env), viqu_buf, 0);
	free(viqu_buf);
	viqu_info->viqu_env_changed = 1;
	return (0);
}
