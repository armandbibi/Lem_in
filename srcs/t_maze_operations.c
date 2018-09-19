/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_maze_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 21:58:53 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/19 17:32:11 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>
#include "libft.h"
#include <unistd.h>
#include <stdio.h>

void	ft_write_verbosed(t_instruction *instru)
{
	if (instru->type == LM_START)
		write(1, "\33[0;31m ", 7);
	if (instru->type == LM_END)
		write(1, "\33[1;34m ", 7);
	else if (ft_is_command(instru))
		write(1, "\33[0;36m ", 7);
	ft_putstr(instru->str);
	write(1, "\33[0m ", 6);
}

void	ft_show_instructs(t_maze *maze, int verbose)
{
	t_instruction	*tmp;

	if (!maze)
		exit(0);
	tmp = maze->head;
	while (tmp && tmp->str)
	{
		if (!tmp->error)
		{
			if (!verbose)
				write(1, tmp->str, ft_strlen(tmp->str));
			else
				ft_write_verbosed(tmp);
		}
		if (tmp->error != NULL)
		{
			write(1, "\n", 1);
			return ;
		}
		write(1, "\n", 1);
		tmp = tmp->next;
	}
	write(1, "\n", 1);
}

t_maze	*maze_append(t_maze *maze, char *str)
{
	t_instruction	*n_instru;

	if (!maze || !str)
		exit(0);
	n_instru = malloc(sizeof(t_instruction));
	if (n_instru == NULL)
		exit(0);
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
	maze->start = 0;
	maze->end = 0;
	maze->have_end = 0;
	maze->have_start = 0;
	maze->error = NULL;
	maze->tab_adj = NULL;
	maze->count_comments = 0;
	maze->count_tubes = 0;
	if (!(maze->good_ways = malloc(sizeof(t_stack *) * 10)))
		exit(0);
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
