/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 23:34:51 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/19 16:01:05 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>
#include "libft.h"

void	ft_print_usage(void)
{
	ft_putstr("usage: ./lem_in [-multi -verbose]\n");
	exit(0);
}

void	ft_parse_args(int ac, char **av, int *multi, int *verbose)
{
	int i;
	int valid;

	i = 1;
	valid = 1;
	if (ac > 3)
		ft_print_usage();
	while (i < ac)
	{
		if (ft_strequ(av[i], "-multi"))
			*multi = 0;
		else if (ft_strequ(av[i], "-verbose"))
			*verbose = 1;
		else
			ft_print_usage();
		i++;
	}
}

void	add_ant_to_table(int *tab, int size, int n)
{
	int i;

	i = size;
	while (--i > 0)
		tab[i] = tab[i - 1];
	tab[0] = n;
}

int		int_tab_is_empty(int **tab, int *size, int limit)
{
	int i;
	int j;

	j = 0;
	while (j < limit)
	{
		i = 0;
		while (i < size[j])
		{
			if (tab[j][i])
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}
