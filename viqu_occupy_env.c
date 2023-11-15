#include "shell.h"

/**
 * viqu_occupy_environ_list - Function to populate the environment linked list.
 * @viqu_info: Structure containing information related to potential arguments.
 *
 * Return: Always returns 0.
 */

int viqu_occupy_environ_list(info_t *viqu_info)
{
	list_t *viqu_node = NULL;
	size_t viqu_index;

	for (viqu_index = 0; environ[viqu_index]; viqu_index++)
		viqu_suffix_node(&viqu_node, environ[viqu_index], 0);

	viqu_info->viqu_env = viqu_node;

	return (0);
}
