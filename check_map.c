/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:04:24 by ekraujin          #+#    #+#             */
/*   Updated: 2022/03/25 17:09:21 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_top_n_bot(t_data *game, int line)
{
	int	i;

	i = 0;
	while (game->map[line][i] && game->map[line][i] != '\n')
	{
		if (game->map[line][i] != '1' && game->map[line][i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	line_check(t_data *game, int line)
{
	int	i;

	i = 0;
	if (game->map[line][i] != ' ' && game->map[line][i] != '1')
		return (0);
	i = 1;
	while (game->map[line][i] && game->map[line][i] != '\n')
	{
		if (game->map[line][i] == ' ' && game->map[line][i] != ' ' \
			&& game->map[line][i] != '1')
			return (0);
		while (game->map[line][i] == ' ')
			i++;
		if (game->map[line][i - 1] == ' ' && game->map[line][i] != '1')
			return (0);
		if (game->map[line][i] == '0' && \
		((game->map[line - 1][i] != '1' && game->map[line - 1][i] != '0') \
		|| (game->map[line + 1][i] != '1' && game->map[line + 1][i] != '0')))
			return(0);
		i++;
	}
	if (game->map[line][i - 1] != ' ' && game->map[line][i - 1] != '1')
		return (0);
	return (1);
}

int	check_map(t_data *game)
{
	int	i;

	i = 0;
	if (!check_top_n_bot(game, i))
		return (0);
	i = 1;
	while (i < game->lc)
	{
		if (!line_check(game, i))
			return (0);
		i++;
	}
	game->map[game->ppos_y][game->ppos_x] = game->pdir;
	return (1);
}