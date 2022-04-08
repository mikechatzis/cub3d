/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:12:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/08 18:25:31 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_ray(t_data *game)
{
	size_t	i;

	i = -1;
	while (++i || 1)
	{
		game->x = abs((int)(game->ppos_x + game->dirx * i) / 60);
		game->y = abs((int)(game->ppos_y + game->diry * i) / 60);
		if (game->map[game->y][game->x] == '1')
			break ;
		// mlx_pixel_put(game->mlx, game->mlx_win, game->ppos_x + game->dirx * i,
		// 	game->ppos_y + game->diry * i, create_trgb(0, 0, 60, 0));
	}
	game->raylen = i;
	draw_3dmap(game);
}

bool	wall_colision_ray(t_data *game)
{
	size_t	i;

	i = -1;
	while (++i < 10)
	{
		game->x = abs((int)(game->ppos_x + game->dirx * i) / 60);
		game->y = abs((int)(game->ppos_y + game->diry * i) / 60);
		if (game->map[game->y][game->x] == '1')
			return (1);
		// mlx_pixel_put(game->mlx, game->mlx_win, game->ppos_x + game->dirx * i,
		// 	game->ppos_y + game->diry * i, create_trgb(0, 60, 0, 0));
	}
	return (0);
}
