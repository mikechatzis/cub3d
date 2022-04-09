/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:12:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/09 14:14:27 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	len_no_n(char *s)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	return (len);
}

void	direction_init(t_data *game)
{
	if (game->pdir == 'N')
	{
		game->dirx = 0;
		game->diry = -1;
	}
	else if (game->pdir == 'E')
	{
		game->dirx = 1;
		game->diry = 0;
	}
	else if (game->pdir == 'W')
	{
		game->dirx = -1;
		game->diry = 0;
	}
	else
	{
		game->dirx = 0;
		game->diry = 1;
	}
}

void	initialize(t_data *game, char **argv)
{
	game->xstart = 480;
	game->rayside = 0;
	game->check = 0;
	game->l_max_len = 0;
	game->map_file = argv[1];
	game->textures = ft_calloc(4, sizeof(char *));
}
