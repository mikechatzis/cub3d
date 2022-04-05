/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:12:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/04 17:50:08 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	face_direction(t_data *game)
{
	int		y;
	short	i;

	y = game->ppos_y - 30;
	i = 0;
	while (i++ < 60)
		mlx_pixel_put(game->mlx, game->mlx_win, game->ppos_x + 30,
			y++, create_trgb(0, 0, 100, 0));
}
