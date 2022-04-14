/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 21:15:10 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/14 16:59:45 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	find_player(t_data *game, int x, int y)
{
	game->ppos_x = x + 0.5;
	game->ppos_y = y + 0.5;
}

static void	*pick_pixel(t_data *game, t_ray *ray)
{
	double	wallx;
	t_img	*tex;

	tex = choose_tex(game, ray);
	if (!ray->side)
		wallx = game->ppos_y + ray->perpwalldist * ray->raydiry;
	else
		wallx = game->ppos_x + ray->perpwalldist * ray->raydirx;
	wallx -= floor((wallx));
	game->texx = (int)(wallx * (double)(tex->width));
	if (ray->side == 0 && ray->raydirx > 0)
		game->texx = tex->width - game->texx - 1;
	if (ray->side == 1 && ray->raydiry < 0)
		game->texx = tex->width - game->texx - 1;
	game->step = 1.0 * tex->height / game->lineheight;
	game->texpos = (game->linestart - SCREEN_H / 2
			+ game->lineheight / 2) * game->step;
	return (tex);
}

static void	pxls_in_img(t_data *game, int x, t_ray *ray, t_img *img)
{
	int	y;
	int	rgb;
	int	texy;

	y = -1;
	rgb = create_trgb(0, game->colors[3], game->colors[4], game->colors[5]);
	while (++y <= game->linestart)
		my_mlx_pixel_put(game, x, y, rgb);
	y = -1;
	while (++y < game->lineheight)
	{
		texy = (int)game->texpos & (img->height - 1);
		game->texpos += game->step;
		rgb = img->px_clrs[texy * img->width + game->texx];
		if (ray->side)
			rgb = (rgb >> 1) & 8355711;
		my_mlx_pixel_put(game, x,
			y + game->linestart, rgb);
	}	
	y -= 1;
	rgb = create_trgb(0, game->colors[0], game->colors[1], game->colors[2]);
	while (++y < SCREEN_H - game->linestart)
		my_mlx_pixel_put(game, x,
			y + game->linestart, rgb);
}

void	draw_3dmap(t_data *game, t_ray *ray, int x)
{
	game->lineheight = SCREEN_H / ray->perpwalldist;
	game->linestart = -game->lineheight / 2 + SCREEN_H / 2;
	if (game->linestart < 0)
		game->linestart = 0;
	if (game->lineheight > SCREEN_H)
		game->lineheight = SCREEN_H;
	pxls_in_img(game, x, ray, pick_pixel(game, ray));
}

void	init_map3d(t_data *game)
{
	int	x;
	int	y;
	int	i;
	int	j;

	x = 0;
	y = 0;
	i = -1;
	j = -1;
	while (game->map[++i])
	{
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S' ||
				game->map[i][j] == 'W' || game->map[i][j] == 'E')
				find_player(game, x, y);
			x += 1;
		}
		j = -1;
		x = 0;
		y += 1;
	}
}
