/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_adj_lst_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:34:16 by abiestro          #+#    #+#             */
/*   Updated: 2018/08/23 17:47:23 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "stdlib.h"

t_adj_node	*new_adj_node(t_adj_lst *dest)
{
	t_adj_node	*new_node;

	new_node = malloc(sizeof(new_node));
	if (!new_node)
		print_fatal_error("Malloc error");
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
		print_fatal_error("malloc error");
	i = 0;
	while (i < nbr_rooms)
	{
		new_tab[i].head = NULL;
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

void		show_adj_lst_tab(t_adj_lst *tab, int size)
{
	int			v;
	t_adj_node	*tmp;

	v = 0;
	while (v < size)
	{
		tmp = tab[v].head;
		printf("name : %s\ndest:\n", tab[v].name);
		while (tmp)
		{
			printf("%s ", tmp->dest->name);
			tmp = tmp->next;
		}
		printf("\n");
		v++;
	}
}
