#include "lem_in.h"

int	ft_is_command(t_instruction *instru)
{
	if (*instru->str == '#')
		return (1);
	else
		return (0);
}
