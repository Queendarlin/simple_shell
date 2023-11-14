#include "shell.h"

/**
 * viqu_hsh - For shell looping
 * @viqu_info: The argument structure
 * @viqu_av: The argument for the function
 *
 * Return: 0 when successful, 1 if error.
 */
int viqu_hsh(info_t *viqu_info, char **viqu_av)
{
	ssize_t viqu_r = 0;
	int viqu_builtin_ret = 0;

	while (viqu_r != -1 && viqu_builtin_ret != -2)
	{
		viqu_clear_info(viqu_info);

		if (viqu_interactive(viqu_info))
			viqu_puts("$ ");

		viqu_eputchar(BUF_FLUSH);
		viqu_r = viqu_get_input(viqu_info);
		if (viqu_r != -1)
		{
			viqu_set_info(viqu_info, viqu_av);
			viqu_builtin_ret = viqu_find_builtin(viqu_info);

			if (viqu_builtin_ret == -1)
				viqu_find_cmd(viqu_info);
		}
		else if (viqu_interactive(viqu_info))
			viqu_putchar('\n');

		viqu_free_info(viqu_info, 0);
	}
	viqu_write_history(viqu_info);
	viqu_free_info(viqu_info, 1);

	if (!viqu_interactive(viqu_info) && viqu_info->viqu_status)
		exit(viqu_info->viqu_status);

	if (viqu_builtin_ret == -2)
	{
		if (viqu_info->viqu_err_num == -1)
			exit(viqu_info->viqu_status);

		exit(viqu_info->viqu_err_num);
	}
	return (viqu_builtin_ret);
}


/**
 * viqu_find_builtin - Function to search for commands.
 * @viqu_info: The parameter structure
 *
 * Return: -1, 0, 1 or 2
 */
int viqu_find_builtin(info_t *viqu_info)
{
	int viqu_i, viqu_builtin_ret = -1;

	viqu_builtin_table viqu_builtintbl[] = {
		{"exit", viqu_myexit},
		{"env", viqu_myenv},
		{"help", viqu_myhelp},
		{"history", viqu_myhistory},
		{"setenv", viqu_mysetenv},
		{"unsetenv", viqu_myunsetenv},
		{"cd", viqu_mycd},
		{"alias", viqu_myalias},
		{NULL, NULL}
	};

	for (viqu_i = 0; viqu_builtintbl[viqu_i].viqu_type; viqu_i++)
	{
		if (viqu_strcmp(viqu_info->viqu_argv[0],
					viqu_builtintbl[viqu_i].viqu_type) == 0)
		{
			viqu_info->viqu_line_count++;
			viqu_builtin_ret = viqu_builtintbl[viqu_i].viqu_func(viqu_info);
			break;
		}
	}

	return (viqu_builtin_ret);
}


/**
 * viqu_find_cmd - Function to search for commands in PATH.
 * @viqu_info: The parameter structure
 */
void viqu_find_cmd(info_t *viqu_info)
{
	char *viqu_the_path = NULL;
	int viqu_i, viqu_k;

	viqu_info->viqu_path = viqu_info->viqu_argv[0];

	if (viqu_info->viqu_linecount_flag == 1)
	{
		viqu_info->viqu_line_count++;
		viqu_info->viqu_linecount_flag = 0;
	}
	for (viqu_i = 0, viqu_k = 0; viqu_info->viqu_arg[viqu_i]; viqu_i++)
		if (!viqu_is_delim(viqu_info->viqu_arg[viqu_i], " \t\n"))
			viqu_k++;
	if (!viqu_k)
		return;
	viqu_the_path = viqu_find_path(viqu_info,
			viqu_getenv(viqu_info, "PATH="), viqu_info->viqu_argv[0]);
	if (viqu_the_path)
	{
		viqu_info->viqu_path = viqu_the_path;
		viqu_fork_cmd(viqu_info);
	}
	else
	{
		if ((viqu_interactive(viqu_info) || viqu_getenv(viqu_info, "PATH=") ||
					viqu_info->viqu_argv[0][0] == '/') &&
				viqu_is_cmd(viqu_info, viqu_info->viqu_argv[0]))
		{
			viqu_fork_cmd(viqu_info);
		}
		else if (*(viqu_info->viqu_arg) != '\n')
		{
			viqu_info->viqu_status = 127;
			viqu_print_error(viqu_info, "not found\n");
		}
	}
}

/**
 * viqu_fork_cmd - Function to execute child processes for commands
 * @viqu_info: The parameter structure
 */
void viqu_fork_cmd(info_t *viqu_info)
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
					viqu_get_environ(viqu_info)) == -1)
		{
			viqu_free_info(viqu_info, 1);

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
				viqu_print_error(viqu_info, "Permission denied\n");
		}
	}
}
