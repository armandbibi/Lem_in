/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 23:33:42 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/18 19:15:33 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "get_next_line.h"

t_maze	*ft_read_file(t_maze *maze)
{
	char	*line;
	int		read_return;
	int		nbr_line;

	nbr_line = 0;
	while ((read_return = get_next_line(STDIN_FILENO, &line)) > 0
			&& *line != 0)
	{
		maze_append(maze, line);
		nbr_line++;
	}
	free(line);
	if (read_return < 0)
		return (NULL);
	if (nbr_line < 6)
		return (NULL);
	return (maze);
}
