#include "shell.h"

/**
 * viqu_is_cmd - Function to locate an executable
 * @viqu_info: The parameter structure
 * @viqu_path: File path
 *
 * Return: 1 when successful, else 0
 */
int viqu_is_cmd(info_t *viqu_info, char *viqu_path)
{
	struct stat viqu_st;

	(void)viqu_info;

	if (!viqu_path || stat(viqu_path, &viqu_st))
		return (0);

	if (viqu_st.st_mode & S_IFREG)
	{
		return (1);
	}

	return (0);
}

/**
 * viqu_dup_chars - Function to double characters
 * @viqu_pathstr: String path
 * @viqu_start:[0].
 * @viqu_stop:End of index.
 *
 * Return: viqu_buf
 */
char *viqu_dup_chars(char *viqu_pathstr, int viqu_start, int viqu_stop)
{
	static char viqu_buf[1024];
	int viqu_i = 0, viqu_k = 0;

	for (viqu_k = 0, viqu_i = viqu_start; viqu_i < viqu_stop; viqu_i++)
		if (viqu_pathstr[viqu_i] != ':')
			viqu_buf[viqu_k++] = viqu_pathstr[viqu_i];

	viqu_buf[viqu_k] = 0;

	return (viqu_buf);
}


/**
 * viqu_find_path - Function to search for command PATH
 * @viqu_info: The parameter structure
 * @viqu_pathstr: PATH string.
 * @viqu_cmd: Command to search for
 *
 * Return: viqu_path when successful or NULL.when it fails
 */
char *viqu_find_path(info_t *viqu_info, char *viqu_pathstr, char *viqu_cmd)
{
	int viqu_i = 0, viqu_curr_pos = 0;
	char *viqu_path;

	if (!viqu_pathstr)
		return (NULL);

	if ((viqu_strlen(viqu_cmd) > 2) && viqu_starts_with(viqu_cmd, "./"))
	{
		if (viqu_is_cmd(viqu_info, viqu_cmd))
			return (viqu_cmd);
	}

	while (1)
	{
		if (!viqu_pathstr[viqu_i] || viqu_pathstr[viqu_i] == ':')
		{
			viqu_path = viqu_dup_chars(viqu_pathstr, viqu_curr_pos, viqu_i);

			if (!*viqu_path)
				viqu_strcat(viqu_path, viqu_cmd);
			else
			{
				viqu_strcat(viqu_path, "/");
				viqu_strcat(viqu_path, viqu_cmd);
			}

			if (viqu_is_cmd(viqu_info, viqu_path))
				return (viqu_path);

			if (!viqu_pathstr[viqu_i])
				break;

			viqu_curr_pos = viqu_i;
		}

		viqu_i++;
	}

	return (NULL);
}
