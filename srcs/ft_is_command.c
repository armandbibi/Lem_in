/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 17:32:17 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/03 22:59:30 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

int	ft_is_command(t_instruction *instru)
{
	if (!*instru->str)
		return (0);
	if (!ft_strcmp(instru->str, "##start"))
	{
		instru = instru->next;
		while (instru && !(ft_is_room(instru)))
			instru = instru->next;
		instru->type = LM_START;
		return (1);
	}
	else if (!ft_strcmp(instru->str, "##end"))
	{
		instru = instru->next;
		while (instru && *instru->str == '#' && !(ft_is_room(instru)))
			instru = instru->next;
		instru->type = LM_END;
		return (1);
	}
	if (*instru->str == '#')
		return (1);
	else
		return (0);
}
