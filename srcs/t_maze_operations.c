/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_maze_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 21:58:53 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/03 18:32:24 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>
#include "libft.h"
#include <unistd.h>
#include <stdio.h>

void	ft_show_instructs(t_maze *maze)
{
	t_instruction	*tmp;

	if (!maze)
		print_fatal_error("maze is not allocated");
	tmp = maze->head;
	while (tmp)
	{
		write(1, tmp->str, ft_strlen(tmp->str));
		if (tmp->error != NULL)
		{
			write(1, "\033[0;31m <-- ", 12);
			write(1, tmp->error, ft_strlen(tmp->error));
			write(1, "\033[0m <-- ", 4);
		}
		write(1, "\n", 1);
		tmp = tmp->next;
	}
}

t_maze	*maze_append(t_maze *maze, char *str)
{
	t_instruction	*n_instru;

	if (!maze || !str)
		print_fatal_error("no maze for append");
	n_instru = malloc(sizeof(t_instruction));
	if (n_instru == NULL)
		print_fatal_error("malloc error");
	n_instru->str = str;
	n_instru->error = NULL;
	n_instru->next = NULL;
	n_instru->type = 0;
	if (maze->tail == NULL)
	{
		n_instru->prev = NULL;
		maze->head = n_instru;
		maze->tail = n_instru;
	}
	else
	{
		maze->tail->next = n_instru;
		n_instru->prev = maze->tail;
		maze->tail = n_instru;
		maze->length++;
	}
	return (NULL);
}

t_maze	*new_maze(t_maze *maze)
{
	maze->length = 0;
	maze->head = NULL;
	maze->tail = NULL;
	maze->have_start = 0;
	maze->have_end = 0;
	if (!(maze->good_ways = malloc(sizeof(t_stack *) * 10)))
		print_fatal_error("ERROR_MALLOC");
	maze->nbr_of_good_ways = 0;
	return (maze);
}

int		ft_turn_and_check(t_maze *maze, int *value)
{
	(void)maze;
	if (*value == 1)
		return (0);
	*value = 1;
	return (1);
}
