/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:40:41 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/14 20:22:50 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"	

static void	get_to_map(t_data *game, int mfd)
{
	int		i;
	char	*temp;

	i = -1;
	while (++i < game->ltm - 1)
	{
		temp = get_next_line(mfd);
		free(temp);
	}
}

static void	make_line(t_data *game, char *temp, int mfd, int i)
{	
	size_t	len;
	int		j;

	len = len_no_n(temp);
	if (len > game->l_max_len)
		game->l_max_len = len;
	game->map[i] = ft_calloc(len + 1, sizeof(char));
	j = -1;
	while (++j <= len)
	{
		game->map[i][j] = temp[j];
		if (i == game->ppos_y && j == game->ppos_x)
			game->map[i][j] = '0';
	}
}

static void	make_array(t_data *game)
{
	int		i;
	size_t	j;
	int		mfd;
	char	*temp;
	size_t	len;

	i = -1;
	len = 0;
	game->map = ft_calloc(game->lc + 1, sizeof(char *));
	mfd = open(game->map_file, O_RDONLY);
	get_to_map(game, mfd);
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

static int	line_val_check(t_data *game, char *line)
{
	int	i;

	i = -1;
	if (line[i] == '\n')
	{
		free(line);
		return (0);
	}
	while (line[++i] && line[i] != '\n')
	{
		if (line[i] == 'N' || line[i] == 'E'
			|| line[i] == 'S' || line[i] == 'W')
		{
			game->ppos_y = game->lc;
			game->ppos_x = i;
			game->pdir = line[i];
			++game->player;
		}
		else if (line[i] != '1' && line[i] != '0' && line[i] != ' ')
		{
			free(line);
			return (0);
		}
	}
	return (1);
}

int	assign_map(t_data *game, int mfd)
{
	char	*temp;

	close(mfd);
	mfd = open(game->map_file, O_RDONLY);
	get_to_map(game, mfd);
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
