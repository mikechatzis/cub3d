/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:12:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/14 19:42:08 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *game, int x, int y, int color)
{
	char	*dst;

	dst = game->frame->addr + (y * game->frame->line_length
			+ x * (game->frame->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

size_t	len_no_n(char *s)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	return (len);
}

static void	direction_init2(t_data *game)
{
	if (game->pdir == 'W')
	{
		game->dirx = -1;
		game->diry = 0;
		game->planex = 0;
		game->planey = -0.66;
	}
	else
	{
		game->dirx = 0;
		game->diry = 1;
		game->planex = -0.66;
		game->planey = 0;
	}
}

void	direction_init(t_data *game)
{
	if (game->pdir == 'N')
	{
		game->dirx = 0;
		game->diry = -1;
		game->planex = 0.66;
		game->planey = 0;
	}
	else if (game->pdir == 'E')
	{
		game->dirx = 1;
		game->diry = 0;
		game->planex = 0;
		game->planey = 0.66;
	}
	else
		direction_init2(game);
}

void	initialize(t_data *game, char **argv)
{
	int	i;

	i = -1;
	game->f = 0;
	game->c = 0;
	game->ltm = 0;
	game->frame = malloc(sizeof(t_img *));
	game->l_max_len = 0;
	game->map_file = argv[1];
	while (++i < 4)
		game->textures[i] = NULL;
}
