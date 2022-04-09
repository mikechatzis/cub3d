/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:12:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/09 16:08:12 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	raystructinit(t_ray *ray, t_data *game)
{
	ray->mapx = game->ppos_x / 60;
	ray->mapy = game->ppos_y / 60;
	ray->deltadistx = fabs(1 / game->dirx);
	// if (!game->dirx)
	// 	ray->deltadistx = 1e30;
	ray->deltadisty = fabs(1 / game->diry);
	// if (!game->diry)
	// 	ray->deltadisty = 1e30;
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
		ray->sidedistx = (ray->mapy + 1 - game->ppos_x) * ray->deltadistx;
	}
	if (game->diry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (game->ppos_y - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1 - game->ppos_y) * ray->deltadisty;
	}
}

void	cast_ray(t_data *game)
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
			printf("test\n");
				ray.hit = 1;
		}
	}
	if (!ray.side)
		game->raylen = fabs(ray.sidedistx - ray.deltadistx) + 60;
	else
		game->raylen = fabs(ray.sidedisty - ray.deltadisty) - 60;
	if (game->raylen < 0)
		game->raylen *= -1;
	printf("%ld\n", game->raylen);
	for (size_t i = 0; i < game->raylen ; i++)
	{
		mlx_pixel_put(game->mlx, game->mlx_win, game->ppos_x + game->dirx * i, game->ppos_y + game->diry * i, create_trgb(0, 0, 255, 0));
	}
	
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
