/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:12:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/12 20:10:10 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	img_init(t_data *game)
{
	game->frame->img = mlx_new_image(game->mlx, SCREEN_W, SCREEN_H);
	game->frame->addr = mlx_get_data_addr(game->frame->img,
			&game->frame->bits_per_pixel, &game->frame->line_length,
			&game->frame->endian);
}
