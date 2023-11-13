#include "shell.h"

/**
 * viqu_buffer_read - Function to read the contents of a buffer
 * @viqu_info: The parameter for the structure
 * @viqu_buf: The buffer to read from
 * @viqu_idx: The actual size of the buffer
 *
 * Return: The whole inputs read
 */
ssize_t viqu_buffer_read(info_t *viqu_info, char *viqu_buf, size_t *viqu_idx)
{
	ssize_t viqu_read = 0;

	if (*viqu_idx)
		return (0);
	viqu_read = read(viqu_info->viqu_read_fd, viqu_buf, VIQU_GET_BUFFER_SIZE);
	if (viqu_read >= 0)
		*viqu_idx = viqu_read;
	return (viqu_read);
}
