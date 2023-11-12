#include "shell,h"

/**
 * viqu_initialize_info - Function initializes the fields of the linked list
 * @viqu_info: The pointer to the linked list
 * @viqu_av: The arguments passed to the function
 *
 */
void viqu_initialize_info(info_t *viqu_info, char **viqu_av)
{
	int viqu_index = 0;

	viqu_info->viqu_file_name = viqu_av[0];

	if (viqu_info->viqu_arg)
	{
		viqu_info->viqu_argv = viqu_main_string_token(viqu_info->viqu_arg, " \t");

		if (!viqu_info->viqu_argv)
		{
			viqu_info->viqu_argv = malloc(sizeof(char *) * 2);
			if (viqu_info->viqu_argv)
			{
				viqu_info->viqu_argv[0] = viqu_custom_strdup(viqu_info->viqu_arg);
				viqu_info->viqu_argv[1] = NULL;
			}
		}
		for (viqu_index = 0; viqu_info->viqu_argv &&
				viqu_info->viqu_argv[viqu_index]; viqu_index++)
			;

		viqu_info->viqu_argc = viqu_index;
		viqu_rep_alias(viqu_info);
		viqu_rep_variables(viqu_info);
	}
}
