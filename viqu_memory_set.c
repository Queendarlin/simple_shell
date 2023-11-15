#include "shell.h"

/**
 * viqu_memory_set - Function to use a single constant byte to fill memory
 * @viqu_s: The address of the memory region.
 * @viqu_b: The byte that *s will be filled with.
 * @viqu_n: The number of bytes that needs to be filled.
 * Return: Pointer to s.
 */
char *viqu_memory_set(char *viqu_s, char viqu_b, unsigned int viqu_n)
{
	unsigned int viqu_index;

	for (viqu_index = 0; viqu_index < viqu_n; viqu_index++)
		viqu_s[viqu_index] = viqu_b;


	return (viqu_s);
}
