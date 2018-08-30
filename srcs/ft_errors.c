/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/30 23:35:11 by abiestro          #+#    #+#             */
/*   Updated: 2018/08/30 23:35:13 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include "libft.h"

t_instruction	*ft_add_error(t_instruction *instru, char *str)
{
	if (instru->error)
		free(instru->error);
	instru->error = ft_strdup(str);
	return (instru);
}
