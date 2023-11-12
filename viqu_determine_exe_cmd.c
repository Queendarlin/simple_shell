#include "shell.h"

/**
 * viqu_determine_exe_cmd - Function that determines if a file is
 * an executable command.
 * @viqu_info: The structure depicting the information.
 * @viqu_path: Pointer that directs to the file path
 *
 * Return: 1 when successful, 0 if it fails.
 */

int viqu_determine_exe_cmd(info_t *viqu_info, char *viqu_path)
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

