/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: triou <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 13:43:17 by triou             #+#    #+#             */
/*   Updated: 2018/09/14 13:09:15 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"
#include <unistd.h>

int			ft_atoi(const char *nptr)
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
	{
		write(1, "error\n", ft_strlen("error\n"));
		exit(0);
	}
	return (sign * digit);
}
