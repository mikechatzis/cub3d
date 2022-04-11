/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:15:10 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/11 02:23:41 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	find_player(t_data *game, int x, int y)
{
	game->ppos_x = x;
	game->ppos_y = y;
}

void	draw_3dmap(t_data *game, t_ray *ray, int x)
{
	int	lineheight;
	int	linestart;
	int	lineend;
	int	y;

	lineheight = 480 / ray->perpwalldist;
	linestart = 240 - lineheight / 2;
	if (lineheight > 480)
		lineheight = 480;
	// lineend = lineheight / 2 + 480 / 2;
	// if (lineend >= 480)
	// 	lineend = 480 - 1; 
	y = -1;
	while (++y < lineheight)
		mlx_pixel_put(game->mlx, game->mlx_win, x, y + linestart, create_trgb(0, 0, 255, 0));
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
