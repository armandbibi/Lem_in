/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_tubes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:19:22 by abiestro          #+#    #+#             */
/*   Updated: 2018/08/28 17:31:53 by abiestro         ###   ########.fr       */
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

void		set_srcs_and_dest(char *tube, char **s, char **d)
{
	int i;
	int j;
	char *srcs;
	char *dest;

	i = 0;
	j = 0;
	while (tube[i] && tube[i] != '-')
		i++;
	while (tube[i + j])
		j++;
	srcs = malloc(sizeof(char) * i);
	dest = malloc(sizeof(char) * j);
	if (!srcs || !dest)
		print_fatal_error("mallco error");
	i = -1;
	j = 0;
	while (tube[++i] != '-')
		srcs[i] = tube[i];
	while (tube[i + ++j])
		dest[j - 1] = tube[i + j];
	srcs[i] = 0;
	dest[j] = 0;
	*s = srcs;
	*d = dest;
}
#include <unistd.h>
int			ft_implement_tube(t_maze *maze, char *tube)
{
	char	*srcs;
	char	*dest;

	srcs = 0;
	dest = 0;
	set_srcs_and_dest(tube, &srcs, &dest);	
printf("s = %s, d = %s\n", srcs, dest);
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
	free(srcs);
	free(dest);
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
