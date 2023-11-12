#include "shell.h"

/**
 * viqu_find_cmd_path - Function to find the specified
 * command in the PATH string.
 * @viqu_info: The structure information
 * @viqu_pathstr: The path to the string.
 * @viqu_cmd: The desired command to look for
 *
 * Return: Full path of the command if found, or NULL.
 */

char *viqu_find_cmd_path(info_t *viqu_info, char *viqu_pathstr, char *viqu_cmd)
{
	int viqu_index = 0, viqu_curr_pos = 0;
	char *viqu_path;

	if (!viqu_pathstr)
		return (NULL);

	if ((viqu_custom_strlen(viqu_cmd) > 2) && viqu_string_start(viqu_cmd, "./"))
	{
		if (viqu_determine_exe_cmd(viqu_info, viqu_cmd))
			return (viqu_cmd);
	}

	while (1)
	{
		if (!viqu_pathstr[viqu_index] || viqu_pathstr[viqu_index] == ':')
		{
			viqu_path = viqu_duplicate_str_char(viqu_pathstr,
					viqu_curr_pos, viqu_index);
			if (!*viqu_path)
				viqu_custom_strcat(viqu_path, viqu_cmd);
			else
			{
				viqu_custom_strcat(viqu_path, "/");
				viqu_custom_strcat(viqu_path, viqu_cmd);
			}
			if (viqu_determine_exe_cmd(viqu_info, viqu_path))
				return (viqu_path);
			if (!viqu_pathstr[viqu_index])
				break;
			viqu_curr_pos = viqu_index;
		}
		viqu_index++;
	}

	return (NULL);
}
