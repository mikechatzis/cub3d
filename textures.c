/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:29:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/14 20:38:43 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	check_validity(char *temp)
{
	temp = skip_tab_n_space(temp);
	if ((ft_strncmp(temp, "NO", 2) && ft_strncmp(temp, "SO", 2)
			&& ft_strncmp(temp, "F", 1) && ft_strncmp(temp, "C", 1)
			&& ft_strncmp(temp, "WE", 2) && ft_strncmp(temp, "EA", 2)))
		return (false);
	return (true);
}

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
