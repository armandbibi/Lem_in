/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abiestro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/28 18:01:00 by abiestro          #+#    #+#             */
/*   Updated: 2018/08/28 20:05:38 by abiestro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_C
# define GRAPHIC_C
# include "lem_in.h"
# include "mlx.h"

# define LM_SCREEN_X 1000
# define LM_SCREEN_Y 700

typedef struct		s_env_graphic
{
	void			*mlx;
	void			*win;
	void			*img;
	t_maze			*maze;
}					t_env_graphic;

void				new_env_graphic(t_env_graphic *env);

#endif
