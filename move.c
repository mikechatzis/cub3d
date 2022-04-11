/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:12:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/11 17:46:56 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move5(t_data *game, double tempx, double tempy)
{
	game->ppos_y -= game->diry * MOVESPEED;
	game->ppos_x -= game->dirx * MOVESPEED;
	if (wall_colision_DOWN(game))
	{
		game->ppos_x = tempx;
		game->ppos_y = tempy;
	}
	cast_rays2(game);
}

void	move4(t_data *game, double tempx, double tempy)
{
	game->ppos_x -= game->diry * MOVESPEED;
	game->ppos_y += game->dirx * MOVESPEED;
	if (wall_colision_LEFT(game))
	{
		game->ppos_x = tempx;
		game->ppos_y = tempy;
	}
	cast_rays2(game);
}

void	move3(t_data *game, int keycode)
{
	double	tempx;
	double	tempy;
	
	if (keycode == RIGHT)
	{
		game->ppos_x += game->diry * MOVESPEED;
		game->ppos_y -= game->dirx * MOVESPEED;
		if (wall_colision_RIGHT(game))
		{
			game->ppos_x = tempx;
			game->ppos_y = tempy;
		}
		cast_rays2(game);
	}
	if (keycode == LEFT)
		move4(game, tempx, tempy);
}

static void	move2(t_data *game, int keycode)
{
	if (keycode == STRAFE_R)
	{
		game->olddirx = game->dirx;
		game->dirx = game->dirx * cos(ROTSPEED)
			- game->diry * sin(ROTSPEED);
		game->diry = game->olddirx * sin(ROTSPEED)
			+ game->diry * cos(ROTSPEED);
		game->oldplanex = game->planex;
		game->planex = game->planex * cos(ROTSPEED) - game->planey * sin(ROTSPEED);
		game->planey = game->oldplanex * sin(ROTSPEED) + game->planey * cos(ROTSPEED);
		cast_rays2(game);
	}
	if (keycode == STRAFE_L)
	{
		game->olddirx = game->dirx;
		game->dirx = game->dirx * cos(-ROTSPEED)
			- game->diry * sin(-ROTSPEED);
		game->diry = game->olddirx * sin(-ROTSPEED)
			+ game->diry * cos(-ROTSPEED);
		game->oldplanex = game->planex;
		game->planex = game->planex * cos(-ROTSPEED) - game->planey * sin(-ROTSPEED);
		game->planey = game->oldplanex * sin(-ROTSPEED) + game->planey * cos(-ROTSPEED);
		cast_rays2(game);
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
		if (wall_colision_UP(game))
		{
			game->ppos_x = tempx;
			game->ppos_y = tempy;
		}
		else
		{
			game->ppos_x += game->dirx * MOVESPEED;
			game->ppos_y += game->diry * MOVESPEED; 
			cast_rays2(game);
		}
		
	}
	else if (keycode == DOWN)
		move5(game, tempx, tempy);
	else
		move2(game, keycode);
}
