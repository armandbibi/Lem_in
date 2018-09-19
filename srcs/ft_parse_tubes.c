/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tubes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:19:22 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/19 17:37:50 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

int				ft_is_tube(t_instruction *tmp)
{
	char *str;

	str = tmp->str;
	if (!str || !*str || *str == '#' || *str == 'L' || ft_strequ(str, " "))
		return (0);
	while (*str && *str > 32 && *str != '-')
		str++;
	if (!*str || *str != '-')
		return (0);
	str++;
	while (*str && *str != '-' && *str != ' ')
		str++;
	if (*str)
		return (0);
	return (1);
}

static void		set_srcs_and_dest(t_maze *maze, char *tube, char **s, char **d)
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
		ft_exit_properly(maze, 1);
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

static int		ft_implement_tube(t_maze *maze, char *tube)
{
	char		*srcs;
	char		*dest;
	t_adj_lst	*s;
	t_adj_lst	*d;
	int			enumi;

	s = NULL;
	d = NULL;
	enumi = -1;
	set_srcs_and_dest(maze, tube, &srcs, &dest);
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

t_instruction	*set_error_tube(t_instruction *tmp)
{
	tmp->error = set_error(tmp->error, "error", 2);
	return (tmp);
}

t_instruction	*ft_parse_tubes(t_maze *maze, t_instruction *index)
{
	t_instruction	*tmp;

	tmp = index;
	while (tmp)
	{
		if (ft_is_command(tmp))
		{
			maze->count_comments++;
			tmp = tmp->next;
		}
		else if (ft_is_tube(tmp))
		{
			maze->count_tubes++;
			if (ft_implement_tube(maze, tmp->str))
				;
			else
				return (set_error_tube(tmp));
			tmp = tmp->next;
		}
		else
			return (set_error_tube(tmp));
	}
	return (tmp);
}
