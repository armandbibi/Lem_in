/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 20:25:44 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/19 18:53:16 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "lem_in.h"
#include "libft.h"

void	ft_show_details(t_maze *maze)
{
	ft_putstr("\n\33[0;32m--extra--\33[0;0m\n");
	ft_putstr("\nnbr of comments:");
	ft_putnbr(maze->count_comments - 2);
	ft_putstr("\nnbr of rooms:");
	ft_putnbr(maze->nbr_rooms);
	ft_putstr("\nnbr of tubes:");
	ft_putnbr(maze->count_tubes);
	ft_putstr("\nnbr of solutions:");
	ft_putnbr(maze->nbr_of_good_ways);
	ft_putstr("\n");
	ft_putstr("\n\33[0;32m--solutions--\33[0;0m\n");
}

void	ft_exit_properly(t_maze *maze, int error)
{
	ft_del_maze(maze);
	(error) ? write(1, "error\n", 6) : 0;
	exit(0);
}

t_maze	*ft_parse(t_maze *maze, int ac, char **av)
{
	(void)ac;
	(void)av;
	if (maze->error != NULL)
		ft_exit_properly(maze, 1);
	if (ft_read_file(maze) == 0)
		ft_exit_properly(maze, 1);
	if (ft_parse_instructions(maze) == NULL)
		ft_exit_properly(maze, 1);
	if (!ft_check_parameters(maze))
		ft_exit_properly(maze, 1);
	return (maze);
}
