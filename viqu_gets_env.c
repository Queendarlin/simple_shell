#include “shell.h”

/**
 * viqu_gets_env - Function to return the string array copy of our environment
 * @viqu_info: Sructure to hold potential arguments.
 * Return: The string array of the environment.
 */
char **viqu_gets_env(info_t *viqu_info)
{
	if (!viqu_info->viqu_environ || viqu_info->viqu_env_changed)
	{
		viqu_info->viqu_environ = viqu_array_string_list(viqu_info->viqu_env);
		viqu_info->viqu_env_changed = 0;
	}

	return (viqu_info->viqu_environ);
}
