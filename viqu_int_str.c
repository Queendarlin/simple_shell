#include "shell.h"

/**
 * viqu_int_to_string - Function that transforms an integer into a string
 * @viqu_num: The numeric value to be converted.
 * @viqu_base: The numerical base for conversion.
 * @viqu_flags: Specific flags that may affect the conversion process.
 *
 * Return: String containing the converted number representation.
 */

char *viqu_int_to_string(long int viqu_num, int viqu_base, int viqu_flags)
{
	static char *viqu_array;
	static char viqu_buffer[50];
	char viqu_sign = 0;
	char *viqu_ptr;
	unsigned long viqu_n = viqu_num;

	if (!(viqu_flags & VIQU_TRANSFORM_UNSIGNED) && viqu_num < 0)
	{
		viqu_n = -viqu_num;
		viqu_sign = '-';
	}
	viqu_array = viqu_flags & VIQU_TRANSFORM_LOWERCASE
		? "0123456789abcdef" : "0123456789ABCDEF";
	viqu_ptr = &viqu_buffer[49];
	*viqu_ptr = '\0';

	do {
		*--viqu_ptr = viqu_array[viqu_n % viqu_base];
		viqu_n /= viqu_base;
	}
	while (viqu_n != 0);

	if (viqu_sign)
		*--viqu_ptr = viqu_sign;

	return (viqu_ptr);
}
