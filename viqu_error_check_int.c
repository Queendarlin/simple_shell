#include "shell.h"

/**
 * viqu_error_check_int - Function to convert a str to an int and check erro
 * @viqu_string: The string to convert into an integer.
 *
 * Return: Returns the converted number if valid, 0 if no numbers in the str
 * or -1 on error.
 */
int viqu_error_check_int(char *viqu_string)
{
	int viqu_index = 0;
	unsigned long int viqu_result = 0;

	if (*viqu_string == '+')
		viqu_string++;

	for (viqu_index = 0; viqu_string[viqu_index] != '\0'; viqu_index++)
	{
		if (viqu_string[viqu_index] >= '0' && viqu_string[viqu_index] <= '9')
			viqu_result *= 10;
			viqu_result += (viqu_string[viqu_index] - '0');

			if (viqu_result > INT_MAX)
				return (-1);
		}
		else
		{
			return (-1);
		}
	}
	return (viqu_result);
}
