/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_parameters.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 22:48:32 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/03 22:55:49 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_check_parameters(t_maze *maze)
{
	if (!maze || !maze->head || !maze->start || !maze->end)
		print_fatal_error("error");
	return (1);
}
