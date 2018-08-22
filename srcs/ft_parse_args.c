#include "lem_in.h"
#include <stdlib.h>
#include <fcntl.h>

void	print_fatal_error(char *str)
{
	printf("%s", str);
	exit(0);
}

t_maze	*ft_parse_file(int ac, char **av, t_maze *maze)
{
	int fd;

	if (ac <= 1)
		print_fatal_error("no arguments");
	fd = open(av[1], O_RDONLY);
	if (fd < 1)
		print_fatal_error("bad_file_descriptor");
	ft_parse_instructions(fd, maze);
	return (maze);
}
