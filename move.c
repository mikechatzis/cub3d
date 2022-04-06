/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:12:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/06 18:20:50 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move3(t_data *game, int keycode)
{
	if (keycode == RIGHT)
	{
		game->ppos_x -= game->diry * 15;
		game->ppos_y += game->dirx * 15;
		draw_character(game, 255);
		cast_rays(game);
	}
	if (keycode == LEFT)
	{
		game->ppos_x += game->diry * 15;
		game->ppos_y -= game->dirx * 15;
		draw_character(game, 255);
		cast_rays(game);
	}
}

void	move2(t_data *game, int keycode)
{
	if (keycode == STRAFE_L)
	{
		game->olddirx = game->dirx;
		game->dirx = game->dirx * cos((float)-0.1)
			- game->diry * sin((float)-0.1);
		game->diry = game->olddirx * sin((float)-0.1)
			+ game->diry * cos((float)-0.1);
		draw_character(game, 255);
		cast_rays(game);
		game->check = 1;
	}
	if (keycode == STRAFE_R)
	{
		game->olddirx = game->dirx;
		game->dirx = game->dirx * cos((float)0.1)
			- game->diry * sin((float)0.1);
		game->diry = game->olddirx * sin((float)0.1)
			+ game->diry * cos((float)0.1);
		draw_character(game, 255);
		cast_rays(game);
		game->check = 1;
	}
	move3(game, keycode);
}

void	move(t_data *game, int keycode)
{
	if (keycode == UP)
	{
		game->ppos_y += game->diry * 15;
		game->ppos_x += game->dirx * 15;
		draw_character(game, 255);
		cast_rays(game);
	}
	else if (keycode == DOWN)
	{
		game->ppos_y -= game->diry * 15;
		game->ppos_x -= game->dirx * 15;
		draw_character(game, 255);
		cast_rays(game);
	}
	else
		move2(game, keycode);
}
