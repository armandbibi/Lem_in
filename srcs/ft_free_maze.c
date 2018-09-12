/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_maze.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 21:25:55 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/12 18:04:45 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

void	del_all_nodes(t_adj_lst *lst)
{
	t_adj_node *node1;
	t_adj_node *node2;

	node1 = lst->head;
	while (node1)
	{
		node2 = node1;
		node1 = node1->next;
		free(node2);
	}
	free(lst->name);
}

void	ft_del_good_ways(t_stack **good_ways, int nbr_of_valid_way)
{
	int n;

	n = 0;
	while (n < nbr_of_valid_way)
	{
		ft_del_stack(good_ways[n]);
		n++;
	}
	free(good_ways);
}
void	ft_del_maze(t_maze *maze)
{
	t_instruction	*tmp_instruction;
	t_instruction	*tmp_instruction2;
	int				lst_iterateur;

	tmp_instruction = maze->head;
	while (tmp_instruction)
	{
		tmp_instruction2 = tmp_instruction;
		tmp_instruction = tmp_instruction->next;
		free(tmp_instruction2->str);
		free(tmp_instruction2->error);
		free(tmp_instruction2);
	}
	ft_del_good_ways(maze->good_ways, maze->nbr_of_good_ways);
	lst_iterateur = 0;
	while (lst_iterateur < maze->nbr_rooms)
	{
		del_all_nodes(&maze->tab_adj[lst_iterateur]);
		lst_iterateur++;
	}
	free(maze->tab_adj);
}
