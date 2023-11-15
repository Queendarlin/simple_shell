#include "shell.h"

/**
 * viqu_remove_environ_var - Remove specified environment variable(s).
 * @viqu_info: Structure containing information related to arguments.
 *
 * Return: 0 when successfully executed, 1 if there are too few arguments.
 */

int viqu_remove_environ_var(info_t *viqu_info)
{
	int viqu_index;

	if (viqu_info->viqu_argc == 1)
	{
		viqu_puts_error("Limited number parameters.\n");
		return (1);
	}

	for (viqu_index = 1; viqu_index < viqu_info->viqu_argc; viqu_index++)
	{
		viqu_delete_env(viqu_info, viqu_info->viqu_argv[viqu_index]);
	}

	return (0);
}
