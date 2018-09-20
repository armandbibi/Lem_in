/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_queue_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 00:06:20 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/20 13:31:03 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>
#include <limits.h>

t_queue			*new_queue(unsigned capacity)
{
	t_queue	*new_queue;

	new_queue = (t_queue*)malloc(sizeof(t_queue));
	if (!new_queue)
		exit(0);
	new_queue->capacity = capacity;
	new_queue->front = 0;
	new_queue->rear = (int)capacity - 1;
	new_queue->size = 0;
	new_queue->array = (t_adj_lst **)malloc(sizeof(t_adj_lst *) * capacity);
	if (!new_queue->array)
		exit(0);
	return (new_queue);
}

int				ft_queue_is_full(t_queue *queue)
{
	return (queue->size == (int)queue->capacity);
}

int				ft_queue_is_empty(t_queue *queue)
{
	return (queue->size == 0);
}

void			ft_enqueue(t_queue *queue, t_adj_lst *item)
{
	if (queue->size == (int)queue->capacity)
		return ;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = item;
	queue->size = queue->size + 1;
}

t_adj_lst		*ft_dequeue(t_queue *queue)
{
	t_adj_lst	*item;

	if (queue->size == 0)
		return (NULL);
	item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size = queue->size - 1;
	return (item);
}
