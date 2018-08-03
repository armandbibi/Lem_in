
#include "lemin_parse.h"

int	ft_is_command(char *str, t_maze *maze)
{
	(void)maze;
	if (*str == '#')
		return (1);
	else
		return (0);
}

int ft_is_nbr_ants(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

int ft_is_room(char *str, t_maze *maze, char **error, int token)
{
	(void) token;
	(void)maze;
	(void)error;
	while (*str == ' ')
		str++;
	while (*str && *str != ' ')
	{
		if (*str <= ' ' || *str == '#')
			return 0;
		str++;
	}
	if (!*str || *str != ' ')
		return (0);
	else
		str++;
	while (*str && *str != ' ')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	if (!*str || *str != ' ')
		return (0);
	else
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);

}
