#include "shell.h"

/**
 * viqu_conv_str_int - Function to convert the given string into an integer.
 * @viqu_string: The string to be transformed.
 *
 * Return: The converted number if numbers are found, otherwise returns 0.
 */
int viqu_conv_str_int(char *viqu_string)
{
	int viqu_index, viqu_sign = 1, viqu_flag = 0, viqu_outcome;
	unsigned int viqu_result = 0;

	for (viqu_index = 0; viqu_string[viqu_index] != '\0'
			&& viqu_flag != 2; viqu_index++)
	{
		if (viqu_string[viqu_index] == '-')
			viqu_sign *= -1;

		if (viqu_string[viqu_index] >= '0' && viqu_string[viqu_index] <= '9')
		{
			viqu_flag = 1;
			viqu_result *= 10;
			viqu_result += (viqu_string[viqu_index] - '0');
		}
		else if (viqu_flag == 1)
			viqu_flag = 2;
	}
	if (viqu_sign == -1)
		viqu_outcome = -viqu_result;
	else
		viqu_outcome = viqu_result;

	return (viqu_outcome);
}
