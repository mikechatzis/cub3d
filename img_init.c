/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:12:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/13 15:03:58 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_pixel_colors(t_img *img)
{
	size_t	i;
	int		x;
	int		y;

	x = -1;
	while (++x < img->width)
	{
		y = -1;
		while (++y < img->height)
		{
			i = img->width * y + x;
			img->px_clrs[i] = (int)img->addr[i];
		}
	}
// 	i = -1;
// 	while (++i < img->width * img->height)
// 		img->px_clrs[i] = (int)img->addr[i];
}

static void	save_textures2(t_img *img, t_data *game, int i)
{
	int	width;
	int	height;

	img->img = mlx_xpm_file_to_image(game->mlx,
			game->textures[i], &width, &height);
	if (!img->img)
	{
		printf("Error: texture %s\n", game->textures[i]);
		finish_game(game);
	}
	img->px_clrs = (int *)mlx_get_data_addr(img->img,
			&img->bits_per_pixel, &img->line_length,
			&img->endian);
	if (!img->addr)
	{
		printf("Error: data address\n");
		finish_game(game);
	}
	img->width = width;
	img->height = height;
	// get_pixel_colors(img);
}

void	save_textures(t_data *game)
{
	game->tex_n = malloc(sizeof(t_img));
	game->tex_s = malloc(sizeof(t_img));
	game->tex_e = malloc(sizeof(t_img));
	game->tex_w = malloc(sizeof(t_img));
	save_textures2(game->tex_n, game, 0);
	save_textures2(game->tex_s, game, 1);
	save_textures2(game->tex_e, game, 2);
	save_textures2(game->tex_w, game, 3);
}

void	img_init(t_data *game)
{
	game->frame->img = mlx_new_image(game->mlx, SCREEN_W, SCREEN_H);
	game->frame->addr = mlx_get_data_addr(game->frame->img,
			&game->frame->bits_per_pixel, &game->frame->line_length,
			&game->frame->endian);
	save_textures(game);
}
