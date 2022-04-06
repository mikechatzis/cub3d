/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:12:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/06 18:39:59 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	cast_rays_left(t_data *game)
{
	size_t	i;

	i = -1;
	while (++i < 30)
	{
		face_direction(game);
		game->olddirx = game->dirx;
		game->dirx = game->dirx * cos((float)-0.02)
			- game->diry * sin((float)-0.02);
		game->diry = game->olddirx * sin((float)-0.02)
			+ game->diry * cos((float)-0.02);
	}
}

static void	cast_rays_right(t_data *game)
{
	size_t	i;

	i = -1;
	while (++i < 30)
	{
		game->olddirx = game->dirx;
		game->dirx = game->dirx * cos((float)0.02)
			- game->diry * sin((float)0.02);
		game->diry = game->olddirx * sin((float)0.02)
			+ game->diry * cos((float)0.02);
		face_direction(game);
	}
}

static bool	cast_rays_colision(t_data *game)
{
	size_t	i;

	i = -1;
	while (++i < 144)
	{
		if (wall_colision_ray(game))
			return (1);
		game->olddirx = game->dirx;
		game->dirx = game->dirx * cos((float)-0.05)
			- game->diry * sin((float)-0.05);
		game->diry = game->olddirx * sin((float)-0.05)
			+ game->diry * cos((float)-0.05);
	}
	return (0);
}

void	cast_rays(t_data *game)
{
	double	cur_dirx;
	double	cur_diry;

	cur_dirx = game->dirx;
	cur_diry = game->diry;
	cast_rays_left(game);
	game->dirx = cur_dirx;
	game->diry = cur_diry;
	cast_rays_right(game);
	game->dirx = cur_dirx;
	game->diry = cur_diry;
}

bool	wall_colision(t_data *game)
{
	double	cur_dirx;
	double	cur_diry;

	cur_dirx = game->dirx;
	cur_diry = game->diry;
	if (cast_rays_colision(game))
	{
		game->dirx = cur_dirx;
		game->diry = cur_diry;
		return (1);
	}
	game->dirx = cur_dirx;
	game->diry = cur_diry;
	return (0);
}
