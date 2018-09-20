/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_queue_operations2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 13:15:25 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/20 13:29:03 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

t_adj_lst	*ft_queue_front(t_queue *queue)
{
	if (queue->size == 0)
		return (NULL);
	return (queue->array[queue->front]);
}

void		ft_del_queue(t_queue *queue)
{
	free(queue->array);
	free(queue);
}
