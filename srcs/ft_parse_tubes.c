/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tubes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:19:22 by abiestro          #+#    #+#             */
/*   Updated: 2018/08/23 19:27:04 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>
int				ft_is_tube(t_instruction *tmp)
{
	char *str;

	str = tmp->str;
	if (!str)
		return (0);
	while (*str &&*str > 32 && *str != '-')
		str++;
	if (!*str || *str !=  '-')
		return (0);
	while (*str)
		str++;
	if (*str)
		return (0);
	return (1);
}

int			ft_implement_tube(t_maze *maze, char *tube)
{
	char	*srcs;
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = 0;
	srcs = 0;
	dest = 0;
	while (tube[i] != '-')
		i++;
	srcs = malloc(sizeof(char) * i);
	while (tube[i + j])
		j++;
	dest = malloc(sizeof(char) * j);
	if (!srcs || !dest)
		print_fatal_error("malloc error");
	i = 0;
	j = 0;
	while (tube[i] != '-')
	{
		srcs[i] = tube[i];
		i++;
	}
	srcs[i] = 0;
	while (tube[i + j + 1] && j < 3)
	{
		dest[j] = tube[i + j + 1];
		j++;
	}
	dest[j] = 0;
	
	int enumi;
	t_adj_lst *s;
	t_adj_lst *d;

	s = NULL;
	d = NULL;
	enumi = 0;
	while (enumi < maze->nbr_rooms)
	{
		if (!ft_strcmp(maze->tab_adj[enumi].name,srcs))
			s = &maze->tab_adj[enumi];
		if (!ft_strcmp(maze->tab_adj[enumi].name,dest))
			d = &maze->tab_adj[enumi];
		enumi++;
	}
	if (s && d)
	{
		ft_add_lst_edge(maze->tab_adj, d, s);
		return (1);
	}
	else
		return (0);
}

t_instruction	*ft_parse_tubes(t_maze *maze, t_instruction *index)
{
	t_instruction	*tmp;

	tmp = index;
	if (!index)
		print_fatal_error("No tubes");
	while (tmp)
	{
		if (ft_is_tube(tmp))
		{
			if (ft_implement_tube(maze, tmp->str))
				ft_add_error(tmp, "good tube");
			else
				ft_add_error(tmp, "rooms'name aren't good");
		}
		tmp = tmp->next;
	}
	return (tmp);
}
