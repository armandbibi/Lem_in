/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_nbr_ants.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 23:32:18 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/06 20:07:16 by abiestro         ###   ########.fr       */
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
		print_fatal_error(new_error("no index in ft_parse_nbr_ants", 2));
	while (tmp)
	{
		if (ft_is_nbr_ants(tmp))
		{
			maze->nbr_ants = ft_atoi(tmp->str);
			if (maze->nbr_ants == 0)
				print_fatal_error(new_error("no ants", 1));
			return (tmp->next);
		}
		else if (ft_is_command(tmp) && !ft_strcmp("##start", tmp->str), !ft_strcmp("##end", tmp->str) )
			tmp = tmp->next;
		else
		{
			tmp->error = set_error(tmp->error, "no valide count of ants", 2);
			print_fatal_error(tmp->error);
			return (tmp);
		}
	}
	return (tmp);
}
