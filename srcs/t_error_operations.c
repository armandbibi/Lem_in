/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_errors_instructions.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/05 19:57:14 by abiestro          #+#    #+#             */
/*   Updated: 2018/09/05 20:03:26 by abiestro         ###   ########.fr       */
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
		print_fatal_error("malloc error");
	error->msg = malloc(sizeof(char) * ft_strlen(str));
	if (!error->msg)
		print_fatal_error("malloc error");
	error->level = level;
	return (error);
}
