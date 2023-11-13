#include "shell.h"

/**
 * viqu_display_command_hist - Function to display of the command history list.
 * @viqu_info: A structured container for potential arguments
 *
 * Return: 0 to indicate the successful presentation of the history list.
 */

int viqu_display_command_hist(info_t *viqu_info)
{
	viqu_print_list_elements(viqu_info->viqu_history);
	return (0);
}
