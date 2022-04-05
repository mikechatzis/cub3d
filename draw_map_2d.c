/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:16:53 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/05 17:00:25 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	draw_character(t_data *game, int rgb)
{
	int	x;
	int	y;

	x = -10;
	y = -10;
	while (++y < 10)
		mlx_pixel_put(game->mlx, game->mlx_win,
			game->ppos_x, game->ppos_y + y, rgb);
	while (++x < 10)
		mlx_pixel_put(game->mlx, game->mlx_win,
			game->ppos_x + x, game->ppos_y, rgb);
}

void	draw_wall(t_data *game, int x_start, int y_start, int rgb)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < 60)
	{
		while (++x < 60)
			mlx_pixel_put(game->mlx, game->mlx_win,
				x_start + x, y_start + y, rgb);
		x = 0;
	}
}

void	draw_map2(t_data *game, int x, int y)
{
	game->ppos_x = x;
	game->ppos_y = y;
	draw_character(game, 155);
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
				draw_wall(game, x, y, create_trgb(0, 50, 0, 60));
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S' ||
				game->map[i][j] == 'W' || game->map[i][j] == 'E')
				draw_map2(game, x, y);
			x += 60;
		}
		j = -1;
		x = 0;
		y += 60;
	}
}
