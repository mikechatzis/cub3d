/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:12:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/15 12:01:43 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	raystructinit(t_ray *ray, t_data *game, int i)
{
	ray->camerax = 2 * i / (double)(SCREEN_W) - 1;
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

static void	calc_ray_dist(t_data *game, t_ray *ray, int i)
{
	if (!ray->side)
	{
		ray->perpwalldist = (ray->sidedistx - ray->deltadistx);
	}
	else
	{
		ray->perpwalldist = (ray->sidedisty - ray->deltadisty);
	}
}

static void	find_wall(t_data *game, t_ray *ray)
{
	while (!ray->hit)
	{
		if (ray->sidedistx < ray->sidedisty)
		{
			ray->sidedistx += ray->deltadistx;
			ray->mapx += ray->stepx;
			ray->side = 0;
		}
		else
		{
			ray->sidedisty += ray->deltadisty;
			ray->mapy += ray->stepy;
			ray->side = 1;
		}
		if (game->map[ray->mapy][ray->mapx] == '1')
			ray->hit = 1;
	}
}

void	cast_rays2(t_data *game)
{
	t_ray	ray;
	int		i;

	i = -1;
	while (++i < SCREEN_W)
	{
		raystructinit(&ray, game, i);
		rayvarsinit(&ray, game);
		find_wall(game, &ray);
		calc_ray_dist(game, &ray, i);
		draw_3dmap(game, &ray, (int)(i));
	}
	mlx_put_image_to_window(game->mlx_win,
		game->mlx_win, game->frame->img, 0, 0);
}
