/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:16:24 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/12 16:49:07 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <unistd.h>
#include "graphic.h"

int	main(int ac, char **av)
{
	t_maze			maze;
	int				is_good;

	new_maze(&maze);
	ft_parse(&maze, ac, av);
	is_good = ft_bfs(&maze);
	if (is_good)
	{
		ft_show_instructs(&maze);
		show_the_passes(maze.good_ways);
	}
	else
		write(1, "no valid pass\n", ft_strlen("no valid pass\n"));
	ft_del_maze(&maze);
}
