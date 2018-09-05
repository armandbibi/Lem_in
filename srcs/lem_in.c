/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:16:24 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/05 20:31:41 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "graphic.h"

int	main(int ac, char **av)
{
	t_maze			maze;

	new_maze(&maze);
	ft_parse(&maze, ac, av);
	if (!ft_check_parameters(&maze))
		print_fatal_error("error\n");
	ft_show_instructs(&maze);	
	ft_bfs(&maze);
	show_adj_lst_tab(&maze, maze.tab_adj, maze.nbr_rooms);
	ft_del_maze(&maze);
}
