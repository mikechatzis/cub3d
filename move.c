/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:12:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/14 17:00:19 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move5(t_data *game, double tempx, double tempy)
{
	if (wall_collision_down(game))
	{
		game->ppos_x = tempx;
		game->ppos_y = tempy;
	}
	else
	{
		game->ppos_x -= game->dirx * MOVESPEED;
		game->ppos_y -= game->diry * MOVESPEED;
		cast_rays2(game);
	}
}

void	move4(t_data *game, double tempx, double tempy)
{
	if (wall_collision_left(game))
	{
		game->ppos_x = tempx;
		game->ppos_y = tempy;
	}
	else
	{
		game->ppos_x -= game->planex * MOVESPEED;
		game->ppos_y -= game->planey * MOVESPEED;
		cast_rays2(game);
	}
}

void	move3(t_data *game, int keycode)
{
	double	tempx;
	double	tempy;

	tempx = game->ppos_x;
	tempy = game->ppos_y;
	if (keycode == RIGHT)
	{
		if (wall_collision_right(game))
		{
			game->ppos_x = tempx;
			game->ppos_y = tempy;
		}
		else
		{
			game->ppos_x += game->planex * MOVESPEED;
			game->ppos_y += game->planey * MOVESPEED;
			cast_rays2(game);
		}
	}
	if (keycode == LEFT)
		move4(game, tempx, tempy);
}

static void	move2(t_data *game, int keycode)
{
	if (keycode == STRAFE_R)
	{
		game->odirx = game->dirx;
		game->dirx = game->dirx * cos(ROTSPEED) - game->diry * sin(ROTSPEED);
		game->diry = game->odirx * sin(ROTSPEED) + game->diry * cos(ROTSPEED);
		game->oplanex = game->planex;
		game->planex = game->planex * cos(ROTSPEED)
			- game->planey * sin(ROTSPEED);
		game->planey = game->oplanex * sin(ROTSPEED)
			+ game->planey * cos(ROTSPEED);
		cast_rays2(game);
	}
	if (keycode == STRAFE_L)
	{
		game->odirx = game->dirx;
		game->dirx = game->dirx * cos(-ROTSPEED) - game->diry * sin(-ROTSPEED);
		game->diry = game->odirx * sin(-ROTSPEED) + game->diry * cos(-ROTSPEED);
		game->oplanex = game->planex;
		game->planex = game->planex * cos(-ROTSPEED)
			- game->planey * sin(-ROTSPEED);
		game->planey = game->oplanex * sin(-ROTSPEED)
			+ game->planey * cos(-ROTSPEED);
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
		if (wall_collision_up(game))
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
