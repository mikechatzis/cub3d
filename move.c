/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:12:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/06 14:27:09 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	move3(t_data *game, int keycode)
{
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

static void	move2(t_data *game, int keycode)
{
	if (keycode == STRAFE_L)
	{
		game->oldDirX = game->dirX;
		game->dirX = game->dirX * cos((float)-0.1)
			- game->dirY * sin((float)-0.1);
		game->dirY = game->oldDirX * sin((float)-0.1)
			+ game->dirY * cos((float)-0.1);
		draw_character(game, 255);
		face_direction(game);
		game->check = 1;
	}
	if (keycode == STRAFE_R)
	{
		game->oldDirX = game->dirX;
		game->dirX = game->dirX * cos((float)0.1)
			- game->dirY * sin((float)0.1);
		game->dirY = game->oldDirX * sin((float)0.1)
			+ game->dirY * cos((float)0.1);
		draw_character(game, 255);
		face_direction(game);
		game->check = 1;
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
