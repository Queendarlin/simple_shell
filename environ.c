#include "shell.h"

/**
 * viqu_myenv - prints the current environment
 * @viqu_info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int viqu_myenv(info_t *viqu_info)
{
	viqu_print_list_str(viqu_info->viqu_env);
	return (0);
}

/**
 * viqu_getenv - gets the value of an environ variable
 * @viqu_info: Structure containing potential arguments
 * @viqu_name: env var name
 *
 * Return: the value
 */

char *viqu_getenv(info_t *viqu_info, const char *viqu_name)
{
	list_t *viqu_node = viqu_info->viqu_env;
	char *viqu_p;

	while (viqu_node)
	{
		viqu_p = viqu_starts_with(viqu_node->viqu_str, viqu_name);
		if (viqu_p && *viqu_p)
			return (viqu_p);
		viqu_node = viqu_node->viqu_next;
	}
	return (NULL);
}



/**
 * viqu_mysetenv - Initialize a new environment variable,
 * or modify an existing one
 * @viqu_info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: 0
 */

int viqu_mysetenv(info_t *viqu_info)
{
	if (viqu_info->viqu_argc != 3)
	{
		viqu_eputs("Incorrect number of arguments\n");
		return (1);
	}
	if (viqu_setenv(viqu_info, viqu_info->viqu_argv[1],
				viqu_info->viqu_argv[2]))
		return (0);
	return (1);
}

/**
 * viqu_myunsetenv - Remove an environment variable
 * @viqu_info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */

int viqu_myunsetenv(info_t *viqu_info)
{
	int viqu_i;

	if (viqu_info->viqu_argc == 1)
	{
		viqu_eputs("Too few arguments.\n");
		return (1);
	}
	for (viqu_i = 1; viqu_i <= viqu_info->viqu_argc; viqu_i++)
		viqu_unsetenv(viqu_info, viqu_info->viqu_argv[viqu_i]);

	return (0);
}

/**
 * viqu_populate_env_list - populates env linked list
 * @viqu_info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int viqu_populate_env_list(info_t *viqu_info)
{
	list_t *viqu_node = NULL;
	size_t viqu_i;

	/* for (viqu_i = 0; environ[viqu_i]; viqu_i++) */
	for (viqu_i = 0; environ[viqu_i]; viqu_i++)
		viqu_add_node_end(&viqu_node, environ[viqu_i], 0);
	viqu_info->viqu_env = viqu_node;
	return (0);
}
