/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:12:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/14 20:34:35 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*skip_empty_lines(t_data *game, int mfd, char *temp)
{
	int	i;

	while (1)
	{
		i = 0;
		temp = get_next_line(mfd);
		game->ltm++;
		while (temp[i] == ' ' || temp[i] == '\t' || temp[i] == '\n')
			i++;
		if (!temp[i])
			free(temp);
		else
			break ;
	}
	return (temp);
}

char	*skip_tab_n_space(char *s)
{
	while (*s == ' ' || *s == '\t')
		s++;
	return (s);
}

void	freedirec2(t_data *game)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (game->textures[i])
			free(game->textures[i]);
}

static bool	get_textures_n_colors2(t_data *game, char *line)
{
	bool	b;

	b = 1;
	if (!ft_strncmp(line, "WE", 2) && (line[2] == ' ' || line[2] == '\t'))
	{
		line += 2;
		line = skip_tab_n_space(line);
		if (game->textures[2])
			free(game->textures[2]);
		game->textures[2] = ft_substr(line, 0, ft_strlen(line) - 1);
	}
	else if (!ft_strncmp(line, "F", 1) && (line[1] == ' ' || line[1] == '\t'))
	{
		line += 1;
		line = skip_tab_n_space(line);
		b = get_colors(game, line, 5);
		game->f = 1;
	}
	else
		b = get_textures_n_colors3(game, line);
	return (b);
}

bool	get_textures_n_colors(t_data *game, char *line)
{
	bool	b;

	b = true;
	line = skip_tab_n_space(line);
	if (!ft_strncmp(line, "NO", 2) && (line[2] == ' ' || line[2] == '\t'))
	{
		line += 2;
		line = skip_tab_n_space(line);
		if (game->textures[0])
			free(game->textures[0]);
		game->textures[0] = ft_substr(line, 0, ft_strlen(line) - 1);
	}
	else if (!ft_strncmp(line, "SO", 2) && (line[2] == ' ' || line[2] == '\t'))
	{
		line += 2;
		line = skip_tab_n_space(line);
		if (game->textures[1])
			free(game->textures[1]);
		game->textures[1] = ft_substr(line, 0, ft_strlen(line) - 1);
	}
	else
		b = get_textures_n_colors2(game, line);
	return (b);
}
