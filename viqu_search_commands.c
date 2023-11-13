#include "shell.h"

/**
 * viqu_search_command - Function  to search the PATH for a command.
 * @viqu_info: The structure containing the parameter and return information.
 *
 */

void viqu_search_command(info_t *viqu_info)
{
	char *viqu_path = NULL;
	int viqu_i, viqu_k;

	viqu_info->viqu_path = viqu_info->viqu_argv[0];

	if (viqu_info->viqu_linecount_flag == 1)
	{
		viqu_info->viqu_line_count++;
		viqu_info->viqu_linecount_flag = 0;
	}
	for (viqu_i = 0, viqu_k = 0; viqu_info->viqu_arg[viqu_i]; viqu_i++)
	{
		if (!viqu_checks_delimiter(viqu_info->viqu_arg[viqu_i], " \t\n"))
			viqu_k++;
	}
	if (!viqu_k)
		return;

	viqu_path = viqu_find_cmd_path(viqu_info, viqu_obtain_environ(viqu_info, "PATH="),
			viqu_info->viqu_argv[0]);
	if (viqu_path)
	{
		viqu_info->viqu_path = viqu_path;
		viqu_exec_fork_command(viqu_info);
	}
	else
	{
		if ((viqu_interactive_mode(viqu_info) ||
					viqu_obtain_environ(viqu_info, "PATH=") ||
					viqu_info->viqu_argv[0][0] == '/') &&
				viqu_determine_exe_cmd(viqu_info, viqu_info->viqu_argv[0]))
			viqu_exec_fork_command(viqu_info);
		else if (*(viqu_info->viqu_arg) != '\n')
		{
			viqu_info->viqu_status = 127;
			viqu_display_error(viqu_info, "not found\n");
		}
	}
}
