/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tubes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:19:22 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/06 18:04:47 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>

int				ft_is_tube(t_instruction *tmp)
{
	char *str;

	str = tmp->str;
	if (!str || *str == '#' || *str == 'L')
		return (0);
	while (*str && *str > 32 && *str != '-')
		str++;
	if (!*str || *str != '-')
		return (0);
	while (*str)
		str++;
	if (*str)
		return (0);
	return (1);
}

void			set_srcs_and_dest(char *tube, char **s, char **d)
{
	int		i;
	int		j;
	char	*srcs;
	char	*dest;

	i = 0;
	j = 0;
	while (tube[i] && tube[i] != '-')
		i++;
	while (tube[i + j])
		j++;
	srcs = (char *)malloc(sizeof(char) * i + 1);
	dest = (char *)malloc(sizeof(char) * j + 1);
	if (!srcs || !dest)
		print_fatal_error(new_error("malloc error", 3));
	i = -1;
	j = 0;
	while (tube[++i] != '-')
		srcs[i] = tube[i];
	while (tube[i + ++j])
		dest[j - 1] = tube[i + j];
	srcs[i] = 0;
	dest[j - 1] = 0;
	*s = srcs;
	*d = dest;
}

int				ft_implement_tube(t_maze *maze, char *tube)
{
	char		*srcs;
	char		*dest;
	t_adj_lst	*s;
	t_adj_lst	*d;
	int			enumi;

	s = NULL;
	d = NULL;
	enumi = -1;
	set_srcs_and_dest(tube, &srcs, &dest);
	while (++enumi < maze->nbr_rooms)
	{
		if (ft_strequ(maze->tab_adj[enumi].name, srcs))
			s = &maze->tab_adj[enumi];
		if (ft_strequ(maze->tab_adj[enumi].name, dest))
			d = &maze->tab_adj[enumi];
	}
	free(srcs);
	free(dest);
	if (s && d)
	{
		ft_add_lst_edge(maze->tab_adj, d, s);
		return (1);
	}
	return (0);
}

t_instruction	*ft_parse_tubes(t_maze *maze, t_instruction *index)
{
	t_instruction	*tmp;

	tmp = index;
	while (tmp)
	{
		if (ft_is_tube(tmp))
		{
			if (ft_implement_tube(maze, tmp->str))
				;
			else
			{
					tmp->error = set_error(tmp->error, "rooms'name aren't good", 2);
					return (tmp);
			}
		}
		else if (!ft_is_command(tmp))
			tmp->error = set_error(tmp->error, "not a good tube", 2);
		tmp = tmp->next;
	}
	return (tmp);
}
