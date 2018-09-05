/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 23:34:51 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/05 20:56:47 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdlib.h>
#include <fcntl.h>

void	print_fatal_error(char *str)
{
	printf("%s\n", str);
	exit(0);
}

int		ft_parse_arguments(int ac, char **av, t_maze *maze)
{
	int fd;

	fd = 0;
	if (ac < 2 )
		maze->error = new_error("no arguments", 3);
	else if (ac > 2)
		maze->error = new_error("too much arguments", 3);
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 1)
			print_fatal_error("bad_file_descriptor");
	}
	return (fd);
}
