/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:16:53 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/03 15:56:14 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	draw_wall(void *mlx, void *win, int x_start, int y_start, int rgb)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < 60)
	{
		while (++x < 60)
			mlx_pixel_put(mlx, win, x_start + x, y_start + y, rgb);
		x = 0;
	}
}

void	draw_map(t_data *game)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = 0;
	y = 0;
	i = -1;
	j = -1;
	while (game->map[++i])
	{
		while (game->map[i][++j])
		{
			if (game->map[i][j] == '1')
				draw_wall(game->mlx, game->mlx_win, x, y,
					create_trgb(0, 50, 0, 60));
			if (game->map[i][j] == 'N')
				draw_wall(game->mlx, game->mlx_win, x, y,
					create_trgb(0, 255, 255, 0));
			x += 60;
		}
		j = -1;
		x = 0;
		y += 60;
	}
}
