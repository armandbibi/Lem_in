/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_nbr_ants.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 23:32:18 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/17 15:14:53 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

int				ft_is_nbr_ants(t_instruction *c_instru)
{
	char *to_check;

	to_check = c_instru->str;
	while (*to_check)
	{
		if (*to_check < '0' || *to_check > '9')
			return (0);
		to_check++;
	}
	return (1);
}

t_instruction	*ft_parse_nbr_ants(t_maze *maze, t_instruction *instru)
{
	t_instruction	*tmp;

	tmp = instru;
	if (!tmp)
		return (NULL);
	while (tmp)
	{
		if (ft_is_nbr_ants(tmp))
		{
			maze->nbr_ants = ft_atoi(maze, tmp->str);
			if (maze->nbr_ants == 0)
				return (NULL);
			return (tmp->next);
		}
		else if (ft_strequ("##start", tmp->str) ||
				ft_strequ("##end", tmp->str) || *tmp->str == '#')
			tmp = tmp->next;
		else
			return (NULL);
	}
	return (tmp);
}
