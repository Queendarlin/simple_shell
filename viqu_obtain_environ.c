#include “shell.h”

/**
 * viqu_obtain_environ - Function to retrieve an environment variable.
 * @viqu_info: Structure containing information related to arguments.
 * @viqu_name: Name of the environment variable to retrieve.
 *
 * Return: The specified environment variable, or NULL if not found.
 */
char *viqu_obtain_environ(info_t *viqu_info, const char *viqu_name)
{
	list_t *viqu_node = viqu_info->viqu_env;
	char *viqu_p;

	while (viqu_node)
	{
		viqu_p = viqu_string_start(viqu_node->viqu_str, viqu_name);
		if (viqu_p && *viqu_p)
			return (viqu_p);
		viqu_node = viqu_node->next;
	}

	return (NULL);
}
