/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_errors_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 19:57:14 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/06 15:58:49 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"
#include <stdlib.h>

t_error		*new_error(char *str, int level)
{
	t_error	*error;

	error = malloc(sizeof(t_error));
	if (!error)
		print_fatal_error(new_error("malloc error", 3));
	error->msg = malloc(sizeof(char) * ft_strlen(str + 1));
	if (!error->msg)
		print_fatal_error(new_error("malloc error", 3));
	ft_strcpy(error->msg, str);
	error->level = level;
	return (error);
}

void		ft_del_error(t_error *error)
{
	if (error && error->msg)
	{
		free(error->msg);
		free(error);
		error = NULL;
	}
}

t_error		*set_error(t_error *old_error, char *new_msg, int new_lvl)
{
	t_error	*_new_error;

	if (old_error && old_error->msg && old_error->level >= new_lvl)
		return (old_error);
	_new_error = new_error(new_msg, new_lvl);
   ft_del_error(old_error);
   old_error = _new_error;
   return (_new_error);
}
