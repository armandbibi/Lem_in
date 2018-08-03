
#include "lemin_parse.h"
#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	char	**msg_error;
	t_maze	maze;

	(void) ac;
	msg_error = ft_innit_error();
	if (ft_parse_file(av, &maze, msg_error) == 0)
	{
		ft_display_error(msg_error);
		exit(0);
	}
	ft_info_maze(&maze);
}
