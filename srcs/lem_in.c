/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:16:24 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/19 16:46:44 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <unistd.h>

int	main(int ac, char **av)
{
	t_maze			maze;
	int				is_good;
	int				speed;
	int				verbose;

	new_maze(&maze);
	speed = 1;
	verbose = 0;
	ft_parse_args(ac, av, &speed, &verbose);
	ft_parse(&maze, ac, av);
	is_good = ft_bfs(&maze, speed);
	if (is_good)
	{
		ft_show_instructs(&maze, verbose);
		if (verbose)
			ft_show_details(&maze);
		maze.length = (size_t)verbose;
		show_the_passes(&maze);
	}
	else
		write(1, "no valid pass\n", ft_strlen("no valid pass\n"));
	ft_del_maze(&maze);
}
