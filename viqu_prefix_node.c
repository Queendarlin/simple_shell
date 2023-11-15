#include "shell.h"

/**
 * viqu_prefix_node - Function to return a node whose string starts
 * with a prefix.
 * @viqu_node: The actual pointer to the list head.
 * @viqu_prefix: The matching string.
 * @viqu_c: The next character after the prefix to match.
 *
 * Return: Pointer to the matching node or NULL if no match.
 */

list_t *viqu_prefix_node(list_t *viqu_node, char *viqu_prefix, char viqu_c)
{
	char *viqu_p = NULL;

	while (viqu_node)
	{
		viqu_p = viqu_string_start(viqu_node->viqu_str, viqu_prefix);
		if (viqu_p && ((viqu_c == -1) || (*viqu_p == viqu_c)))
			return (viqu_node);

		viqu_node = viqu_node->viqu_next;
	}
	return (NULL);
}
