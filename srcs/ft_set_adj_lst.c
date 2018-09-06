/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_adj_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 15:09:51 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/06 18:03:58 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>
#include "libft.h"
#include <limits.h>

void    ft_set_do_lst(t_adj_lst *lst, t_instruction *value, int numero)
{
	int     i;
	char    *name;

	i = 0;
	while (value->str[i] != ' ')
		i++;
	name = NULL;
	name = malloc(sizeof(char) * i + 1);
	if (!name)
		print_fatal_error(new_error("malloc error", 3));
	i = 0;
	while (value->str[i] != ' ')
	{
		name[i] = value->str[i];
		i++;
	}
	name[i] = 0;
	lst->name = name;
	lst->numero = numero;
	lst->layer = INT_MAX;
	lst->belong_to_pass = 0;
	lst->prev_in_graph = NULL;
}

void	check_twice_same_name(t_adj_lst *lst, int size_lst)
{
	int i;
	int j;

	i = 0;
	while (i < size_lst - 1)
	{
		j = i + 1;
		while (j <=size_lst - 1)
		{
			if (ft_strequ(lst[i].name, lst[j].name))
				print_fatal_error(new_error("error", 3));
			j++;
		}
		i++;
	}
}

void    ft_set_adj_lst(t_maze *maze, t_instruction *index)
{
	t_instruction   *reverse;
	int             i;

	reverse = index->prev;
	i = maze->nbr_rooms - 1;
	while (reverse && reverse != maze->head && i > -1)
	{
		if (ft_is_room(reverse))
		{
			ft_set_do_lst(&maze->tab_adj[i], reverse, i);
			if (reverse->type == LM_START)
				maze->start = &maze->tab_adj[i];
			if (reverse->type == LM_END)
				maze->end = &maze->tab_adj[i];
			i--;
		}
		reverse = reverse->prev;
	}
	check_twice_same_name(maze->tab_adj, maze->nbr_rooms);
}