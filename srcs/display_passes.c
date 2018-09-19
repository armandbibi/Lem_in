/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_passes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:42:18 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/19 19:28:46 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

char		**stack_to_tab_tab(t_maze *maze, t_stack *stack, int **tab_of_ants)
{
	char		**lst_of_rooms;
	t_adj_lst	*room;
	int			i;
	int			*tabi;

	i = 0;
	lst_of_rooms = malloc(sizeof(char *) * (stack->size));
	tabi = malloc(sizeof(int) * (stack->size));
	if (!lst_of_rooms || !tab_of_ants || !tabi)
		ft_exit_properly(maze, 1);
	ft_stack_pop(stack);
	while ((room = ft_stack_pop(stack)) && room->name)
	{
		tabi[i] = 0;
		lst_of_rooms[i++] = room->name;
		show_room(maze->length, room->name);
	}
	if (maze->length)
		ft_putstr("\n");
	lst_of_rooms[i] = NULL;
	tabi[i] = 0;
	*tab_of_ants = tabi;
	return (lst_of_rooms);
}

static void	concat_room(char *str, int ant, char *room)
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

static int	ft_print_current_state(char **tab_rooms, int *tab_ants, int size)
{
	int		i;
	char	str[800];

	if (*str == '\n')
	{
		*str = '0';
		return (0);
	}
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
	return (ft_strlen(str));
}

static void	ft_free_tables(char ***tab_rooms, int **tab_ants, int limit)
{
	int i;

	i = 0;
	while (i < limit)
	{
		free(tab_rooms[i]);
		free(tab_ants[i]);
		i++;
	}
}

void		show_the_passes(t_maze *maze)
{
	int		size[10];
	int		count_ants;
	char	**tab_rooms[10];
	int		*tab_ants[10];
	int		i;

	count_ants = 0;
	init_passes(maze, size, tab_rooms, tab_ants);
	if (maze->length)
		ft_putstr("\n\33[0;32m--details--\33[0;0m\n\n");
	i = 0;
	while (++count_ants <= (int)maze->nbr_ants)
	{
		add_ant_to_table(tab_ants[i], size[i], count_ants);
		ft_print_current_state(tab_rooms[i], tab_ants[i], size[i]);
		ft_modulo_i(&i, maze->nbr_of_good_ways);
	}
	while (!int_tab_is_empty(tab_ants, size, maze->nbr_of_good_ways))
	{
		add_ant_to_table(tab_ants[i], size[i], 0);
		ft_print_current_state(tab_rooms[i], tab_ants[i], size[i]);
		if (!int_tab_is_empty(tab_ants, size, maze->nbr_of_good_ways))
			ft_modulo_i(&i, maze->nbr_of_good_ways);
	}
	ft_free_tables(tab_rooms, tab_ants, maze->nbr_of_good_ways);
}
