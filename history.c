#include "shell.h"


/**
 * viqu_get_history_file - gets the history file
 * @viqu_info: parameter struct
 *
 * Return: allocated string containg history file
 */

char *viqu_get_history_file(info_t *viqu_info)
{
	char *viqu_buf, *viqu_dir;

	dir = viqu_getenv(viqu_info, "HOME=");
	if (!viqu_dir)
		return (NULL);
	viqu_buf = malloc(sizeof(char) * (viqu_strlen(viqu_dir) + viqu_strlen(HIST_FILE) + 2));
	if (!viqu_buf)
		return (NULL);
	viqu_buf[0] = 0;
	viqu_strcpy(viqu_buf, viqu_dir);
	viqu_strcat(viqu_buf, "/");
	viqu_strcat(viqu_buf, HIST_FILE);
	return (viqu_buf);
}


#include "shell.h"


/**
 * viqu_write_history - creates a file, or appends to an existing file
 * @viqu_info: the parameter struct
 *
 * Return: 1 on success, else -1
 */
int viqu_write_history(info_t *viqu_info)
{
	ssize_t viqu_fd;
	char *viqu_filename = viqu_get_history_file(viqu_info);
	list_t *viqu_node = NULL;

	if (!viqu_filename)
		return (-1);

	viqu_fd = open(viqu_filename, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(viqu_filename);
	if (viqu_fd == -1)
		return (-1);
	for (viqu_node = viqu_info->viqu_history; viqu_node; viqu_node = viqu_node->viqu_next)
	{
		viqu_putsfd(viqu_node->viqu_str, viqu_fd);
		viqu_putfd('\n', viqu_fd);
	}
	viqu_putfd(BUF_FLUSH, viqu_fd);
	close(viqu_fd);
	return (1);
}


#include "shell.h"


/**
 * viqu_read_history - reads history from file
 * @viqu_info: the parameter struct
 *
 * Return: viqu_histcount on success, 0 otherwise
 */
int viqu_read_history(info_t *viqu_info)
{
	int viqu_i, viqu_last = 0, viqu_linecount = 0;
	ssize_t viqu_fd, viqu_rdlen, viqu_fsize = 0;
	struct stat viqu_st;
	char *viqu_buf = NULL, *viqu_filename = viqu_get_history_file(info);

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
	for (viqu_i = 0; viqu_i < viqu_fsize; viqu_i++)
		if (viqu_buf[viqu_i] == '\n')
		{
			viqu_buf[viqu_i] = 0;
			viqu_build_history_list(viqu_info, viqu_buf + viqu_last, viqu_linecount++);
			viqu_last = viqu_i + 1;
		}
	if (viqu_last != viqu_i)
		viqu_build_history_list(viqu_info, viqu_buf + viqu_last, viqu_linecount++);
	free(viqu_buf);
	viqu_info->viqu_histcount = viqu_linecount;
	while (viqu_info->viqu_histcount-- >= HIST_MAX)
		viqu_delete_node_at_index(&(viqu_info->viqu_history), 0);
	viqu_renumber_history(viqu_info);
	return (viqu_info->viqu_histcount);
}

#include "shell.h"



/**
 * build_history_list - adds entry to a history linked list
 * @viqu_info: Structure containing potential arguments. Used to maintain
 * @viqu_buf: buffer
 * @viqu_linecount: the history linecount, viqu_histcount
 *
 * Return: Always 0
 */
int viqu_build_history_list(info_t *viqu_info, char *viqu_buf, int viqu_linecount)
{
	list_t *viqu_node = NULL;

	if (viqu_info->viqu_history)
		viqu_node = viqu_info->viqu_history;
	viqu_add_node_end(&viqu_node, viqu_buf, viqu_linecount);

	if (!viqu_info->viqu_history)
		viqu_info->viqu_history = viqu_node;
	return (0);
}


#include "shell.h"


/**
 * viqu_renumber_history - renumbers the history linked list after changes
 * @viqu_info: Structure containing potential arguments. Used to maintain
 *
 * Return: the new histcount
 */
int viqu_renumber_history(info_t *viqu_info)
{
	list_t *viqu_node = viqu_info->viqu_history;
	int viqu_i = 0;

	while (viqu_node)
	{
		viqu_node->viqu_num = viqu_i++;
		viqu_node = viqu_node->viqu_next;
	}
	return (viqu_info->viqu_histcount = i);
}
