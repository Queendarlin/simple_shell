#include "shell.h"

/**
 * viqu_free_list_field - Function to free fields of the linked list.
 * @viqu_info: Pointer to the structure to be freed.
 * @viqu_every: The parameter to know if every field should be freed
 */

void viqu_free_list_field(info_t *viqu_info, int viqu_every)
{
	viqu_free_web_string(viqu_info->viqu_argv);
	viqu_info->viqu_argv = NULL;
	viqu_info->viqu_path = NULL;

	if (viqu_every)
	{
		if (!viqu_info->viqu_cmd_buf)
			viqu_free_ptr(viqu_info->viqu_arg);

		if (viqu_info->viqu_env)
			viqu_free_all_nodes(&(viqu_info->viqu_env));

		if (viqu_info->viqu_history)
			viqu_free_all_nodes(&(viqu_info->viqu_history));

		if (viqu_info->viqu_alias)
			viqu_free_all_nodes(&(viqu_info->viqu_alias));

		viqu_free_web_string(viqu_info->viqu_environ);
		viqu_info->viqu_environ = NULL;

		viqu_free_ptr((void **)viqu_info->viqu_cmd_buf);
		if (viqu_info->viqu_read_fd > 2)
			close(viqu_info->viqu_read_fd);

		viqu_putchar(VIQU_FLUSH_BUFFER);
	}
}
