#include "shell.h"

/**
 * viqu_list_len - Function to decide the length of a linked list.
 * @viqu_h: The actual pointer to the first node of the linked list.
 *
 * Return: The specific size of the linked list.
 */
size_t viqu_list_len(const list_t *viqu_h)
{
	size_t viqu_i = 0;

	while (viqu_h)
	{
		viqu_h = viqu_h->viqu_next;
		viqu_i++;
	}

	return (viqu_i);
}



/**
 * viqu_list_to_strings - Function to return an
 * array of strings from the list nodes.
 * @viqu_head: The pointer to the initial node in the linked list.
 *
 * Return: The complete array of strings.
 */
char **viqu_list_to_strings(list_t *viqu_head)
{
	list_t *viqu_node = viqu_head;
	size_t viqu_i = viqu_list_len(viqu_head), viqu_j;
	char **viqu_strs;
	char *viqu_str;

	if (!viqu_head || !viqu_i)
		return (NULL);

	viqu_strs = malloc(sizeof(char *) * (viqu_i + 1));

	if (!viqu_strs)
		return (NULL);

	for (viqu_i = 0; viqu_node; viqu_node = viqu_node->viqu_next, viqu_i++)
	{
		viqu_str = malloc(viqu_strlen(viqu_node->viqu_str) + 1);

		if (!viqu_str)
		{
			for (viqu_j = 0; viqu_j < viqu_i; viqu_j++)
				free(viqu_strs[viqu_j]);

			free(viqu_strs);
			return (NULL);
		}

		viqu_str = viqu_strcpy(viqu_str, viqu_node->viqu_str);
		viqu_strs[viqu_i] = viqu_str;
	}

	viqu_strs[viqu_i] = NULL;
	return (viqu_strs);
}



/**
 * viqu_print_list - Function to print all elements of a list_t linked list.
 * @viqu_h: The actual pointer to the first node of the linked list.
 *
 * Return: The correct size of the linked list.
 */
size_t viqu_print_list(const list_t *viqu_h)
{
	size_t viqu_i = 0;

	while (viqu_h)
	{
		viqu_puts(viqu_convert_number(viqu_h->viqu_num, 10, 0));
		viqu_putchar(':');
		viqu_putchar(' ');
		viqu_puts(viqu_h->viqu_str ? viqu_h->viqu_str : "(nil)");
		viqu_puts("\n");
		viqu_h = viqu_h->viqu_next;
		viqu_i++;
	}

	return (viqu_i);
}


/**
 * viqu_node_starts_with - Function to return a node
 * whose string starts with a prefix.
 * @viqu_node: The actual pointer to the list head.
 * @viqu_prefix: The matching string.
 * @viqu_c: The next character after the prefix to match.
 *
 * Return: Pointer to the matching node or NULL if no match.
 */
list_t *viqu_node_starts_with(list_t *viqu_node,
		char *viqu_prefix, char viqu_c)
{
	char *viqu_p = NULL;

	while (viqu_node)
	{
		viqu_p = viqu_starts_with(viqu_node->viqu_str, viqu_prefix);

		if (viqu_p && ((viqu_c == -1) || (*viqu_p == viqu_c)))
			return (viqu_node);

		viqu_node = viqu_node->viqu_next;
	}

	return (NULL);
}


/**
 * viqu_get_node_index - A function that
 * gets the index of a node in a linked list.
 * @viqu_head: The main pointer to the list head.
 * @viqu_node: The singular pointer to the node.
 *
 * Return: Index of the node when successful
 * or -1 when the node is not found.
 */
ssize_t viqu_get_node_index(list_t *viqu_head, list_t *viqu_node)
{
	size_t viqu_i = 0;

	while (viqu_head)
	{
		if (viqu_head == viqu_node)
			return (viqu_i);

		viqu_head = viqu_head->viqu_next;
		viqu_i++;
	}

	return (-1);
}
