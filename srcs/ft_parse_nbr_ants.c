/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_nbr_ants.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 23:32:18 by abiestro          #+#    #+#             */
/*   Updated: 2018/08/30 23:32:37 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
		print_fatal_error("not enougth instructions");
	while (tmp)
	{
		if (ft_is_nbr_ants(tmp))
		{
			maze->nbr_ants = ft_atoi(tmp->str);
			return (tmp->next);
		}
		else if (ft_is_command(tmp))
			tmp = tmp->next;
		else
		{
			tmp = ft_add_error(tmp, "no valide count of ants");
			return (tmp);
		}
	}
	return (tmp);
}
