/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:15:10 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/07 19:59:48 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

static void	find_player(t_data *game, int x, int y)
{
	game->ppos_x = x;
	game->ppos_y = y;
	// draw_character(game, 155);
}

void	draw_3dmap(t_data *game, double startx, double starty) // We never use startx or starty
{
	int	lineheight;
	int	linestart;
	static	int	x;
	int	y;
	
	lineheight = 450 * 60 / game->raylen;
	if (lineheight > 450)
		lineheight = 450;
	linestart = 225 - lineheight / 2;
	mlx_clear_window(game->mlx, game->mlx_win);
	while (game->xstart++ % 10 && game->xstart < 450)
	{
		y = -1;
		while (++y < lineheight)
			mlx_pixel_put(game->mlx, game->mlx_win, startx + game->xstart, starty + y + linestart, create_trgb(0, 120, 0, 120));
	}
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
			x += 60;
		}
		j = -1;
		x = 0;
		y += 60;
	}
}