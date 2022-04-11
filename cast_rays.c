/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:12:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/11 23:47:06 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	wall_colision_up(t_data *game)
{
	if (game->map[(int)(game->ppos_y + game->diry * MOVESPEED * 2)]
		[(int)(game->ppos_x + game->dirx * MOVESPEED * 2)] == '1')
		return (1);
	return (0);
}

bool	wall_colision_down(t_data *game)
{
	if (game->map[(int)(game->ppos_y - game->diry * MOVESPEED * 2)]
		[(int)(game->ppos_x - game->dirx * MOVESPEED * 2)] == '1')
		return (1);
	return (0);
}

bool	wall_colision_left(t_data *game)
{
	if (game->map[(int)(game->ppos_y - game->planey * MOVESPEED * 2)]
		[(int)(game->ppos_x - game->planex * MOVESPEED * 2)] == '1')
		return (1);
	return (0);
}

bool	wall_colision_right(t_data *game)
{
	if (game->map[(int)(game->ppos_y + game->planey * MOVESPEED * 2)]
		[(int)(game->ppos_x + game->planex * MOVESPEED * 2)] == '1')
		return (1);
	return (0);
}
