#include "shell.h"

/**
 * viqu_exit_control - Function for shell's exit process
 * @viqu_info: Structure containing potential arguments
 *
 * Return: (-2) if an argument is provided, and (-2) for no specified exit
 */

int viqu_exit_control(info_t *viqu_info)
{
	int viqu_exit_check;

	if (viqu_info->viqu_argv[1])
	{
		viqu_exit_check = viqu_error_check_int(viqu_info->viqu_argv[1]);

		if (viqu_exit_check == -1)
		{
			viqu_info->viqu_status = 2;
			viqu_display_error(viqu_info, "Illegal number: ");
			viqu_puts_error(viqu_info->viqu_argv[1]);
			viqu_putchar_error('\n');
			return (1);
		}

		viqu_info->viqu_err_num = viqu_error_check_int(viqu_info->viqu_argv[1]);
		return (-2);
	}

	viqu_info->viqu_err_num = -1;
	return (-2);
}
