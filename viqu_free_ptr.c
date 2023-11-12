#include "shell.h"

/**
 * viqu_free_ptr - A function that frees a pointer and NULLs the address.
 * @viqu_ptr: The address of the pointer to free.
 *
 * Return: 1 when successful, else 0.
 */

int viqu_free_ptr(void **viqu_ptr)
{
	if (viqu_ptr && *viqu_ptr)
	{
		free(*viqu_ptr);
		*viqu_ptr = NULL;
		return (1);
	}

	return (0);
}
