/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:12:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/11 17:49:56 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	raystructinit(t_ray *ray, t_data *game, int i)
{
	ray->camerax = 2 * i / (double)(60) - 1;
	ray->raydirx = game->dirx + game->planex * ray->camerax;
	ray->raydiry = game->diry + game->planey * ray->camerax;
	ray->mapx = (int)game->ppos_x;
	ray->mapy = (int)game->ppos_y;
	if (!ray->raydirx)
		ray->deltadistx = INFINITY;
	else
		ray->deltadistx = fabs(1 / ray->raydirx);
	if (!ray->raydiry)
		ray->deltadisty = INFINITY;
	else
		ray->deltadisty = fabs(1 / ray->raydiry);
	ray->hit = 0;
}

static void	rayvarsinit(t_ray *ray, t_data *game)
{
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (game->ppos_x - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - game->ppos_x) * ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (game->ppos_y - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - game->ppos_y) * ray->deltadisty;
	}
}

void	cast_rays2(t_data *game)
{
	t_ray	ray;
	int		i;

	mlx_clear_window(game->mlx, game->mlx_win);
	i = -1;
	while (++i < 60)
	{
		raystructinit(&ray, game, i);
		rayvarsinit(&ray, game);
		while (!ray.hit)
		{
			if (ray.sidedistx < ray.sidedisty)
			{
				ray.sidedistx += ray.deltadistx;
				ray.mapx += ray.stepx;
				ray.side = 0;
			}
			else
			{
				ray.sidedisty += ray.deltadisty;
				ray.mapy += ray.stepy;
				ray.side = 1;
			}
			if (game->map[ray.mapy][ray.mapx] == '1')
				ray.hit = 1;
		}
		if (!ray.side)
		{
			ray.perpwalldist = (ray.sidedistx - ray.deltadistx);
			draw_3dmap(game, &ray, (int)(i + game->ppos_y + ray.perpwalldist * ray.raydirx));
		}
		else
		{
			ray.perpwalldist = (ray.sidedisty - ray.deltadisty);
			draw_3dmap(game, &ray, (int)(i + game->ppos_x + ray.perpwalldist * ray.raydirx));
		}
	}
}

