/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:43:17 by triou             #+#    #+#             */
/*   Updated: 2018/09/19 18:10:56 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"
#include "lem_in.h"
#include <unistd.h>

int			ft_atoi(t_maze *maze, const char *nptr)
{
	int		sign;
	long	digit;

	sign = (*nptr == '-') ? -1 : 1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	digit = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		digit *= 10;
		digit += *nptr++ - '0';
	}
	if ((sign < 0 && -digit < INT_MIN) || (sign > 0 && digit > INT_MAX))
		ft_exit_properly(maze, 1);
	return (sign * digit);
}
