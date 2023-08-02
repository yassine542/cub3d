/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yajallal <yajallal@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 17:11:24 by yajallal          #+#    #+#             */
/*   Updated: 2023/08/02 22:02:28 by yajallal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_map	*add_new_node(char *line, char config, t_map *map, char type)
{
	t_map	*head;
	t_map	*new_node;

	head = map;
	new_node = ft_malloc(sizeof(t_map), 1, type);
	if (!new_node)
		return (NULL);
	new_node->line = line;
	new_node->cnofig = config;
	new_node->next = NULL;
	if (!map)
		map = new_node;
	else
	{
		while (head->next)
			head = head->next;
		head->next = new_node;
	}
	return (map);
}

t_map	*delete_node(t_map *head, char *str)
{
	t_map	*node;
	t_map	*remove;

	node = head;
	if (!head)
		return (NULL);
	if (!ft_strcmp(head->line, str))
	{
		remove = head;
		head = head->next;
		// free(remove->line);
		// remove->line = NULL;
		// free(remove);
		// remove = NULL;
		return (head);
	}
	while (node->next)
	{
		if (!ft_strcmp(node->line, str))
		{
			remove = node->next;
			node->next = node->next->next;
			// free(remove->line);
			// remove->line = NULL;
			// free(remove);
			// remove = NULL;
		}
		if (node->next)
			node = node->next;
	}
	return (head);
}
