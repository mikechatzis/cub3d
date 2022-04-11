/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:12:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/11 02:37:02 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	raystructinit(t_ray *ray, t_data *game, int i)
{
	ray->camerax = 2 * i / (double)(480) - 1;
	ray->raydirx = game->dirx + game->planex * ray->camerax;
	ray->raydiry = game->diry + game->planey * ray->camerax;
	ray->mapx = (int)game->ppos_x;
	ray->mapy = (int)game->ppos_y;
	if (!game->dirx)
		ray->deltadistx = INFINITY;
	else
		ray->deltadistx = fabs(1 / ray->raydirx);
	if (!game->diry)
		ray->deltadisty = INFINITY;
	else
		ray->deltadisty = fabs(1 / ray->raydiry);
	ray->hit = 0;
}

static void	rayvarsinit(t_ray *ray, t_data *game)
{
	if (game->dirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (game->ppos_x - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - game->ppos_x) * ray->deltadistx;
	}
	if (game->diry < 0)
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
	while (++i < 480)
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
			ray.perpwalldist = (ray.sidedistx - ray.deltadistx);
		else
			ray.perpwalldist = (ray.sidedisty - ray.deltadisty);
		draw_3dmap(game, &ray, i);
	}
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
