/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:16:53 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/14 20:36:52 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	get_textures_n_colors3(t_data *game, char *line)
{
	bool	b;

	b = 1;
	if (!ft_strncmp(line, "C", 1) && (line[1] == ' ' || line[1] == '\t'))
	{
		line += 1;
		line = skip_tab_n_space(line);
		b = get_colors(game, line, 6);
		game->c = 1;
	}
	else if (!ft_strncmp(line, "EA", 2) && (line[2] == ' ' || line[2] == '\t'))
	{
		line += 2;
		line = skip_tab_n_space(line);
		if (game->textures[3])
			free(game->textures[3]);
		game->textures[3] = ft_substr(line, 0, ft_strlen(line) - 1);
	}
	return (b);
}

bool	check_if_map(t_data *game, char *temp)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (!game->textures[i])
			return (0);
	if (!game->f || !game->c)
		return (0);
	return (1);
}

static bool	isnotnum(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s) && *s != ' ' && *s != '\t')
			return (false);
		s++;
	}
	return (true);
}

static bool	loop(t_data *game, char **clrs, short k)
{
	static short	j;

	j = -1;
	while (clrs[++j])
	{
		if (ft_atoi(clrs[j]) < 0 || ft_atoi(clrs[j]) > 255
			|| !isnotnum(clrs[j]))
			return (false);
		game->colors[k++] = ft_atoi(clrs[j]);
	}
	return (true);
}

bool	get_colors(t_data *game, char *line, int i)
{
	char	**clrs;
	short	k;

	if (i == 5)
		k = 0;
	else
		k = 3;
	line[ft_strlen(line) - 1] = 0;
	clrs = ft_split(line, ',');
	if (ft_dstrlen(clrs) != 3 || !loop(game, clrs, k))
	{
		ft_freedstring(clrs);
		return (false);
	}
	ft_freedstring(clrs);
	return (true);
}
