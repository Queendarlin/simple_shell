#include "shell.h"

/**
 * viqu_custom_realloc - Function for memory block reallocation.
 * @viqu_ptr: The preceding malloc allocated block's pointer.
 * @viqu_old_size:The previous block's size, in bytes.
 * @viqu_new_size: The new block's size, in bytes.
 * Return: ..
 */

void *viqu_custom_realloc(void *viqu_ptr, unsigned int viqu_old_size,
		unsigned int viqu_new_size)
{
	char *viqu_p;

	if (!viqu_ptr)
		return (malloc(viqu_new_size));

	if (!viqu_new_size)
		return (free(viqu_ptr), NULL);
	if (viqu_new_size == viqu_old_size)
		return (viqu_ptr);

	viqu_p = malloc(viqu_new_size);

	if (!viqu_p)
		return (NULL);
	viqu_old_size = viqu_old_size < viqu_new_size ? viqu_old_size : viqu_new_size;
	while (viqu_old_size--)
		viqu_p[viqu_old_size] = ((char *)viqu_ptr)[viqu_old_size];

	free(viqu_ptr);
	return (viqu_p);
}
