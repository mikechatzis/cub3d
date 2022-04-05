/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:12:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/04 19:36:47 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move2(t_data *game, int keycode)
{
	if (keycode == STRAFE_L)
		game->angle += 10;
	if (keycode == STRAFE_R)
		game->angle -= 10;
	if (keycode == RIGHT)
	{
		game->ppos_x += 60;
		draw_wall(game, game->ppos_x, game->ppos_y,
			create_trgb(0, 255, 255, 0));
		draw_wall(game, game->ppos_x - 60, game->ppos_y, 0);
	}
	if (keycode == LEFT)
	{
		game->ppos_x -= 60;
		draw_wall(game, game->ppos_x, game->ppos_y,
			create_trgb(0, 255, 255, 0));
		draw_wall(game, game->ppos_x + 60, game->ppos_y, 0);
	}
}

void	move(t_data *game, int keycode)
{
	if (keycode == UP)
	{
		game->ppos_y -= 40 * cos(game->angle);
		game->ppos_x += 40 * sin(game->angle);
		draw_wall(game, game->ppos_x, game->ppos_y,
			create_trgb(0, 255, 255, 0));
		draw_wall(game, game->ppos_x - 40 * sin(game->angle),
			game->ppos_y + 40 * cos(game->angle), 0);
	}
	else if (keycode == DOWN)
	{
		game->ppos_y += 60;
		draw_wall(game, game->ppos_x, game->ppos_y,
			create_trgb(0, 255, 255, 0));
		draw_wall(game, game->ppos_x, game->ppos_y - 60, 0);
	}
	else
		move2(game, keycode);
}
