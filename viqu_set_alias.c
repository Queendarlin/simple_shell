#include "shell.h"

/**
 * viqu_set_alias - Function to set an alias to a string.
 * @viqu_info: Structure containing parameters.
 * @viqu_str: The string alias.
 *
 * Return: Returns 0 when successful, or 1 on error.
 */

int viqu_set_alias(info_t *viqu_info, char *viqu_str)
{
	char *viqu_p;

	viqu_p = viqu_get_str_char(viqu_str, '=');
	if (!viqu_p)
		return (1);

	if (!*++viqu_p)
		return (viqu_unset_alias(viqu_info, viqu_str));

	viqu_unset_alias(viqu_info, viqu_str);

	return (viqu_suffix_node(&(viqu_info->viqu_custom_alias), viqu_str, 0) == NULL);
}
