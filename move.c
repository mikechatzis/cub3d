/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:12:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/05 15:11:59 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move2(t_data *game, int keycode)
{
	if (keycode == STRAFE_L)
	{
		game->oldDirX = game->dirX;
		game->dirX = game->dirX * cos((float)-0.2) - game->dirY * sin((float)-0.2);
		game->dirY = game->oldDirX * sin((float)-0.2) + game->dirY * cos((float)-0.2);
	}
	if (keycode == STRAFE_R)
	{
		game->oldDirX = game->dirX;
		game->dirX = game->dirX * cos((float)0.2) - game->dirY * sin((float)0.2);
		game->dirY = game->oldDirX * sin((float)0.2) + game->dirY * cos((float)0.2);
	}
	if (keycode == RIGHT)
	{
		game->ppos_x -= game->dirY * 15;
		game->ppos_y += game->dirX * 15;
		draw_character(game, 255);
		face_direction(game);
	}
	if (keycode == LEFT)
	{
		game->ppos_x += game->dirY * 15;
		game->ppos_y -= game->dirX * 15;
		draw_character(game, 255);
		face_direction(game);
	}
}

void	move(t_data *game, int keycode)
{
	if (keycode == UP)
	{
		game->ppos_y += game->dirY * 15;
		game->ppos_x += game->dirX * 15;
		draw_character(game, 255);
		face_direction(game);
	}
	else if (keycode == DOWN)
	{
		game->ppos_y -= game->dirY * 15;
		game->ppos_x -= game->dirX * 15;
		draw_character(game, 255);
		face_direction(game);
	}
	else
		move2(game, keycode);
}
