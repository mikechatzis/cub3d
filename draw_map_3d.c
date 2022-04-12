/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:15:10 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/12 20:35:44 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	find_player(t_data *game, int x, int y)
{
	game->ppos_x = x + 0.5;
	game->ppos_y = y + 0.5;
}

void	draw_3dmap(t_data *game, t_ray *ray, int x)
{
	int	lineheight;
	int	linestart;
	int	lineend;
	int	y;

	lineheight = SCREEN_H / ray->perpwalldist;
	linestart = -lineheight / 2 + SCREEN_H / 2;
	if (linestart < 0)
		linestart = 0;
	if (lineheight > SCREEN_H)
		lineheight = SCREEN_H;
	y = -1;
	// x * 8 in mlx_pixel_put FOR FASTER RAYCAST
	while (++y <= linestart)
		my_mlx_pixel_put(game, x,
			y, create_trgb(0, game->colors[3],
				game->colors[4], game->colors[5]));
	y = -1;
	while (++y < lineheight)
		my_mlx_pixel_put(game, x,
			y + linestart, create_trgb(0, 0, 0, 0));
	y -= 1;
	while (++y < SCREEN_H - linestart)
		my_mlx_pixel_put(game, x,
			y + linestart, create_trgb(0, game->colors[0],
				game->colors[1], game->colors[2]));
	mlx_put_image_to_window(game->mlx_win,
		game->mlx_win, game->frame->img, 0, 0);
}

void	init_map3d(t_data *game)
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
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S' ||
				game->map[i][j] == 'W' || game->map[i][j] == 'E')
				find_player(game, x, y);
			x += 1;
		}
		j = -1;
		x = 0;
		y += 1;
	}
}
