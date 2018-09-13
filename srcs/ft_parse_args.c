/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 23:34:51 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/13 18:30:08 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>
#include <fcntl.h>

void	print_fatal_error(t_error *str)
{
	printf("%s\n", str->msg);
	exit(0);
}

int		ft_parse_arguments(int ac, char **av, t_maze *maze)
{
	(void)av;
	(void)maze;
	if (ac != 2)
		return (0);
	return (1);
}
