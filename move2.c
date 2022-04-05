/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:12:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/05 19:12:49 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	face_direction(t_data *game)
{
	int		y;
	size_t	i;
	int		x;

	i = -1;
	while (++i || 1)
	{
		if ((!((int)(game->ppos_x + game->dirX * i) % 60)
			|| !((int)(game->ppos_y + game->dirY * i) % 60)))
		{
			printf("%lf, %lf\n", game->dirX, game->dirY);
			if (game->dirX < 0 && game->dirY < 0)
			{
				x = abs((int)(game->ppos_x + game->dirX * i - 1) / 60);
				y = abs((int)(game->ppos_y + game->dirY * i - 1) / 60);
			}
			else if (game->dirX > 0 && game->dirY < 0)
			{
				x = abs((int)(game->ppos_x + game->dirX * i + 1) / 60);
				y = abs((int)(game->ppos_y + game->dirY * i - 1) / 60);
			}
			else if (game->dirX > 0 && game->dirY > 0)
			{
				x = abs((int)(game->ppos_x + game->dirX * i + 1) / 60);
				y = abs((int)(game->ppos_y + game->dirY * i + 1) / 60);
			}
			else
			{
				x = abs((int)(game->ppos_x + game->dirX * i - 1) / 60);
				y = abs((int)(game->ppos_y + game->dirY * i + 1) / 60);
			}
			if (game->map[y][x] == '1')
				break ;
		}
		mlx_pixel_put(game->mlx, game->mlx_win, game->ppos_x + game->dirX * i,
			game->ppos_y + game->dirY * i, create_trgb(0, 0, 60, 0));
	}
}
