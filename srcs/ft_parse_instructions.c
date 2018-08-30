/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 23:33:42 by abiestro          #+#    #+#             */
/*   Updated: 2018/08/30 23:33:44 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "get_next_line.h"

t_maze	*ft_parse_instructions(int fd, t_maze *maze)
{
	char	*line;

	while (get_next_line(fd, &line))
	{
		maze_append(maze, line);
	}
	free(line);
	ft_catch_errors_maze(maze);
	ft_show_instructs(maze);
	return (maze);
}
