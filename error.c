/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:16:53 by ekraujin          #+#    #+#             */
/*   Updated: 2022/03/21 18:11:20 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	invalid_arg(void)
{
	write(1, "Error\nInvalid argument.\n", 24);
	exit(0);
}

void	invalid_top(void)
{
	write(1, "Error\nInvalid top.\n", 20);
	exit(0);
}

void	invalid_map_values(void)
{
	write(1, "Error\nInvalid map values.\n", 27);
	exit(0);
}

void	invalid_map(t_data *game)
{
	free_map(game);
	write(1, "Error\nInvalid map.\n", 20);
	exit(0);
}

void	free_map(t_data *game)
{
	int	i;

	i = -1;
	while (++i < game->lc)
		free(game->map[i]);
	free(game->map);
}