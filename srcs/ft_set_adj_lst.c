/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_adj_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 15:09:51 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/17 15:17:49 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <limits.h>

static int	ft_set_do_lst(t_adj_lst *lst, t_instruction *value, int numero)
{
	int		i;
	char	*name;

	i = 0;
	while (value->str[i] != ' ')
		i++;
	name = NULL;
	if (i < 1)
		return (0);
	name = malloc(sizeof(char) * i + 1);
	if (!name)
		return (0);
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
	return (1);
}

static int	check_twice_same_name(t_adj_lst *lst, int size_lst)
{
	int i;
	int j;

	i = 0;
	while (i < size_lst - 1)
	{
		j = i + 1;
		while (j <= size_lst - 1)
		{
			if (ft_strequ(lst[i].name, lst[j].name))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static void	ft_del_adj_tab(t_maze *maze, int nbr_room_created)
{
	int i;

	i = 0;
	while (i < nbr_room_created)
	{
		if (maze->tab_adj[i].name)
			free(maze->tab_adj[i].name);
		i++;
	}
	free(maze->tab_adj);
	maze->tab_adj = NULL;
}

int			ft_set_adj_lst(t_maze *maze, t_instruction *index)
{
	t_instruction	*reverse;
	int				i;

	reverse = index->prev;
	i = maze->nbr_rooms - 1;
	while (reverse && reverse != maze->head && i > -1)
	{
		if (ft_is_room(reverse))
		{
			if (!ft_set_do_lst(&maze->tab_adj[i], reverse, i))
				return (0);
			if (reverse->type == LM_START)
				maze->start = &maze->tab_adj[i];
			if (reverse->type == LM_END)
				maze->end = &maze->tab_adj[i];
			i--;
		}
		reverse = reverse->prev;
	}
	if (!check_twice_same_name(maze->tab_adj, maze->nbr_rooms))
	{
		ft_del_adj_tab(maze, maze->nbr_rooms);
		return (0);
	}
	return (1);
}
