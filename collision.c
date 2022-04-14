/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:12:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/14 16:59:06 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	wall_collision_up(t_data *game)
{
	if (game->map[(int)(game->ppos_y + game->diry * MOVESPEED)]
		[(int)(game->ppos_x + game->dirx * MOVESPEED)] == '1')
		return (1);
	return (0);
}

bool	wall_collision_down(t_data *game)
{
	if (game->map[(int)(game->ppos_y - game->diry * MOVESPEED)]
		[(int)(game->ppos_x - game->dirx * MOVESPEED)] == '1')
		return (1);
	return (0);
}

bool	wall_collision_left(t_data *game)
{
	if (game->map[(int)(game->ppos_y - game->planey * MOVESPEED)]
		[(int)(game->ppos_x - game->planex * MOVESPEED)] == '1')
		return (1);
	return (0);
}

bool	wall_collision_right(t_data *game)
{
	if (game->map[(int)(game->ppos_y + game->planey * MOVESPEED)]
		[(int)(game->ppos_x + game->planex * MOVESPEED)] == '1')
		return (1);
	return (0);
}
