#include “shell.h”

/**
 * viqu_retrieve_file_hist - Function to retrieve the history of a file path.
 * @viqu_info: Parameter for maintaining argument structure.
 *
 * Return: The specified string containing the history file path
 */
char *viqu_retrieve_file_hist(info_t *viqu_info)
{
	char *viqu_buf, *viqu_dir;

	viqu_dir = viqu_getenv(viqu_info, "HOME=");
	if (!viqu_dir)
		return (NULL);

	viqu_buf = malloc(sizeof(char) * (viqu_custom_strlen(viqu_dir) +
				viqu_custom_strlen(VIQU_FILE_HIISTORY) + 2));
	if (!viqu_buf)
		return (NULL);

	viqu_buf[0] = 0;

	viqu_custom_strcpy(viqu_buf, viqu_dir);

	viqu_custom_strcat(viqu_buf, "/");

	viqu_custom_strcat(viqu_buf, VIQU_FILE_HIISTORY);

	return (viqu_buf);
}
