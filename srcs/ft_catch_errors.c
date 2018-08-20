#include "lem_in.h"


t_maze	*ft_catch_errors_maze(t_maze *maze)
{
	t_instruction *index;

	index = maze->head;
	index = ft_parse_nbr_ants(maze, index);
	index = ft_parse_rooms(maze, index);
//	index = parse_tubes(index);
	return (maze);
}
