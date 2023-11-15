#include "shell.h"

/**
 * viqu_comment_sign_removal - Function to alter the string by cutting off'#'
 * @viqu_buf: Pointer to the string to be modified.
 *
 */
void viqu_comment_sign_removal(char *viqu_buf)
{
	int viqu_index;

	for (viqu_index = 0; viqu_buf[viqu_index] != '\0'; viqu_index++)
	{
		if (viqu_buf[viqu_index] == '#' &&
				(!viqu_index || viqu_buf[viqu_index - 1] == ' '))
		{
			viqu_buf[viqu_index] = '\0';
			break;
		}
	}
}
