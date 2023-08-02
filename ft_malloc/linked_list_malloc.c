/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_malloc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 18:33:48 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/02 22:53:21 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_malloc.h"

t_malloc	*add_new_node_malloc(void *address, char type, t_malloc *head)
{
	t_malloc	*new_node;
	t_malloc	*nodes;

	nodes = head;
	new_node = (t_malloc *)malloc(sizeof(t_malloc));
	if (!new_node)
		return (NULL);
	new_node->address = address;
	new_node->type = type;
	new_node->next = NULL;
	if (!nodes)
		head = new_node;
	else
	{
		while (nodes->next)
			nodes = nodes->next;
		nodes->next = new_node;
	}
	return (head);
}

t_malloc	*delete_addr(t_malloc *head)
{
	t_malloc	*node;
	t_malloc	*remove;

	node = head;
	if (!head)
		return (NULL);
	while (node)
	{
		remove = node;
		node = node->next;
		if (remove->address)
		{
			free(remove->address);
			remove->address = NULL;
		}
		free(remove);
		remove = NULL;
	}
	head = NULL;
	return (head);
}

t_malloc	*delete_addr_before_after(t_malloc *head, char type)
{
	t_malloc	*node;
	t_malloc	*remove;

	node = head;
	if (!head)
		return (NULL);
	while (node)
	{
		if (node->type == type)
		{
			remove = node;
			node = node->next;
			if (remove->address)
			{
				free(remove->address);
				remove->address = NULL;
			}
			free(remove);
			remove = NULL;
		}
		else
			node = node->next;
	}
	return (head);
}
