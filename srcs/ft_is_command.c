/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 17:32:17 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/12 18:15:12 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

int	ft_is_command(t_instruction *instru)
{
	if (!*instru->str)
		return (0);
	if (ft_strequ(instru->str, "##start"))
	{
		instru = instru->next;
		while (instru && !(ft_is_room(instru)) && !ft_is_tube(instru))
			instru = instru->next;
		if (!ft_is_room(instru))
		{
			instru->error = (new_error("command with no rooms after", 3));
			return (0);
		}
		else
			instru->type = LM_START;
		return (1);
	}
	else if (ft_strequ(instru->str, "##end"))
	{
		instru = instru->next;
		while (instru && !(ft_is_room(instru)) && !ft_is_tube(instru))
			instru = instru->next;
		if (!ft_is_room(instru))
		{
			instru->error = (new_error("command with no rooms after", 3));
			return (0);
		}
		else
			instru->type = LM_END;
		return (1);
	}
	else if (*instru->str == '#')
		return (1);
	else
		return (0);
}
