/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 23:33:42 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/12 14:37:15 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "get_next_line.h"

t_maze	*ft_read_file(int fd, t_maze *maze)
{
	char	*line;
	int		read_return;
	int		nbr_line;

	nbr_line = 0;
	while ((read_return = get_next_line(fd, &line)) > 0)
	{
		maze_append(maze, line);
		nbr_line++;
	}
	if (read_return < 0)
	{
		maze->error = set_error(maze->error, "invalid read", 3);
		print_fatal_error(maze->error);
	}
	if (nbr_line < 6)
	{
		maze->error = set_error(maze->error, "invalid read", 3);
		print_fatal_error(maze->error);	
	}
	free(line);
	return (maze);
}
