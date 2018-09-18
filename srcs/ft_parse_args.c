/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 23:34:51 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/18 19:58:49 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>
#include "libft.h"

void	add_ant_to_table(int *tab, int size, int n)
{
	int i;

	i = size;
	while (--i > 0)
		tab[i] = tab[i - 1];
	tab[0] = n;
}

int		int_tab_is_empty(int *tab, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		if (tab[i])
			return (0);
		i++;
	}
	return (1);
}
