/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_passes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:42:18 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/18 20:24:55 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

char	**stack_to_tab_tab(t_maze *maze, t_stack *stack, int **tab_of_ants)
{
	char		**lst_of_rooms;
	t_adj_lst	*room;
	int			i;
	int			*tabi;

	i = 0;
	lst_of_rooms = malloc(sizeof(char *) * (stack->size));
	tabi = malloc(sizeof(int) * (stack->size));
	if (!lst_of_rooms || !tab_of_ants)
		ft_exit_properly(maze, 1);
	ft_stack_pop(stack);
	while ((room = ft_stack_pop(stack)) && room->name)
	{
		tabi[i] = 0;
		lst_of_rooms[i++] = room->name;
	}
	lst_of_rooms[i] = NULL;
	tabi[i] = 0;
	*tab_of_ants = tabi;
	return (lst_of_rooms);
}

void	concat_room(char *str, int ant, char *room)
{
	int		i;
	char	tmp[20];

	i = 0;
	while (i < 20)
		tmp[i++] = 0;
	ft_strcat(str, "L");
	ft_strcat(str, ft_itoa((intmax_t)ant, tmp, 10));
	ft_strcat(str, "-");
	ft_strcat(str, room);
	ft_strcat(str, " ");
}

void	ft_print_current_state(char **tab_rooms, int *tab_ants, int size)
{
	int		i;
	char	str[800];

	i = 0;
	while (i < 800)
		str[i++] = 0;
	i = size;
	while (i > 0)
	{
		if (tab_ants[i - 1] && tab_rooms[i - 1])
			concat_room(str, tab_ants[i - 1], tab_rooms[i - 1]);
		i--;
	}
	ft_putstr(str);
}

void	show_the_passes(t_maze *maze)
{
	int		size[10];
	int		count_ants;
	char	**tab_rooms[10];
	int		*tab_ants[10];
	int		i;

	write(1, "\n", 1);
	i = 0;
	count_ants = 0;
	while (i < maze->nbr_of_good_ways)
	{
		size[i] = maze->good_ways[i]->size;
		tab_rooms[i] = stack_to_tab_tab(maze, maze->good_ways[i], &tab_ants[i]);
		i++;
	}
	i = 0;
	while (++count_ants <= (int)maze->nbr_ants)
	{
		add_ant_to_table(tab_ants[i], size[i], count_ants);
		ft_print_current_state(tab_rooms[i], tab_ants[i], size[i]);
		i = (i + 1) % maze->nbr_of_good_ways;
		if (i == 0)
			write(1, "\n", 1);
	}
	while (!int_tab_is_empty(tab_ants[i], size[i]))
	{
		add_ant_to_table(tab_ants[i], size[i], 0);
		ft_print_current_state(tab_rooms[i], tab_ants[i], size[i]);
		i = (i + 1) % maze->nbr_of_good_ways;
		if (i == 0)
			write(1, "\n", 1);
	}
	free(tab_rooms[0]);
	free(tab_ants[0]);
}
