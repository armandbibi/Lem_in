#include "lem_in.h"
#include "libft.h"

t_instruction	*ft_add_error(t_instruction *instru, char *str)
{
	if (instru->error)
		free(instru->error);
	instru->error = ft_strdup(str);
	return (instru);
}
