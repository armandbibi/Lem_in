/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 20:25:44 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/06 16:11:09 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_maze	*ft_parse(t_maze *maze, int ac, char **av)
{
	int fd;

	fd = ft_parse_arguments(ac, av, maze);
	if (maze->error == NULL)
	{
		ft_read_file(fd, maze);
		ft_parse_instructions(maze);
		ft_check_parameters(maze);
	}
	return (maze);
}
