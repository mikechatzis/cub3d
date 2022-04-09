/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:12:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/09 15:13:23 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move5(t_data *game, double tempx, double tempy)
{
	game->ppos_y -= game->diry * 15;
	game->ppos_x -= game->dirx * 15;
	if (wall_colision(game))
	{
		game->ppos_x = tempx;
		game->ppos_y = tempy;
	}
	draw_character(game, 255);
	game->xstart = 480;
	cast_rays(game);
}

void	move4(t_data *game, double tempx, double tempy)
{
	game->ppos_x += game->diry * 15;
	game->ppos_y -= game->dirx * 15;
	if (wall_colision(game))
	{
		game->ppos_x = tempx;
		game->ppos_y = tempy;
	}
	draw_character(game, 255);
	game->xstart = 480;
	cast_rays(game);
}

void	move3(t_data *game, int keycode)
{
	double	tempx;
	double	tempy;

	tempx = game->ppos_x;
	tempy = game->ppos_y;
	if (keycode == RIGHT)
	{
		game->ppos_x -= game->diry * 15;
		game->ppos_y += game->dirx * 15;
		if (wall_colision(game))
		{
			game->ppos_x = tempx;
			game->ppos_y = tempy;
		}
		draw_character(game, 255);
		game->xstart = 480;
		cast_rays(game);
	}
	if (keycode == LEFT)
		move4(game, tempx, tempy);
}

static void	move2(t_data *game, int keycode)
{
	if (keycode == STRAFE_L)
	{
		game->olddirx = game->dirx;
		game->dirx = game->dirx * cos((float)-0.1)
			- game->diry * sin((float)-0.1);
		game->diry = game->olddirx * sin((float)-0.1)
			+ game->diry * cos((float)-0.1);
		draw_character(game, 255);
		game->xstart = 480;
		cast_rays(game);
	}
	if (keycode == STRAFE_R)
	{
		game->olddirx = game->dirx;
		game->dirx = game->dirx * cos((float)0.1)
			- game->diry * sin((float)0.1);
		game->diry = game->olddirx * sin((float)0.1)
			+ game->diry * cos((float)0.1);
		draw_character(game, 255);
		game->xstart = 480;
		cast_rays(game);
	}
	move3(game, keycode);
}

void	move(t_data *game, int keycode)
{
	double	tempx;
	double	tempy;

	tempx = game->ppos_x;
	tempy = game->ppos_y;
	if (keycode == UP)
	{
		game->ppos_y += game->diry * 15;
		game->ppos_x += game->dirx * 15;
		if (wall_colision(game))
		{
			game->ppos_x = tempx;
			game->ppos_y = tempy;
		}
		draw_character(game, 255);
		game->xstart = 480;
		cast_rays(game);
	}
	else if (keycode == DOWN)
		move5(game, tempx, tempy);
	else
		move2(game, keycode);
}
