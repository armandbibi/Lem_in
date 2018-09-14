/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 20:25:44 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/14 13:28:12 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "lem_in.h"

void	ft_exit_properly(t_maze *maze, int error)
{
	ft_del_maze(maze);
	(void)maze;
	if (error)
		write(1, "error et cette sortie la\n", 30);
	exit(0);
}

t_maze	*ft_parse(t_maze *maze, int ac, char **av)
{
	(void)av;
	if (ac != 1)
		ft_exit_properly(maze, 1);
	if (maze->error != NULL)
		ft_exit_properly(maze, 1);
	if (ft_read_file(maze) == 0)
		ft_exit_properly(maze, 1);
	if (ft_parse_instructions(maze) == NULL)
		ft_exit_properly(maze, 1);
	if (!ft_check_parameters(maze))
		ft_exit_properly(maze, 1);
	return (maze);
}
