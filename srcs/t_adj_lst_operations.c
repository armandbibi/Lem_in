/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_adj_lst_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:34:16 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/19 18:19:19 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

t_adj_node	*new_adj_node(t_adj_lst *dest)
{
	t_adj_node	*new_node;

	new_node = malloc(sizeof(t_adj_node));
	if (!new_node)
		exit(0);
	new_node->dest = dest;
	new_node->next = NULL;
	return (new_node);
}

t_adj_lst	*new_tab_adj(int nbr_rooms)
{
	t_adj_lst	*new_tab;
	int			i;

	new_tab = malloc(sizeof(t_adj_lst) * nbr_rooms);
	if (!new_tab)
		return (NULL);
	i = 0;
	while (i < nbr_rooms)
	{
		new_tab[i].head = NULL;
		new_tab[i].name = NULL;
		new_tab[i].prev_in_graph = NULL;
		i++;
	}
	return (new_tab);
}

void		ft_add_lst_edge(t_adj_lst *tab, t_adj_lst *dest, t_adj_lst *srcs)
{
	t_adj_node	*new_node;

	(void)tab;
	new_node = new_adj_node(dest);
	new_node->next = srcs->head;
	srcs->head = new_node;
	new_node = new_adj_node(srcs);
	new_node->next = dest->head;
	dest->head = new_node;
}

void		ft_delete_node(t_adj_lst *lst, t_adj_node *node)
{
	t_adj_node	*tmp;

	tmp = lst->head;
	if (tmp == node)
	{
		lst->head = tmp->next;
		free(tmp);
		return ;
	}
	while (tmp)
	{
		if (tmp->next == node)
		{
			tmp->next = node->next;
			free(node);
			return ;
		}
		tmp = tmp->next;
	}
}
