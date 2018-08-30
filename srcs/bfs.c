/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 22:00:23 by abiestro          #+#    #+#             */
/*   Updated: 2018/08/30 03:04:06 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <limits.h>

static int is_layer_attribuate(t_adj_lst *room, t_adj_node *node)
{
	if (!room || !node)
		print_fatal_error("problem in layer attribution");
	return ((node->dest->layer <=  room->layer));
}

void		ft_bfs(t_maze *maze)
{
	t_queue		*queue;
	t_adj_lst	*current_room;
	t_adj_node	*current_node;


	queue = new_queue(maze->nbr_rooms);	
	maze->start->layer = 0;
	ft_enqueue(queue, maze->start);
	while (!ft_queue_is_empty(queue))
	{
		current_room = ft_dequeue(queue);
		current_node = current_room->head;
		while (current_node != NULL)
		{
			if (!is_layer_attribuate(current_room, current_node))
			{
				current_node->dest->layer = current_room->layer + 1;
				ft_enqueue(queue, current_node->dest);
			}
			else if (current_node->dest->layer != INT_MAX && current_node->dest->layer < current_room->layer)
				ft_delete_node(current_room, current_node);
			current_node = current_node->next;
		}
	}
}
