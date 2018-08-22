#include "lem_in.h"
#include "libft.h"

int	ft_is_command(t_instruction *instru)
{
	if (!ft_strcmp(instru->str, "##start"))
		instru->next->type = LM_START;
	if (!ft_strcmp(instru->str, "##end"))
		instru->next->type = LM_END;
	if (*instru->str == '#')
		return (1);
	else
		return (0);
}
