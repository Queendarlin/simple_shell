#include "shell.h"

/**
 * viqu_myhistory - displays the history list, one command by line, preceded
 *          	with line numbers, starting at 0.
 * @viqu_info: Structure containing potential arguments. Used to maintain
 *    	constant function prototype.
 *  Return: Always 0
 */
int viqu_myhistory(info_t *viqu_info)
{
          	print_list(viqu_info->viqu_history);
          	return (0);
}


#include "shell.h"

/**
 * viqu_unset_alias - sets alias to string
 * @viqu_info: parameter struct
 * @viqu_str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int viqu_unset_alias(info_t *viqu_info, char *viqu_str)
{
          	char *viqu_p, viqu_c;
          	int viqu_ret;

          	viqu_p = viqu_strchr(viqu_str, '=');
          	if (!viqu_p)
                         	return (1);
          	viqu_c = *viqu_p;
          	*viqu_p = 0;
          	viqu_ret = viqu_delete_node_at_index(&(viqu_info->viqu_alias),
                         	viqu_get_node_index(viqu_info->viqu_alias, viqu_node_starts_with(viqu_info->viqu_alias, viqu_str, -1)));
          	*viqu_p = c;
          	return (viqu_ret);
}

#include "shell.h"
/**
 * viqu_set_alias - sets alias to string
 * @viqu_info: parameter struct
 * @viqu_str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int viqu_set_alias(info_t *viqu_info, char *viqu_str)
{
          	char *viqu_p;

          	viqu_p = viqu_strchr(viqu_str, '=');
          	if (!viqu_p)
                         	return (1);
          	if (!*++viqu_p)
                         	return (viqu_unset_alias(viqu_info, viqu_str));

          	viqu_unset_alias(viqu_info, viqu_str);
          	return (viqu_add_node_end(&(viqu_info->viqu_alias), viqu_str, 0) == NULL);
}


#include "shell.h"

/**
 * viqu_print_alias - prints an alias string
 * @viqu_node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */

int viqu_print_alias(list_t *viqu_node)
{
          	char *viqu_p = NULL, *viqu_a = NULL;
 
          	if (viqu_node)
          	{
                         	viqu_p = _viqu_strchr(viqu_node->viqu_str, '=');
                         	for (viqu_a = viqu_node->viqu_str; viqu_a <= viqu_p; viqu_a++)
                         	viqu_putchar(*viqu_a);
                         	viqu_putchar('\'');
                         	viqu_puts(viqu_p + 1);
                         	viqu_puts("'\n");
                         	return (0);
          	}
          	return (1);
}


#include “shell.h”

/**
 * viqu_myalias - mimics the alias builtin (man alias)
 * @viqu_info: Structure containing potential arguments. Used to maintain
 *      	constant function prototype.
 *  Return: Always 0
 */
int viqu_myalias(info_t *viqu_info)
{
          	int viqu_i = 0;
          	char *viqu_p = NULL;
          	list_t *viqu_node = NULL;

          	if (viqu_info->viqu_argc == 1)
          	{
                         	viqu_node = viqu_info->viqu_alias;
                         	while (viqu_node)
                         	{
                                       	viqu_print_alias(viqu_node);
                                       	viqu_node = viqu_node->viqu_next;
                         	}
                         	return (0);
          	}
          	for (viqu_i = 1; viqu_info->viqu_argv[viqu_i];viqu_ i++)
          	{
                         	viqu_p = viqu_strchr(viqu_info->viqu_argv[viqu_i], '=');
                         	if (viqu_p)
                                       	viqu_set_alias(viqu_info, viqu_info->viqu_argv[viqu_i]);
                         	else
                                       	viqu_print_alias(viqu_node_starts_with(viqu_info->alias, info->argv[viqu_i], '='));
          	}

          	return (0);
}
