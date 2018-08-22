/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tubes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:19:22 by abiestro          #+#    #+#             */
/*   Updated: 2018/08/22 21:23:22 by abiestro         ###   ########.fr       */
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
	while (*str > 32 && *str != '-')
		str++;
	if (*str !=  '-')
		return (0);
	while (*str && *str != ' ' && *str != '-')
		str++;
	if (*str)
		return (1);
	return (1);
}

void			ft_implement_tube(t_maze *maze, char *tube)
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
	
	int num_room;
	t_adj_lst s = -1;
	int d = -1;

	num_room = 0;
	while (num_room < maze->nbr_rooms)
	{
		if (!ft_strcmp(srcs,maze->tab_adj[num_room].name))
			s = maze->tab_adj[num_room].numero;
		if (!ft_strcmp(dest,maze->tab_adj[num_room].name))
			d = maze->tab_adj[num_room].numero;
		num_room++;
	}
	printf("%d %d\n", s, d);
	if (s  > 0 && d > 0)
		ft_add_lst_edge(maze->tab_adj, d, s);
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
			ft_add_error(tmp, "good tube");
			ft_implement_tube(maze, tmp->str);
		}
		tmp = tmp->next;
	}
	return (tmp);
}
