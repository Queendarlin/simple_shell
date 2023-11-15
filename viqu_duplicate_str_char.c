#include "shell.h"

/**
 * viqu_duplicate_str_char - Function that will duplicate characters
 * in a string.
 * @viqu_pathstr: The PATH to the string
 * @viqu_start: Parameter that shows the index beginning
 * @viqu_stop: Parameter that shows the index to end
 *
 * Return: Pointer to a new buffer.
 */

char *viqu_duplicate_str_char(char *viqu_pathstr, int viqu_start,
		int viqu_stop)
{
	static char viqu_buf[1024];
	int viqu_index = 0, viqu_k = 0;

	/* Iterate through the specified range of characters */
	for (viqu_k = 0, viqu_index = viqu_start; viqu_index < viqu_stop;
			viqu_index++)
	{
		/* Copy non-colon characters to the buffer */
		if (viqu_pathstr[viqu_index] != ':')
			viqu_buf[viqu_k++] = viqu_pathstr[viqu_index];
	}

	/* Null-terminate the buffer */
	viqu_buf[viqu_k] = '\0';

	/* Return a pointer to the new buffer */
	return (viqu_buf);
}
