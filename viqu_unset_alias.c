#include "shell.h"

/**
 * viqu_unset_alias - Function to remove an alias specified by a string.
 * @viqu_info: Structure containing parameters.
 * @viqu_str: The string representing the alias.
 *
 * Return: 0 when successful or (1) if error occur.
 */

int viqu_unset_alias(info_t *viqu_info, char *viqu_str)
{
	char *viqu_p, viqu_c;
	int viqu_ret;

	viqu_p = viqu_get_str_char(viqu_str, '=');
	if (!viqu_p)
		return (1);

	viqu_c = *viqu_p;
	*viqu_p = 0;
	viqu_ret = viqu_del_node_idx(&(viqu_info->viqu_alias),
			viqu_gets_index_node(viqu_info->viqu_alias,
				viqu_prefix_node(viqu_info->viqu_alias, viqu_str, -1)));

	*viqu_p = viqu_c;
	return (viqu_ret);
}
