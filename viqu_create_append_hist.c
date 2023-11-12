#include “shell.h”

/**
 * viqu_create_append_hist - Function to create or append a/an existing file.
 * @viqu_info: Parameter for maintaining argument structure.
 *
 * Return: 1 when successful, -1 when it fails.
 */
int viqu_create_append_hist(info_t *viqu_info)
{
	ssize_t viqu_fd;
	char *viqu_filename = viqu_retrieve_file_hist(viqu_info);
	list_t *viqu_node = NULL;

	if (!viqu_filename)
		return (-1);

	viqu_fd = open(viqu_filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(viqu_filename);
	if (viqu_fd == -1)
		return (-1);

	for (viqu_node = viqu_info->viqu_history;
			viqu_node; viqu_node = viqu_node->next)
	{
		viqu_puts_file_d(viqu_node->viqu_str, viqu_fd);
		viqu_put_file_d('\n', viqu_fd);
	}

	viqu_put_file_d(VIQU_FLUSH_BUFFER, viqu_fd);
	close(viqu_fd);
	return (1);
}
