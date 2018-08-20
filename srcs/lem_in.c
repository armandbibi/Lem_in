#include "lem_in.h"

int	main(int ac, char **av)
{
	t_maze	*maze;
	(void) ac;
	maze = ft_parse_file(ac, av);
	(void)maze;
}
