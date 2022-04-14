/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:29:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/13 19:59:13 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	*choose_tex(t_data *game, t_ray *ray)
{
	void	*img;

	if (!ray->side)
	{
		if (ray->raydirx > 0)
			return (game->tex_e);
		return (game->tex_w);
	}
	else
	{
		if (ray->raydiry < 0)
			return (game->tex_s);
		return (game->tex_n);
	}
	return (0);
}