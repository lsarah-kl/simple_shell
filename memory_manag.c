#include "main.h"

/**
 * add_ln_nd_end - function that adds a cmd line at the end of a line_list.
 * @hd: linked list head
 * @cmd_line: Command line.
 *
 * Return: Address to the head.
 */
line_list *add_ln_nd_end(line_list **hd, char *cmd_line)
{
	line_list *nw, *tmp;

	nw = malloc(sizeof(line_list));
	if (nw == NULL)
		return (NULL);

	nw->line = cmd_line;
	nw->next = NULL;
	tmp = *hd;

	if (tmp == NULL)
	{
		*hd = nw;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = nw;
	}

	return (*hd);
}

/**
 * free_line_ls - Frees a line_list.
 * @hd: linked list head
 *
 * Return: Nothing
 */
void free_line_ls(line_list **hd)
{
	line_list *tmp;
	line_list *current;

	if (hd != NULL)
	{
		current = *hd;
		while ((tmp = current) != NULL)
		{
			current = current->next;
			free(tmp);
		}
		*hd = NULL;
	}
}

/**
 * add_node_en - Adds a separator found at the end
 * of a sep_list.
 * @hd: linked list head
 * @sp: Separator found (; | &).
 *
 * Return: Address of the head.
 */
sep_list *add_node_en(sep_list **hd, char sp)
{
	sep_list *new_n, *tmp;

	new_n = malloc(sizeof(sep_list));
	if (new_n == NULL)
		return (NULL);

	new_n->sep = sp;
	new_n->next = NULL;
	tmp = *hd;

	if (tmp == NULL)
	{
		*hd = new_n;
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_n;
	}

	return (*hd);
}

/**
 * free_sp_ls - Frees a sep_list.
 * @hd: linked lis t head .
 *
 * Return: Nothing
 */
void free_sp_ls(sep_list **hd)
{
	sep_list *tmp;
	sep_list *current;

	if (hd != NULL)
	{
		current = *hd;
		while ((tmp = current) != NULL)
		{
			current = current->next;
			free(tmp);
		}
		*hd = NULL;
	}
}
