/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:12:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/09 19:23:23 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	raystructinit(t_ray *ray, t_data *game)
{
	ray->mapx = game->ppos_x / 60;
	ray->mapy = game->ppos_y / 60;
	ray->deltadistx = fabs(1 / game->dirx);
	if (!game->dirx)
		ray->deltadistx = INFINITY;
	ray->deltadisty = fabs(1 / game->diry);
	if (!game->diry)
		ray->deltadisty = INFINITY;
	ray->hit = 0;
}

static void	rayvarsinit(t_ray *ray, t_data *game)
{
	if (game->dirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (double)(game->ppos_x - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (double)(ray->mapx + 60 - game->ppos_x) * ray->deltadistx;
	}
	if (game->diry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (double)(game->ppos_y - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (double)(ray->mapy + 60 - game->ppos_y) * ray->deltadisty;
	}
	printf("%lf    %lf  \n", ray->sidedistx, ray->sidedisty);
}

void	cast_ray(t_data *game, size_t i)
{
	t_ray	ray;

	raystructinit(&ray, game);
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
		{
			printf("hit\n");
			ray.hit = 1;
		}
		mlx_pixel_put(game->mlx, game->mlx_win, ray.mapx * 60, ray.mapy * 60, create_trgb(0, 0, 255, 0));
	}
	if (!ray.side)
		game->raylen = (int)fabs((ray.sidedistx - ray.deltadistx)
				/ cos(0.005 * (i + 1)));
	else
		game->raylen = (int)fabs((ray.sidedisty - ray.deltadisty)
				/ cos(0.005 * (i + 1)));
	printf("%ld\n", game->raylen);
	// draw_3dmap(game, &ray);
}

bool	wall_colision_ray(t_data *game)
{
	size_t	i;

	i = -1;
	while (++i < 10)
	{
		game->x = abs((int)(game->ppos_x + game->dirx * i) / 60);
		game->y = abs((int)(game->ppos_y + game->diry * i) / 60);
		if (game->map[game->y][game->x] == '1')
			return (1);
		// mlx_pixel_put(game->mlx, game->mlx_win, game->ppos_x + game->dirx * i,
		// 	game->ppos_y + game->diry * i, create_trgb(0, 60, 0, 0));
	}
	return (0);
}
