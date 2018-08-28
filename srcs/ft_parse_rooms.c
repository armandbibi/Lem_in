#include "libft.h"
#include "lem_in.h"
#include <unistd.h>
int		ft_is_room(t_instruction *tmp)
{
	char *str;
	str = tmp-> str;
	if (!str)
		return 0;
	if (*str && *str > ' ') 
		str ++;
	else 
		return (0);
	while (*str && *str > ' ')
		str++;
	if (!*str || *str != ' ')
		return (0);
	else
		str++;
	if (!*str || *str < '0' || *str > '9')
		return 0;
	while (*str && *str >= '0' && *str <= '9')
		str++;
	if (!*str || *str != ' ')
		return (0);
	else
		str++;
	if (!*str || *str < '0' || *str > '9')
		return 0;
	while (*str && *str >= '0' && *str <= '9')
		str++;
	if (*str)
		return (0);
	else
		return (1);

}

t_instruction	*ft_parse_rooms(t_maze *maze, t_instruction *index)
{
	t_instruction *tmp;

	maze->nbr_rooms = 0;
	tmp = index;
	if (!index)
		print_fatal_error("not enougth instructions");
	while (tmp)
	{
		if (ft_is_tube(tmp))
			return (tmp);
		if (ft_is_room(tmp))
		{
			ft_add_error(tmp, "good room");
			if (!tmp->type)
				tmp->type = LM_ROOM;
			else if (tmp->type == LM_START)
				ft_add_error(tmp, "        start");
			else if (tmp->type == LM_END)
				ft_add_error(tmp, "        end");
			maze->nbr_rooms++;
		}
		else if (ft_is_command(tmp))
			;
		else
			ft_add_error(tmp, "Bad syntax");
		tmp = tmp->next;
		if (tmp && !ft_strcmp(tmp->str, "##start") && !ft_turn_and_check(maze, &maze->have_start))
			ft_add_error(tmp, "2 start!!!");
		else if (tmp && !ft_strcmp(tmp->str, "##end") && !ft_turn_and_check(maze, &maze->have_end))
			ft_add_error(tmp, "2 ends!!!");
	}
	return (tmp);
}
