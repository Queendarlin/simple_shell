#include "shell.h"

/**
 * viqu_find_cmd_builtin - The function to find
 * a corresponding built-in command.
 * @viqu_info: The structure containing the parameter and return information.
 *
 * Return: -1, 0, 1 or 2
 */

int viqu_find_cmd_builtin(info_t *viqu_info)
{
	int viqu_index, viqu_builtin_ret = -1;

	viqu_built_in_table viqu_builtintbl[] = {
		{"exit", viqu_exit_control},
		{"env", viqu_current_environ},
		{"help", viqu_help_function},
		{"history", viqu_display_command_hist},
		{"setenv", viqu_modify_environ_var},
		{"unsetenv", viqu_remove_environ_var},
		{"cd", viqu_change_directory},
		{"alias", viqu_custom_alias},
		{NULL, NULL}
	};

	for (viqu_index = 0; viqu_builtintbl[viqu_index].viqu_type; viqu_index++)
	{
		if (viqu_custom_strcmp(viqu_info->viqu_argv[0],
					viqu_builtintbl[viqu_index].viqu_type) == 0)
		{
			viqu_info->viqu_line_count++;
			viqu_builtin_ret = viqu_builtintbl[viqu_i].viqu_func(viqu_info);
			break;
		}
	}

	return (viqu_builtin_ret);
}
