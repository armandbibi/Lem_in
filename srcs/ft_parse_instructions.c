/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_catch_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 19:26:23 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/13 18:48:45 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>
#include <limits.h>

t_maze	*ft_parse_instructions(t_maze *maze)
{
	t_instruction *index;

	index = maze->head;
	if (!index)
		return (NULL);
	index = ft_parse_nbr_ants(maze, index);
	if (!index)
		return (NULL);
	index = ft_parse_rooms(maze, index);
	if (!index || maze->nbr_rooms < 2)
		return (NULL);
	maze->tab_adj = new_tab_adj(maze->nbr_rooms);
	if (!(ft_set_adj_lst(maze, index)))
		return (NULL);
	if (!index)
		return (NULL);
	index = ft_parse_tubes(maze, index);
	return (maze);
}
