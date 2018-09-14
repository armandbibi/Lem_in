/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_command.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 17:32:17 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/14 12:52:09 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

static int		command_have_error(t_instruction *instru)
{
	char *command;

	command = instru->str;
	instru = instru->next;
	while (instru && !(ft_is_room(instru)) && !ft_is_tube(instru))
		instru = instru->next;
	if (!ft_is_room(instru))
	{
		instru->error = set_error(instru->error,
				"command with no rooms after", 3);
		return (0);
	}
	if (ft_strequ(command, "##start"))
		instru->type = LM_START;
	if (ft_strequ(command, "##end"))
		instru->type = LM_END;
	return (1);
}

int				ft_is_command(t_instruction *instru)
{
	if (!*instru->str)
		return (0);
	if (ft_strequ(instru->str, "##start") ||
		ft_strequ(instru->str, "##end"))
		return (command_have_error(instru));
	else if (*instru->str == '#')
		return (1);
	else
		return (0);
}
