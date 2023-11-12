#include “shell.h”

/**
 * viqu_get_command_prompt - The function to get the command prompt
 * @viqu_sig_num: The unused parameter
 */

void viqu_get_command_prompt(__attribute__((unused))int viqu_sig_num)
{
	viqu_puts("\n");
	viqu_puts("$ ");
	viqu_putchar(VIQU_FLUSH_BUFFER);
}
