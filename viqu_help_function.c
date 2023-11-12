#include “shell.h”

/**
 * viqu_help_function - Function that oversees the initial help functionality
 * @viqu_info: Contains potential arguments for consistent function prototypes.
 *
 * Return: 0 on success, indicating basic functionality for the help system.
 */

int viqu_help_function(viqu_info_t *viqu_info)
{
	char **viqu_arg_array;

	viqu_arg_array = viqu_info->viqu_argv;
	viqu_puts("help call works. Function not yet implemented \n");
	if (0)
		viqu_puts(*viqu_arg_array);
	return (0);
}
