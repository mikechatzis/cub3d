/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:12:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/11 18:02:18 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	wall_colision_UP(t_data *game)
{
	printf("%d   %d\n", (int)(game->ppos_y * MOVESPEED * 6), (int)(game->ppos_x * MOVESPEED * 6));
	if (game->map[(int)(game->ppos_y * MOVESPEED * 6)][(int)(game->ppos_x * MOVESPEED * 6)] == '1')
	{
		printf("test\n");
		return (1);	
	}
	return (0);
}

bool	wall_colision_DOWN(t_data *game)
{
	printf("%d   %d\n", (int)(game->ppos_y * MOVESPEED * 6), (int)(game->ppos_x * MOVESPEED * 6));
	if (game->map[(int)(game->ppos_y * MOVESPEED * 6)][(int)(game->ppos_x * MOVESPEED * 6)] == '1')
	{
		printf("test\n");
		return (1);
	}
	return (0);
}

bool	wall_colision_LEFT(t_data *game)
{
	printf("%d   %d\n", (int)(game->ppos_y * MOVESPEED * 6), (int)(game->ppos_x * MOVESPEED * 6));
	if (game->map[(int)(game->ppos_y * MOVESPEED * 6)][(int)(game->ppos_x * MOVESPEED * 6)] == '1')
	{
		printf("test\n");
		return (1);	
	}
	return (0);
}

bool	wall_colision_RIGHT(t_data *game)
{
	printf("%d   %d\n", (int)(game->ppos_y * MOVESPEED * 6), (int)(game->ppos_x * MOVESPEED * 6));
	if (game->map[(int)(game->ppos_y * MOVESPEED * 6)][(int)(game->ppos_x * MOVESPEED * 6)] == '1')
	{
		printf("test\n");
		return (1);	
	}
	return (0);
}