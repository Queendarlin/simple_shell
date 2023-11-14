#include "shell.h"

/**
 * viqu_interactive_mode - Function to show if the shell is in interactive mode
 * @viqu_info: Address of the structure containing shell information.
 * Return: 1 if the shell is in interactive mode, else 0
 */
int viqu_interactive_mode(info_t *viqu_info)
{
	return (isatty(STDIN_FILENO) && viqu_info->viqu_read_fd <= 2);
}
