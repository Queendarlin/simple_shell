#include "shell.h"

/**
 * viqu_copy_string - Function to copy a string up to a number of char
 * @viqu_dest: The destination string to receive the copy
 * @viqu_src: The source string that will copied to dest
 * @viqu_num: The maximum number of characters to copy.
 *
 * Return: Returns a pointer to the resulting string (@viqu_dest).
 */
char *viqu_copy_string(char *viqu_dest, char *viqu_src, int viqu_num)
{
	char *viqu_result = viqu_dest;
	int viqu_index,  viqu_temp;

	viqu_index = 0;

	while (viqu_src[viqu_index] != '\0' && viqu_index < viqu_num - 1)
	{
		viqu_dest[viqu_index] = viqu_src[viqu_index];
		viqu_index++;
	}


	if (viqu_index < viqu_num)
	{
		viqu_temp = viqu_index;
		while (viqu_temp < viqu_num)
		{
			viqu_dest[viqu_temp] = '\0';
			viqu_temp++;
		}
	}

	return (viqu_result);
}
