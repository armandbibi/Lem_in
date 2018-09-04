/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 16:16:24 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/03 22:53:08 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "graphic.h"

int	main(int ac, char **av)
{
	t_maze			maze;
//	t_env_graphic	env;

	new_maze(&maze);
//	new_env_graphic(&env);
	ft_parse_file(ac, av, &maze);
	ft_check_parameters(&maze);
	ft_bfs(&maze);
	show_adj_lst_tab(&maze, maze.tab_adj, maze.nbr_rooms);
	ft_del_maze(&maze);
}
