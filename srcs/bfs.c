/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 22:00:23 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/01 15:04:00 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <limits.h>
#include <stdlib.h>

static int		is_layer_attribuate(t_adj_lst *room, t_adj_node *node)
{
	if (!room || !node)
		print_fatal_error("problem in layer attribution");
	return ((node->dest->layer <= room->layer) || node->dest->belong_to_pass);
}

static void		ft_add_to_current_pass(t_adj_lst *room, t_stack *stack)
{
	while (ft_stack_see_top(stack) &&
			room->layer < ft_stack_see_top(stack)->layer)
		ft_stack_pop(stack);
	ft_stack_push(stack, room);
}

static int		ft_show_valid_stack(t_maze *maze, t_adj_lst *room_before_end)
{
	t_adj_lst	*current_room;
	int			size;

	printf("\n\n");
	current_room = room_before_end;
	size = 0;
	printf("%s -->", maze->end->name);
	while (current_room->prev_in_graph)
	{
		printf("%s -->", current_room->name);
		current_room->belong_to_pass = 1;
		current_room = current_room->prev_in_graph;
		size++;
	}
	printf("\n\n");
	return (size);
}

	static void		iter_through_destination
(t_adj_lst *current_room, t_queue *queue)
{
	t_adj_node	*current_node;

	current_node = current_room->head;
	while (current_node != NULL)
	{
		if (!is_layer_attribuate(current_room, current_node))
		{
			current_node->dest->layer = current_room->layer + 1;
			current_node->dest->prev_in_graph = current_room;
			ft_enqueue(queue, current_node->dest);
		}
		current_node = current_node->next;
	}
}

void			ft_bfs(t_maze *maze)
{
	t_queue		*queue;
	t_adj_lst	*current_room;
	t_stack		*lst_of_valid_pass;

	queue = new_queue(maze->nbr_rooms);
	maze->start->layer = 0;
	ft_enqueue(queue, maze->start);
	lst_of_valid_pass = new_stack(maze->nbr_rooms);
	while (!ft_queue_is_empty(queue))
	{
		current_room = ft_dequeue(queue);
		ft_add_to_current_pass(current_room, lst_of_valid_pass);
		if (current_room == maze->end)
		{
			if (ft_show_valid_stack(maze, current_room->prev_in_graph) > 0)
			{
				exit(0);
				while (ft_dequeue(queue))
					;
				ft_bfs(maze);
			}
		}
		else
			iter_through_destination(current_room, queue);
	}
	free(lst_of_valid_pass->array);
	free(lst_of_valid_pass);
	free(queue->array);
	free(queue);
}
