#include "shell.h"

/**
 * viqu_modify_environ_var - Function to Initialize or modify environment var
 * @viqu_info: Pointer to a structure containing arguments.
 *
 * Return: 0 when successful, 1 if there's an incorrect number of arguments.
 */
int viqu_modify_environ_var(info_t *viqu_info)
{
	if (viqu_info->viqu_argc != 3)
	{
		viqu_puts_error("wrong arguments!\n");
		return (1);
	}

	if (viqu_create_env(viqu_info,
				viqu_info->viqu_argv[1], viqu_info->viqu_argv[2]))
		return (0);

	return (1);
}

