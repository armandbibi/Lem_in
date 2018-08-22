#include "lem_in.h"
#include "get_next_line.h"

t_maze	*ft_parse_instructions(int fd, t_maze *maze)
{
	char	*line;

	while (get_next_line(fd, &line))
	{
		maze_append(maze, line);
	}
	free(line);
	ft_catch_errors_maze(maze);
	ft_show_instructs(maze);
	show_adj_lst_tab(maze->tab_adj, maze->nbr_rooms);
	return (maze);
}
