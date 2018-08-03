
#include "lemin_parse.h"
#include "get_next_line.h"
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>

static char	**ft_init_instructs(char **instructs, char *str)
{
	instructs = malloc(sizeof(char *) * 2);
	if (!instructs)
		exit(-1);
	instructs[0] = str;
	instructs[1] = 0;
	return (instructs);
}

static char	**ft_add_maze_description(char **instructs, char *str)
{
	char **new_instructs;
	int i;

	i = 0;
	if (!instructs)
		return (ft_init_instructs(instructs, str));
	while (instructs[i])
		i++;
	new_instructs = malloc(sizeof(char **) * (i + 3));
	if (!new_instructs)
		exit(-1);
	i = 0;
	while (instructs[i])
	{
		new_instructs[i] = instructs[i];
		i++;
	}
	new_instructs[i] = str;
	new_instructs[i + 1] = NULL;
	free(instructs);
	return (new_instructs);
	
}

static void	ft_display_instructions(char **str)
{
	char	**tmp;

	tmp = str;
	while (*tmp)
	{
		write(1, *tmp, ft_strlen(*tmp));
		write(1, "\n", 1);
		tmp++;
	}
}

int		ft_parse_file(char **av, t_maze *maze, char **error)
{
	int	fd;
	char	*str;
	char	**tab_instructs;
	int	token;

	tab_instructs = NULL;
	token = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		ft_add_error(error, errno);
		return (0);
	}
	while (get_next_line(fd, &str) > 0 && (ft_is_command(str, maze) || ft_is_nbr_ants(str)))
	{
		tab_instructs = ft_add_maze_description(tab_instructs, str);
		ft_parse_nbr_ants(maze, str);
	}
	while (get_next_line(fd, &str) && (ft_is_command(str, maze) || ft_is_room(str, maze,error, token)))
	{
		tab_instructs = ft_add_maze_description(tab_instructs, str);
//		ft_parse_rooms(maze, error, str, fd);
	}
/*	while (get_next_line(fd, str) && ft_add_maze_description)
		ft_parse_tubes(maze, error, str);
*/	ft_display_instructions(tab_instructs);
	return (1);
}
