/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_errors_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 19:57:14 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/14 12:58:46 by abiestro         ###   ########.fr       */
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
		exit(0);
	error->msg = malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!error->msg)
		exit(0);
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
	t_error	*error;

	if (old_error && old_error->msg && old_error->level >= new_lvl)
		return (old_error);
	error = new_error(new_msg, new_lvl);
	ft_del_error(old_error);
	old_error = error;
	return (error);
}
