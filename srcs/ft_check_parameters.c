/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parameters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 22:48:32 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/04 15:12:43 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_check_parameters(t_maze *maze)
{
	t_instruction	*instru;

	instru = maze->head;
	if (!maze || !maze->head || !maze->start || !maze->end)
		return (0);
	while (instru)
	{
		if (instru->error)
			print_fatal_error(instru->error);
		instru =instru->next;
	}
	return (1);
}
