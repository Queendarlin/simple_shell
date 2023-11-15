#include "shell.h"

/**
 * viqu_read_file_hist - A function to read the history of a file
 * @viqu_info: Parameter for maintaining argument structure
 *
 * Return: The count of history when successful, or 0 when it fails
 */
int viqu_read_file_hist(info_t *viqu_info)
{
	int viqu_idx, viqu_last = 0, viqu_linecount = 0;
	ssize_t viqu_fd, viqu_rdlen, viqu_fsize = 0;
	struct stat viqu_st;
	char *viqu_buf = NULL, *viqu_filename = viqu_retrieve_file_hist(viqu_info);

	if (!viqu_filename)
		return (0);
	viqu_fd = open(viqu_filename, O_RDONLY);
	free(viqu_filename);
	if (viqu_fd == -1)
		return (0);
	if (!fstat(viqu_fd, &viqu_st))
		viqu_fsize = viqu_st.st_size;
	if (viqu_fsize < 2)
		return (0);
	viqu_buf = malloc(sizeof(char) * (viqu_fsize + 1));
	if (!viqu_buf)
		return (0);
	viqu_rdlen = read(viqu_fd, viqu_buf, viqu_fsize);
	viqu_buf[viqu_fsize] = 0;
	if (viqu_rdlen <= 0)
		return (free(viqu_buf), 0);
	close(viqu_fd);
	for (viqu_idx = 0; viqu_idx < viqu_fsize; viqu_idx++)
		if (viqu_buf[viqu_idx] == '\n')
		{
			viqu_buf[viqu_idx] = 0;
			viqu_enter_hist_list(viqu_info, viqu_buf + viqu_last, viqu_linecount++);
			viqu_last = viqu_idx + 1;
		}
	if (viqu_last != viqu_idx)
		viqu_enter_hist_list(viqu_info, viqu_buf + viqu_last, viqu_linecount++);
	free(viqu_buf);
	viqu_info->viqu_hist_count = viqu_linecount;
	while (viqu_info->viqu_hist_count-- >= VIQU_MAXIMUM_HIISTORY)
		viqu_del_node_idx(&(viqu_info->viqu_history), 0);
	viqu_renum_hist_list(viqu_info);
	return (viqu_info->viqu_hist_count);
}
