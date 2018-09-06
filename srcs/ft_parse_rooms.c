/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_rooms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 23:18:33 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/06 17:28:59 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "lem_in.h"
#include <unistd.h>

int				ft_is_room2(char *str)
{
	if (!*str || *str != ' ')
		return (0);
	else
		str++;
	if (!*str || *str < '0' || *str > '9')
		return (0);
	while (*str && *str >= '0' && *str <= '9')
		str++;
	if (*str)
		return (0);
	else
		return (1);
}

int				ft_is_room(t_instruction *tmp)
{
	char *str;

	str = tmp->str;
	if (!str)
		return (0);
	if (*str && *str > ' ' && *str != '#' && *str != 'L')
		str++;
	else
		return (0);
	while (*str && *str > ' ')
		str++;
	if (!*str || *str != ' ')
		return (0);
	else
		str++;
	if (!*str || *str < '0' || *str > '9')
		return (0);
	while (*str && *str >= '0' && *str <= '9')
		str++;
	return (ft_is_room2(str));
}

t_instruction	*ft_parse_rooms(t_maze *maze, t_instruction *tmp)
{
	maze->nbr_rooms = 0;
	if (!tmp)
		exit(0);
	while (tmp)
	{
		if (ft_is_tube(tmp))
			return (tmp);
		if (ft_is_room(tmp))
			maze->nbr_rooms++;
		else if (ft_is_command(tmp))
			;
		else
			tmp->error = set_error(tmp->error, "Bad syntax", 2);
		if (tmp && !ft_strcmp(tmp->str, "##start") &&
				!ft_turn_and_check(maze, &maze->have_start))
			tmp->error = set_error(tmp->error, "2 start!!!", 1);
		else if (tmp && !ft_strcmp(tmp->str, "##end") &&
				!ft_turn_and_check(maze, &maze->have_end))
			tmp->error = set_error(tmp->error, "2 ends!!!", 1);
		tmp = tmp->next;
	}
	return (tmp);
}
