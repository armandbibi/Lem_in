#include "lem_in.h"

int		ft_is_room(t_instruction *tmp)
{
	char *str;

	str = tmp-> str;
	//check if exist
	if (!str)
		return 0;
	//check for name at least 1 char
	if (*str && *str > ' ') 
		str ++;
	else 
		return (0);
	while (*str && *str > ' ')
		str++;
	//check for first space
	if (!*str || *str != ' ')
		return (0);
	else
		str++;
	// check for first coord
	if (!*str || *str < '0' || *str > '9')
		return 0;
	while (*str && *str >= '0' && *str <= '9')
		str++;
	//check for second space
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
	else return (1);

}

t_instruction	*ft_parse_rooms(t_maze *maze, t_instruction *index)
{
	t_instruction *tmp;
	(void) maze;

	tmp = index;
	if (!index)
		print_fatal_error("not enougth instructions");
	while (tmp)
	{
		if (ft_is_room(tmp))
		{
			ft_add_error(tmp, "good room");
			tmp = tmp->next;
			ft_add_room(maze, tmp);
		}
		else if (ft_is_command(tmp))
				tmp = tmp->next;
		else
		{
			ft_add_error(tmp, "no handled");
			tmp = tmp->next;
		}
	}
	return (tmp);
}
