/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/29 22:00:23 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/19 15:44:10 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static int		is_layer_attribuate(
				t_maze *maze, t_adj_lst *room, t_adj_node *node, int shorter)
{
	if (!room || !node)
		ft_exit_properly(maze, 1);
	return ((node->dest->layer - shorter < room->layer)
			|| node->dest->belong_to_pass);
}

int				ft_show_valid_stack(t_maze *maze, t_adj_lst *room_before_end)
{
	t_adj_lst	*current_room;
	int			size;

	ft_putstr("\n\n");
	current_room = room_before_end;
	size = 0;
	ft_putstr(maze->end->name);
	while (current_room->prev_in_graph)
	{
		ft_putstr(current_room->name);
		current_room->belong_to_pass = 1;
		current_room = current_room->prev_in_graph;
		size++;
	}
	ft_putstr(maze->start->name);
	ft_putstr("\n\n");
	return (size);
}

static int		ft_add_good_way(t_maze *maze, t_adj_lst *room_before_end)
{
	t_adj_lst	*room;
	int			size;
	t_stack		*stock;

	room = room_before_end;
	size = 0;
	stock = new_stack(room->layer + 2);
	ft_stack_push(stock, maze->end);
	while (room->prev_in_graph)
	{
		ft_stack_push(stock, room);
		room->belong_to_pass = 1;
		room = room->prev_in_graph;
		size++;
	}
	ft_stack_push(stock, maze->start);
	maze->good_ways[maze->nbr_of_good_ways++] = stock;
	return (size);
}

static void		iter_through_destination(t_maze *maze, t_adj_lst *current_room,
				t_queue *queue, int shorter)
{
	t_adj_node	*current_node;

	current_node = current_room->head;
	while (current_node != NULL)
	{
		if (!is_layer_attribuate(maze, current_room, current_node, shorter))
		{
			current_node->dest->layer = current_room->layer + 1;
			current_node->dest->prev_in_graph = current_room;
			ft_enqueue(queue, current_node->dest);
		}
		current_node = current_node->next;
	}
}

int				ft_bfs(t_maze *maze, int shorter)
{
	t_queue		*queue;
	t_adj_lst	*current_room;

	queue = new_queue(maze->nbr_rooms);
	maze->start->layer = 0;
	ft_enqueue(queue, maze->start);
	while (!ft_queue_is_empty(queue))
	{
		current_room = ft_dequeue(queue);
		if (current_room == maze->end)
		{
			if (ft_add_good_way(maze, current_room->prev_in_graph) && !shorter)
				ft_bfs(maze, shorter);
			ft_del_queue(queue);
			return (1);
		}
		else
			iter_through_destination(maze, current_room, queue, shorter);
	}
	ft_del_queue(queue);
	return (0);
}
