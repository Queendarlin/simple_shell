#include "shell.h"

/**
 * viqu_exec_fork_command - Function to execute
 * command via forking an exec thread.
 * @viqu_info: The structure parameter and return information.
 *
 */

void viqu_exec_fork_command(info_t *viqu_info)
{
	pid_t viqu_child_pid;

	viqu_child_pid = fork();
	if (viqu_child_pid == -1)
	{
		perror("Error:");
		return;
	}

	if (viqu_child_pid == 0)
	{
		if (execve(viqu_info->viqu_path, viqu_info->viqu_argv,
					viqu_gets_env(viqu_info)) == -1)
		{
			viqu_free_list_field(viqu_info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(viqu_info->viqu_status));
		if (WIFEXITED(viqu_info->viqu_status))
		{
			viqu_info->viqu_status = WEXITSTATUS(viqu_info->viqu_status);
			if (viqu_info->viqu_status == 126)
				viqu_display_error(viqu_info, "No Permission\n");
		}
	}
}
