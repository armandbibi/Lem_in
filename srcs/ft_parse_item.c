
#include "lemin_parse.h"

int	ft_parse_nbr_ants(t_maze *maze, char *str)
{
	if (*str != '#')
		maze->nbr_ants = ft_atoi(str);
	return (1);
}
