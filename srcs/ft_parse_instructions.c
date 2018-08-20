#include "lem_in.h"
#include "get_next_line.h"

t_maze	*ft_parse_instructions(int fd)
{
	t_maze *maze;
	char	*line;

	maze = new_maze();
	while (get_next_line(fd, &line))
	{
		maze = maze_append(maze, line);
	}
	maze = ft_catch_errors_maze(maze);
	ft_show_instructs(maze);
	return (maze);
}
