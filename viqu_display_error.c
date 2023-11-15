#include "shell.h"

/**
 * viqu_display_error - Displays an error message with information
 * @viqu_info: Pointer to the linked list.
 * @viqu_estring: The string containing the specified error type.
 */

void viqu_display_error(info_t *viqu_info, char *viqu_estring)
{
	viqu_puts_error(viqu_info->viqu_file_name);
	viqu_puts_error(": ");
	viqu_display_decimal(viqu_info->viqu_line_count, STDERR_FILENO);
	viqu_puts_error(": ");
	viqu_puts_error(viqu_info->viqu_argv[0]);
	viqu_puts_error(": ");
	viqu_puts_error(viqu_estring);
}

