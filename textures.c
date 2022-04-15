/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:29:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/15 12:06:25 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_dir(const char *path)
{
	struct stat	path_stat;

	stat(path, &path_stat);
	return (S_ISDIR(path_stat.st_mode));
}

void	init_check(t_data *game, int argc, int mfd)
{
	mfd = open(game->map_file, O_RDONLY);
	if (argc != 2 || mfd <= 0 || is_dir(game->map_file)
		|| !arg_check(game, mfd))
		invalid_arg(game);
	if (!assign_map(game, mfd))
		invalid_map_values();
	if (!check_map(game))
		invalid_map(game);
	close(mfd);
	direction_init(game);
}

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
