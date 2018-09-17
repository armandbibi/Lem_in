/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_stack_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 18:06:32 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/17 17:02:03 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>

t_stack		*new_stack(unsigned capacity)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		exit(0);
	new_stack->capacity = capacity;
	new_stack->top = -1;
	new_stack->size = 0;
	new_stack->array = (t_adj_lst **)malloc(sizeof(t_adj_lst *) * capacity);
	if (!new_stack->array)
		exit(0);
	return (new_stack);
}

void		ft_stack_push(t_stack *stack, t_adj_lst *item)
{
	if (stack->top == (int)stack->capacity - 1)
		return ;
	stack->array[++stack->top] = item;
	stack->size++;
}

t_adj_lst	*ft_stack_pop(t_stack *stack)
{
	if (stack->top == -1)
		return (NULL);
	return (stack->array[stack->top--]);
	stack->size--;
}

t_adj_lst	*ft_stack_see_top(t_stack *stack)
{
	if (!stack)
		exit(0);
	if (stack->top == -1)
		return (NULL);
	return (stack->array[stack->top]);
}

void		ft_del_stack(t_stack *stack)
{
	free(stack->array);
	free(stack);
	stack = NULL;
}
