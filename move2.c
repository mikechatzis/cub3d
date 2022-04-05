/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:12:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/05 15:12:32 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	face_direction(t_data *game)
{
	int		y;
	short	i;
	int		x;

	y = game->ppos_y;
	x = game->ppos_x;
	i = 0;
	while (i++ < 60)
	{
		mlx_pixel_put(game->mlx, game->mlx_win, x + game->dirX * i,
			y + game->dirY * i, create_trgb(0, 0, 100, 0));
	}
}
