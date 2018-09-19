/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_passes2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 17:38:23 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/19 17:44:24 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <unistd.h>

void	show_room(int i, char *str)
{
	if (i)
	{
		ft_putstr(str);
		ft_putstr(" ");
	}
}

void	ft_modulo_i(int *i, int modulo)
{
	*i = (*i + 1) % modulo;
	if (*i == 0)
		write(1, "\n", 1);
}

void	init_passes(t_maze *maze, int *size, char ***rooms, int **ants)
{
	int i;

	i = 0;
	while (i < maze->nbr_of_good_ways)
	{
		size[i] = maze->good_ways[i]->size;
		rooms[i] = stack_to_tab_tab(maze, maze->good_ways[i], &ants[i]);
		i++;
	}
}
