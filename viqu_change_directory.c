#include “shell.h”

/**
 * viqu_change_directory - Function for changing the current directory
 * @g: A structured set of potential arguments
 * Return: Returns 0 when successful.
 */
int viqu_change_directory(info_t *g)
{
	char *viqu_s, *viqu_d, viqu_buffer[1024];
	int viqu_r;

	viqu_s = getcwd(viqu_buffer, 1024);
	if (!viqu_s)
		viqu_puts("TODO: >>Handle getcwd failure for an error message here<<\n");
	if (!g->viqu_argv[1])
	{
		viqu_d = viqu_obtain_environ(g, "HOME=");
		if (!viqu_d)
			viqu_r = chdir((viqu_d = viqu_obtain_environ(g, "PWD=")) ? viqu_d : "/");
		viqu_r = chdir(viqu_d);
	}
	else if (viqu_custom_strcmp(g->viqu_argv[1], "-") == 0)
	{
		if (!viqu_obtain_environ(g, "OLDPWD="))
		{
			viqu_puts(viqu_s);
			viqu_putchar('\n');
			return (1);
		}
		viqu_puts(_viqu_obtain_environ(g, "OLDPWD="));
		viqu_putchar('\n');
		viqu_r = chdir((viqu_d = viqu_obtain_environ(g, "OLDPWD=")) ? viqu_d : "/");
	}
	else
		viqu_r = chdir(g->viqu_argv[1]);
	if (viqu_r  == -1)
	{
		viqu_display_error(g, "can't cd to ");
		viqu_puts_error(g->viqu_argv[1]);
		viqu_putchar_error('\n');
	}
	else
	{
		viqu_create_env(g, "OLDPWD",
				viqu_obtain_environ(g, "PWD="));
		viqu_create_env(g, "PWD", getcwd(viqu_buffer, 1024));
	}
	return (0);
}
