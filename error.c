/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:16:53 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/15 11:54:32 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	invalid_arg(t_data *game)
{
	freedirec2(game);
	write(1, "Error\nInvalid argument.\n", 24);
	exit(1);
}

void	invalid_top(void)
{
	write(1, "Error\nInvalid top.\n", 20);
	exit(1);
}

void	invalid_map_values(void)
{
	write(1, "Error\nInvalid map values.\n", 27);
	exit(1);
}

void	invalid_map(t_data *game)
{
	free_map(game, 0);
	write(1, "Error\nInvalid map.\n", 20);
	exit(1);
}

void	free_map(t_data *game, int check)
{
	int	i;

	i = -1;
	while (++i < game->lc)
		free(game->map[i]);
	free(game->map);
	if (check)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		mlx_destroy_image(game->mlx, game->frame->img);
	}
	free(game->frame);
}
