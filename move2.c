/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:12:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/07 12:05:10 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	check(t_data *game, size_t i)
// {
// 	if (game->pdir == 'S' || game->pdir == 'E')
// 	{
// 		game->x = abs((int)(game->ppos_x + game->dirx * i + 1) / 60);
// 		game->y = abs((int)(game->ppos_y + game->diry * i + 1) / 60);
// 	}
// 	else if (game->pdir == 'N' || game->pdir == 'W')
// 	{
// 		game->x = abs((int)(game->ppos_x + game->dirx * i - 1) / 60);
// 		game->y = abs((int)(game->ppos_y + game->diry * i - 1) / 60);
// 	}
// }

// void	check2(t_data *game, size_t i)
// {
// 	if (game->dirx < 0 && game->diry < 0)
// 	{
// 		game->x = abs((int)(game->ppos_x + game->dirx * i - 1) / 60);
// 		game->y = abs((int)(game->ppos_y + game->diry * i - 1) / 60);
// 	}
// 	else if (game->dirx > 0 && game->diry < 0)
// 	{
// 		game->x = abs((int)(game->ppos_x + game->dirx * i + 1) / 60);
// 		game->y = abs((int)(game->ppos_y + game->diry * i - 1) / 60);
// 	}
// 	else if (game->dirx > 0 && game->diry > 0)
// 	{
// 		game->x = abs((int)(game->ppos_x + game->dirx * i + 1) / 60);
// 		game->y = abs((int)(game->ppos_y + game->diry * i + 1) / 60);
// 	}
// 	else
// 	{
// 		game->x = abs((int)(game->ppos_x + game->dirx * i - 1) / 60);
// 		game->y = abs((int)(game->ppos_y + game->diry * i + 1) / 60);
// 	}
// }

void	face_direction(t_data *game)
{
	size_t	i;

	i = -1;
	while (++i || 1)
	{
		game->x = abs((int)(game->ppos_x + game->dirx * i) / 60);
		game->y = abs((int)(game->ppos_y + game->diry * i) / 60);
		if (game->map[game->y][game->x] == '1')
			break ;
		mlx_pixel_put(game->mlx, game->mlx_win, game->ppos_x + game->dirx * i,
			game->ppos_y + game->diry * i, create_trgb(0, 0, 60, 0));
	}
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
		mlx_pixel_put(game->mlx, game->mlx_win, game->ppos_x + game->dirx * i,
			game->ppos_y + game->diry * i, create_trgb(0, 60, 0, 0));
	}
	return (0);
}
