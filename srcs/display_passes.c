/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_passes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 18:42:18 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/17 20:25:32 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

char	**stack_to_tab_tab(t_stack *stack)
{
	char		**lst_of_rooms;
	t_adj_lst	*room;
	int			i;

	i = 0;
	lst_of_rooms = malloc(sizeof(char *) * (stack->size + 1));
	while ((room = ft_stack_pop(stack)) && room->name)
	{
		lst_of_rooms[i++] = room->name;
		printf("%s ", room->name);
	}
	printf("\n");
	lst_of_rooms[i] = NULL;
	return (lst_of_rooms);
}

void	concat_room(char *str, int ant, char *room)
{
	char tmp[20];

	ft_strcat(str, "L");
	ft_strcat(str, ft_itoa((intmax_t)ant + 1, tmp, 10));
	ft_strcat(str, "-");
	ft_strcat(str, room);
	ft_strcat(str, " ");
}

void	ft_show_current_state(t_maze *maze, char **tab_of_rooms, int *ants_in_maze)
{
	char	str[500];
	int		i;
	int		j;

	j = *ants_in_maze - 1;
	i = 0;
	while (i < 500)
		str[i++] = 0;
	i = 0;
	while (maze->nbr_ants > 0 && j && tab_of_rooms[i] && *ants_in_maze > i)
		concat_room(str, j--, tab_of_rooms[i++]);
	if (tab_of_rooms[i])
		concat_room(str, j, tab_of_rooms[i]);
	++*ants_in_maze;
	maze->nbr_ants--;
	ft_strcat(str,"\n");
	write(1, str, ft_strlen(str));
}

void	ft_show_last_state(char **tab_of_rooms, int *ants_in_maze, int iterator, int k)
{
	int		j;
	char	str[500];
	int		i;

	i = *ants_in_maze - 1;
	j = 0;
	while (j < 500)
		str[j++] = 0;
	j = k;
	while (j > iterator)
		concat_room(str, j, tab_of_rooms[i]);
	ft_strcat(str,"\n");
	write(1, str, ft_strlen(str));
}

void	show_the_passes(t_maze *maze)
{
	char	**tab_of_rooms;
	int 	ants_in_maze;
	int		ants_at_start;
	int		iterator;		
	int		k;

	ants_at_start = maze->nbr_ants;
	iterator = maze->good_ways[0]->size;
	k = iterator;
	write(1, "\n", 1);
	ants_in_maze = 1;
	tab_of_rooms = stack_to_tab_tab(maze->good_ways[0]);
	while (maze->nbr_ants)
		ft_show_current_state(maze, tab_of_rooms, &ants_in_maze);
	while (iterator--)
		ft_show_last_state(tab_of_rooms, &ants_in_maze, iterator, k);
}
