#include "shell.h"

/**
 * viqu_reset_info - Function to set fields to their initial values
 * @viqu_info: Pointer to the list to be initialized
 *
 */

void viqu_reset_info(info_t *viqu_info)
{
	viqu_info->viqu_arg = NULL;
	viqu_info->viqu_argv = NULL;
	viqu_info->viqu_path = NULL;
	viqu_info->viqu_argc = 0;
}
