#include "shell.h"

/**
 * viqu_add_node - adds a node to the start of the list
 * @viqu_head: address of pointer to head node
 * @viqu_str: str field of node
 * @viqu_num: node index used by history
 *
 * Return: size of list
 */
list_t *viqu_add_node(list_t **viqu_head, const char *viqu_str, int viqu_num)
{
	list_t *viqu_new_head;

	if (!viqu_head)
		return (NULL);
	viqu_new_head = malloc(sizeof(list_t));
	if (!viqu_new_head)
		return (NULL);
	viqu_memset((void *)viqu_new_head, 0, sizeof(list_t));
	viqu_new_head->viqu_num = viqu_num;
	if (viqu_str)
	{
		viqu_new_head->viqu_str = viqu_strdup(viqu_str);
		if (!viqu_new_head->viqu_str)
		{
			free(viqu_new_head);
			return (NULL);
		}
	}
	viqu_new_head->viqu_next = *viqu_head;
	*viqu_head = viqu_new_head;
	return (viqu_new_head);
}


#include "shell.h"

/**
 * viqu_add_node_end - adds a node to the end of the list
 * @viqu_head: address of pointer to head node
 * @viqu_str: str field of node
 * @viqu_num: node index used by history
 *
 * Return: size of list
 */
list_t *viqu_add_node_end(list_t **viqu_head, const char *viqu_str, int viqu_num)
{
	list_t *viqu_new_node, *viqu_node;

	if (!viqu_head)
		return (NULL);

	viqu_node = *viqu_head;
	viqu_new_node = malloc(sizeof(list_t));
	if (!viqu_new_node)
		return (NULL);
	viqu_memset((void *)viqu_new_node, 0, sizeof(list_t));
	viqu_new_node->viqu_num = viqu_num;
	if (viqu_str)
	{
		viqu_new_node->viqu_str = viqu_strdup(viqu_str);
		if (!viqu_new_node->viqu_str)
		{
			free(viqu_new_node);
			return (NULL);
		}
	}
	if (viqu_node)
	{
		while (viqu_node->viqu_next)
			viqu_node = viqu_node->viqu_next;
		viqu_node->viqu_next = viqu_new_node;
	}
	else
		*viqu_head = viqu_new_node;
	return (viqu_new_node);
}


#include "shell.h"

/**
 * viqu_print_list_str - prints only the str element of a list_t linked list
 * @viqu_h: pointer to first node
 *
 * Return: size of list
 */

size_t viqu_print_list_str(const list_t *viqu_h)
{
	size_t viqu_i = 0;

	while (viqu_h)
	{
		viqu_puts(viqu_h->viqu_str ? viqu_h->viqu_str : "(nil)");
		viqu_puts("\n");
		viqu_h = viqu_h->viqu_next;
		viqu_i++;
	}
	return (viqu_i);
}


#include "shell.h"


/**
 * viqu_delete_node_at_index - deletes node at given index
 * @viqu_head: address of pointer to first node
 * @viqu_index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int viqu_delete_node_at_index(list_t **viqu_head, unsigned int viqu_index)
{
	list_t *viqu_node, *viqu_prev_node;
	unsigned int viqu_i = 0;

	if (!viqu_head || !*viqu_head)
		return (0);

	if (!viqu_index)
	{
		viqu_node = *viqu_head;
		*viqu_head = (*viqu_head)->viqu_next;
		free(viqu_node->viqu_str);
		free(viqu_node);
		return (1);
	}
	node = *viqu_head;
	while (viqu_node)
	{
		if (viqu_i == viqu_index)
		{
			viqu_prev_node->viqu_next = viqu_node->viqu_next;
			free(viqu_node->viqu_str);
			free(viqu_node);
			return (1);
		}
		viqu_i++;
		viqu_prev_node = viqu_node;
		viqu_node = viqu_node->viqu_next;
	}
	return (0);
}


#include "shell.h"

/**
 * viqu_free_list - frees all nodes of a list
 * @viqu_head_ptr: address of pointer to head node
 *
 * Return: void
 */
void viqu_free_list(list_t **viqu_head_ptr)
{
	list_t *viqu_node, *viqu_next_node, *viqu_head;

	if (!viqu_head_ptr || !*viqu_head_ptr)
		return;
	viqu_head = *viqu_head_ptr;
	viqu_node = viqu_head;
	while (viqu_node)
	{
		viqu_next_node = viqu_node->viqu_next;

		free(viqu_node->viqu_str);
		free(viqu_node);
		viqu_node = viqu_next_node;
	}
	*viqu_head_ptr = NULL;
}
