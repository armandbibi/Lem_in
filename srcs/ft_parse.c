/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 20:25:44 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/13 20:29:36 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "lem_in.h"

void	ft_exit_properly(t_maze *maze, int error)
{
	ft_del_maze(maze);
	if (error)
		write(1, "error\n", 6);
	exit(0);
}

t_maze	*ft_parse(t_maze *maze, int ac, char **av)
{
	int fd;
	int error;

	error = 0;
	fd = ft_parse_arguments(ac, av, maze);
	if (maze->error != NULL)
		ft_exit_properly(maze, 1);
	if (ft_read_file(fd, maze) == 0)
		ft_exit_properly(maze, 1);
	if (ft_parse_instructions(maze) == NULL)
		ft_exit_properly(maze, 1);
	if (!ft_check_parameters(maze))
		ft_exit_properly(maze, 1);
	return (maze);
}
