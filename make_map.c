/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:40:41 by ekraujin          #+#    #+#             */
/*   Updated: 2022/03/27 17:19:55 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"	

void	get_to_map(int mfd)
{
	int		i;
	char	*temp;

	i = -1;
	while (++i < 8)
	{
		temp = get_next_line(mfd);
		free(temp);
	}
}

void	make_line(t_data *game, char *temp, int mfd, int i)
{	
	size_t	len;
	int		j;

	len = len_no_n(temp);
	game->map[i] = malloc(len * sizeof(size_t));
	j = -1;
	while (++j <= len)
	{
		game->map[i][j] = (int)temp[j];
		if (i == game->ppos_y && j == game->ppos_x)
			game->map[i][j] = '0';
	}
}

void	make_array(t_data *game)
{
	int		i;
	size_t	j;
	int		mfd;
	char	*temp;
	size_t	len;

	i = -1;
	len = 0;
	game->map = malloc(game->lc * sizeof(int *));
	mfd = open(game->map_file, O_RDONLY);
	get_to_map(mfd);
	temp = get_next_line(mfd);
	i = 0;
	while (temp)
	{
		make_line(game, temp, mfd, i);
		free(temp);
		temp = get_next_line(mfd);
		i++;
	}
	close(mfd);
}

int	line_val_check(t_data *game, char *line)
{
	int	i;

	i = 0;
	if (line[i] == '\n')
	{
		free(line);
		return (0);
	}
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == 'N' || line[i] == 'E'
			|| line[i] == 'S' || line[i] == 'W')
		{
			game->ppos_y = game->lc;
			game->ppos_x = i;
			game->pdir = (int)line[i];
			++game->player;
		}
		else if (line[i] != '1' && line[i] != '0' && line[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	assign_map(t_data *game, int mfd)
{
	char	*temp;

	game->lc = 0;
	game->player = 0;
	temp = get_next_line(mfd);
	while (temp)
	{
		if (!line_val_check(game, temp))
			return (0);
		free(temp);
		temp = get_next_line(mfd);
		++game->lc;
	}
	free(temp);
	close(mfd);
	if (game->player != 1)
		return (0);
	make_array(game);
	return (1);
}
