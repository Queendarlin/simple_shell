#include "shell.h"

/**
 * viqu_memset - Function for memory setting
 * @viqu_s: Pointer to the set memory.
 * @viqu_b:Byte for memory filling.
 * @viqu_n: Byte quantity filled.
 *
 * Return: viqu_s
 */
char *viqu_memset(char *viqu_s, char viqu_b, unsigned int viqu_n)
{
	unsigned int viqu_i;

	for (viqu_i = 0; viqu_i < viqu_n; viqu_i++)
		viqu_s[viqu_i] = viqu_b;

	return (viqu_s);
}


/**
 * viqu_ffree - Function for freeing a web of strings.
 * @viqu_pp: We of strings to free
 */
void viqu_ffree(char **viqu_pp)
{
	char **viqu_a = viqu_pp;

	if (!viqu_pp)
		return;

	while (*viqu_pp)
		free(*viqu_pp++);

	free(viqu_a);
}


/**
 * viqu_realloc - Function for memory reallocation
 * @viqu_ptr: Pointer to previous memory allocated
 * @viqu_old_size: The size allocated to previous block
 * @viqu_new_size: The size allocated to current block.
 *
 * Return: viqu_p
 */
void *viqu_realloc(void *viqu_ptr, unsigned int viqu_old_size,
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


/**
 * viqu_bfree - Function for freeing a pointer
 * @viqu_ptr: Address of pointer that needs to be freed
 *
 * Return: 1 when successful, else 0.
 */
int viqu_bfree(void **viqu_ptr)
{
	if (viqu_ptr && *viqu_ptr)
	{
		free(*viqu_ptr);
		*viqu_ptr = NULL;
		return (1);
	}

	return (0);
}
