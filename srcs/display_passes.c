/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_passes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:42:18 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/12 19:00:00 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void            show_the_passes(t_stack **lst_of_good_pass)
{
	t_stack     *s;
	t_adj_lst   *room;

	s = *lst_of_good_pass;
	if (!ft_stack_see_top(s))
		print_fatal_error(new_error ("no pass", 3));
	printf("\n");
	while ((room = ft_stack_pop(s)))
		printf("%s\n", room->name);
}

void			show_valid_stack(t_maze *maze)
{
	int		effective_lines;

	effective_lines = ft_stack_see_top(*maze->good_ways)->layer
		/ maze->nbr_of_good_ways;
}