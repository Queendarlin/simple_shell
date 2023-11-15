#include "shell.h"

/**
 * viqu_shell_loop - The Function for the specified shell loop.
 * @viqu_info: The structure containing parameter and return information.
 * @viqu_av:The main() function's command line arguments
 *
 * Return: 0 when successful, 1 when error is encountered, or error code.
 */

int viqu_shell_loop(info_t *viqu_info, char **viqu_av)
{
	ssize_t viqu_r = 0;
	int viqu_builtin_ret = 0;

	while (viqu_r != -1 && viqu_builtin_ret != -2)
	{
		viqu_reset_info(viqu_info);
		if (viqu_interactive_mode(viqu_info))
			viqu_puts("$ ");
		viqu_putchar_error(VIQU_FLUSH_BUFFER);
		viqu_r = viqu_receive_input(viqu_info);
		if (viqu_r != -1)
		{
			viqu_initialize_info(viqu_info, viqu_av);
			viqu_builtin_ret = viqu_find_cmd_builtin(viqu_info);
			if (viqu_builtin_ret == -1)
				viqu_search_command(viqu_info);
		}
		else if (viqu_interactive_mode(viqu_info))
			viqu_putchar('\n');
		viqu_free_list_field(viqu_info, 0);
	}
	viqu_create_append_hist(viqu_info);
	viqu_free_list_field(viqu_info, 1);
	if (!viqu_interactive_mode(viqu_info) && viqu_info->viqu_status)
		exit(viqu_info->viqu_status);
	if (viqu_builtin_ret == -2)
	{
		if (viqu_info->viqu_err_num == -1)
			exit(viqu_info->viqu_status);
		exit(viqu_info->viqu_err_num);
	}
	return (viqu_builtin_ret);
}
