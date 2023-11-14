#include "shell.h"

/**
 * viqu_clear_info - initializes info_t struct
 * @viqu_info: struct address
 */

void viqu_clear_info(info_t *viqu_info)
{
	viqu_info->viqu_arg = NULL;
	viqu_info->viqu_argv = NULL;
	viqu_info->viqu_path = NULL;
	viqu_info->viqu_argc = 0;
}


#include "shell.h"


/**
 * viqu_set_info - initializes info_t struct
 * @viqu_info: struct address
 * @viqu_av: argument vector
 */

void viqu_set_info(info_t *viqu_info, char **viqu_av)
{
	int viqu_i = 0;

	viqu_info->viqu_fname = viqu_av[0];
	if (viqu_info->viqu_arg)
	{
		viqu_info->viqu_argv = viqu_strtow(viqu_info->viqu_arg, " \t");
		if (!viqu_info->viqu_argv)
		{
			viqu_info->viqu_argv = malloc(sizeof(char *) * 2);
			if (viqu_info->viqu_argv)
			{
				viqu_info->viqu_argv[0] = viqu_strdup(viqu_info->viqu_arg);
				viqu_info->viqu_argv[1] = NULL;
			}
		}
		for (viqu_i = 0; viqu_info->viqu_argv && viqu_info->viqu_argv[viqu_i]; viqu_i++)
			;
		viqu_info->viqu_argc = viqu_i;

		viqu_replace_alias(viqu_info);
		viqu_replace_vars(viqu_info);
	}
}


#include "shell.h"

/**
 * viqu_free_info - frees info_t struct fields
 * @viqu_info: struct address
 * @viqu_all: true if freeing all fields
 */

void viqu_free_info(info_t *viqu_info, int viqu_all)
{
	viqu_ffree(viqu_info->viqu_argv);
	viqu_info->viqu_argv = NULL;
	viqu_info->viqu_path = NULL;
	if (viqu_all)
	{
		if (!viqu_info->viqu_cmd_buf)
			free(viqu_info->arg);
		if (info->viqu_env)
			free_list(&(viqu_info->viqu_env));
		if (viqu_info->viqu_history)
			viqu_free_list(&(viqu_info->viqu_history));
		if (viqu_info->viqu_viqu_alias)
			viqu_free_list(&(viqu_info->viqu_alias));
		viqu_ffree(viqu_info->viqu_environ);
		viqu_info->viqu_environ = NULL;
		viqu_bfree((void **)viqu_info->viqu_cmd_buf);
		if (viqu_info->viqu_readfd > 2)
			close(viqu_info->viqu_readfd);
		viqu_putchar(BUF_FLUSH);
	}
}
