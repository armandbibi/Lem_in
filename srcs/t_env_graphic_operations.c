/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_env_graphic_operations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 18:10:12 by abiestro          #+#    #+#             */
/*   Updated: 2018/08/30 23:13:23 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphic.h"
#include "lem_in.h"
#include <stdlib.h>

int		deal_keys(int key, t_env_graphic *env)
{
	if (key)
	{
		mlx_destroy_window(env->mlx, env->win);
		exit(0);
	}
	return (0);
}

void	new_env_graphic(t_env_graphic *new_env)
{
	new_env = malloc(sizeof(*new_env));
	if (!new_env)
		print_fatal_error("malloc_error");
	new_env->mlx = mlx_init();
	new_env->win = mlx_new_window(new_env->mlx,
			LM_SCREEN_X, LM_SCREEN_Y, "LEM_IN");
	mlx_key_hook(new_env->win, deal_keys, new_env);
	mlx_loop(new_env->mlx);
}
