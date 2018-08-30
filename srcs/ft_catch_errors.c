/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_catch_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 19:26:23 by abiestro          #+#    #+#             */
/*   Updated: 2018/08/30 23:35:43 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>
#include <limits.h>

void	ft_set_do_lst(t_adj_lst *lst, t_instruction *value, int numero)
{
	int		i;
	char	*name;

	i = 0;
	while (value->str[i] != ' ')
		i++;
	name = NULL;
	name = malloc(sizeof(char) * i + 1);
	if (!name)
		print_fatal_error("malloc error");
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
}

void	ft_set_adj_lst(t_maze *maze, t_instruction *index)
{
	t_instruction	*reverse;
	int				i;

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
}

t_maze	*ft_catch_errors_maze(t_maze *maze)
{
	t_instruction *index;

	index = maze->head;
	index = ft_parse_nbr_ants(maze, index);
	if (!index)
		print_fatal_error("imcomplete maze: no rooms");
	index = ft_parse_rooms(maze, index);
	if (!index)
		print_fatal_error("imcomplete maze: no tubes");
	maze->tab_adj = new_tab_adj(maze->nbr_rooms);
	if (!index)
		print_fatal_error("imcomplete maze");
	ft_set_adj_lst(maze, index);
	if (!index)
		print_fatal_error("imcomplete maze");
	index = ft_parse_tubes(maze, index);
	return (maze);
}
