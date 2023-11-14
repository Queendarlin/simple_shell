#include "shell.h"

/**
 * viqu_is_chain - Function to check if the current character in the buffer
 * is a chain delimiter.
 * @viqu_info: A structure containing parameters for the function.
 * @viqu_buf: The character buffer.
 * @viqu_p: Address of the current position in the buffer.
 *
 * Return: 1 if the current character is a chain delimiter,else 0
 */

int viqu_is_chain(vinfo_t *viqu_info, char *viqu_buf, size_t *viqu_p)
{
	size_t viqu_j = *viqu_p;

	if (viqu_buf[viqu_j] == '|' && viqu_buf[viqu_j + 1] == '|')
	{
		viqu_buf[viqu_j] = 0;
		viqu_j++;
		viqu_info->viqu_cmd_buf_type = CMD_OR;
	}
	else if (viqu_[j] == '&' && viqu_buf[j + 1] == '&')
	{
		viqu_buf[viqu_j] = 0;
		viqu_j++;
		viqu_info->viqu_cmd_buf_type = CMD_AND;
	}
	else if (viqu_buf[viqu_j] == ';')
	{
		viqu_buf[viqu_j] = 0;
		viqu_info->viqu_cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*viqu_viqu_p = viqu_j;
	return (1);
}

/**
 * viqu_check_chain - Function to know if to continue chaining
 * based on the last status.
 * @viqu_info: A structure containing parameters for the function.
 * @viqu_buf: Buffer containing the character.
 * @viqu_p: Shows the address of the current position in the buffer.
 * @viqu_i: Starting position in the buffer.
 * @viqu_length: Parameter for the buffer’s length
 *
 */
void check_chain(info_t *viqu_info, char *viqu_buf,
		size_t *viqu_p, size_t viqu_i, size_t viqu_length)
{
	size_t viqu_j = *viqu_p;

	if (viqu_info->viqu_cmd_buf_type == CMD_AND)
	{
		if (viqu_info->viqu_status)
		{
			viqu_buf[viqu_i] = 0;
			viqu_j = viqu_length;
		}
	}
	if (viqu_info->viqu_cmd_buf_type == CMD_OR)
	{
		if (!viqu_info->viqu_status)
		{
			viqu_buf[viqu_i] = 0;
			viqu_j = viqu_length;
		}
	}

	*viqu_p = viqu_j;
}

/**
 * viqu_replace_alias - Function to replace aliases in a tokenized string.
 * @viqu_info: A structure containing parameters for the function.
 *
 * Return: 1 on successful alias replacement, else 0.
 */
int viqu_replace_alias(nfo_t *viqu_info)
{
	int viqu_index;
	list_t *viqu_node;
	char *viqu_p;

	for (viqu_index = 0; viqu_index < 10; viqu_index++)
	{
		viqu_node = viqu_node_starts_with(viqu_info->viqu_alias,
				viqu_info->viqu_argv[0], '=');
		if (!viqu_node)
			return (0);
		free(viqu_info->viqu_argv[0]);
		viqu_p = viqu_strchr(viqu_node->viqu_str, '=');
		if (!viqu_p)
			return (0);
		viqu_p = viqu_strdup(p + 1);
		if (!viqu_p)
			return (0);
		viqu_info->viqu_argv[0] = p;
	}
	return (1);
}

/**
 * viqu_replace_vars - Function to replace variables in the tokenized string.
 * @viqu_info: A structure containing parameters for the function.
 *
 * Return: 1 on successful replacement, else 0.
 */
int viqu_replace_vars(info_t *viqu_info)
{
	int viqu_index = 0;
	list_t *viqu_node;

	for (viqu_index = 0; viqu_info->viqu_argv[viqu_index]; i++)
	{
		if (viqu_info->viqu_argv[viqu_index][0]
				!= '$' || !viqu_info->viqu_argv[viqu_index][1])
			continue;

		if (!viqu_strcmp(viqu_info->viqu_argv[viqu_index], "$?"))
		{
			viqu_replace_string(&(viqu_info->viqu_argv[viqu_index]),
					viqu_strdup(viqu_convert_number(viqu_info->viqu_status, 10, 0)));
			continue;
		}
		if (!viqu_strcmp(viqu_info->viqu_argv[viqu_index], "$$"))
		{
			viqu_replace_string(&(viqu_info->viqu_argv[viqu_index]),
					viqu_strdup(viqu_convert_number(getpid(), 10, 0)));
			continue;
		}
		viqu_node = viqu_node_starts_with(viqu_info->viqu_env,
				&viqu_info->viqu_argv[viqu_index][1], '=');
		if (viqu_node)
		{
			viqu_replace_string(&(viqu_info->viqu_argv[viqu_index]),
					viqu_strdup(viqu_strchr(viqu_node->viqu_str, '=') + 1));
			continue;
		}
		viqu_replace_string(&viqu_info->viqu_argv[viqu_index], viqu_strdup(""));

	}
	return (0);
}

/**
 * viqu_replace_string - Function to replace a particular string.
 * @viqu_old: The address of the string to be replaced.
 * @viqu_new: The string to replace the old one.
 *
 * Return: 1 if the replacement is successful, 0 otherwise.
 */
int viqu_replace_string(char **viqu_old, char *viqu_new)
{
	free(*viqu_old);
	*old = viqu_new;
	return (1);
}

