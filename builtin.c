#include "shell.h"
/**
 * viqu_myexit - exits the shell
 * @viqu_info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: exits with a given exit status
 * (0) if viqu_info.viqu_argv[0] != "exit"
 */
int viqu_myexit(info_t *viqu_info)
{
	int viqu_exitcheck;

	if (viqu_info->viqu_argv[1])          	{
		viqu_exitcheck =viqu_erratoi(viqu_info->viqu_argv[1]);
		if (viqu_exitcheck == -1)
		{
			viqu_info->viqu_status = 2;
			viqu_print_error(viqu_info, "Illegal number: ");
			viqu_eputs(viqu_info->viqu_argv[1]);
			viqu_eputchar('\n');
			return (1);
		}
		viqu_info->viqu_err_num =viqu_erratoi(viqu_info->viqu_argv[1]);
		return (-2);
	}
	viqu_info->viqu_err_num = -1;
	return (-2);
}

#include "shell.h"

/**
 * viqu_mycd - changes the current directory of the process
 * @viqu_info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int viqu_mycd(info_t *viqu_info)
{
	char *viqu_s, *viqu_dir, viqu_buffer[1024];
	int viqu_chdir_ret;

	viqu_s = getcwd(viqu_buffer, 1024);
	if (!viqu_s)
		viqu_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!viqu_info->viqu_argv[1])
	{
		viqu_dir = viqu_getenv(viqu_info, "HOME=");
		if (!viqu_dir)
			viqu_chdir_ret = /* TODO: what should this be? */
				viqu_chdir((viqu_dir = viqu_getenv(viqu_info, "PWD=")) ? viqu_dir : "/");
		else
			viqu_chdir_ret = viqu_chdir(viqu_dir);
	}
	else if (_strcmp(viqu_info->viqu_argv[1], "-") == 0)
	{
		if (!viqu_getenv(viqu_info, "OLDPWD="))
		{
			viqu_puts(viqu_s);
			viqu_putchar('\n');
			return (1);
		}
		viqu_puts(viqu_getenv(viqu_info, "OLDPWD=")), viqu_putchar('\n');
		viqu_chdir_ret = /* TODO: what should this be? */
			viqu_chdir((viqu_dir = viqu_getenv(viqu_info, "OLDPWD=")) ? viqu_dir : "/");
	}
	else
		viqu_chdir_ret = viqu_chdir(viqu_info->viqu_argv[1]);
	if (viqu_chdir_ret == -1)
	{
		print_error(viqu_info, "can't cd to ");
		_eputs(viqu_info->viqu_argv[1]), _eputchar('\n');
	}
	else
	{
		viqu_setenv(viqu_info, "OLDPWD", viqu_getenv(viqu_info, "PWD="));
		viqu_setenv(viqu_info, "PWD", getcwd(viqu_buffer, 1024));
	}
	return (0);
}


#include "shell.h"

/**
 * viqu_myhelp - changes the current directory of the process
 * @viqu_info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int viqu_myhelp(info_t *viqu_info)
{
	char **viqu_arg_array;

	viqu_arg_array = viqu_info->viqu_argv;
	viqu_puts("help call works. Function not yet implemented \n");
	if (0)
		viqu_puts(*viqu_arg_array);
	return (0);
}
