/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:12:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/05 18:27:26 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move3(t_data *game, int keycode)
{
	if (keycode == RIGHT)
	{
		game->ppos_x += game->dirY * 15 + 0.0001;
		game->ppos_y -= game->dirX * 15 + 0.0001;
		draw_character(game, 255);
		face_direction(game);
	}
	if (keycode == LEFT)
	{
		game->ppos_x -= game->dirY * 15 + 0.0001;
		game->ppos_y += game->dirX * 15 + 0.0001;
		draw_character(game, 255);
		face_direction(game);
	}
}

void	move2(t_data *game, int keycode)
{
	if (keycode == STRAFE_L)
	{
		game->oldDirX = game->dirX;
		game->dirX = game->dirX * cos((float)-0.2)
			- game->dirY * sin((float)-0.2);
		game->dirY = game->oldDirX * sin((float)-0.2)
			+ game->dirY * cos((float)-0.2);
		draw_character(game, 255);
		face_direction(game);
	}
	if (keycode == STRAFE_R)
	{
		game->oldDirX = game->dirX;
		game->dirX = game->dirX * cos((float)0.2)
			- game->dirY * sin((float)0.2);
		game->dirY = game->oldDirX * sin((float)0.2)
			+ game->dirY * cos((float)0.2);
		draw_character(game, 255);
		face_direction(game);
	}
	move3(game, keycode);
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
