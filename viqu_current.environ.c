#include "shell.h"

/**
 * viqu_current_environ - Function to print the current shell environment
 * @viqu_info: Structure containing information related to arguments.
 *
 * Return: Always returns 0.
 */
int viqu_current_environ(info_t *viqu_info)
{
	viqu_print_str_element(viqu_info->viqu_env);

	return (0);
}
