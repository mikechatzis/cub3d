/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:16:53 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/01 15:07:22 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*skip_space(char *s)
{
	while (*s == ' ')
		s++;
	return (s);
}

bool	isnotnum(char *s)
{
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (false);
		s++;
	}
	return (true);
}

bool	loop(t_data *game, char **clrs)
{
	unsigned short	j;

	j = -1;
	while (clrs[++j])
	{
		clrs[j] = skip_space(clrs[j]);
		if (ft_atoi(clrs[j]) < 0 || ft_atoi(clrs[j]) > 255
			|| !isnotnum(clrs[j]))
			return (false);
		game->colors[j] = ft_atoi(clrs[j]);
	}
	return (true);
}

bool	get_colors(t_data *game, char *line, int i)
{
	char			**clrs;
	unsigned short	j;

	j = -1;
	line[ft_strlen(line) - 1] = 0;
	line = skip_space(line);
	if ((i == 5 && ft_strncmp(line, "F", 1))
		|| (i == 6 && ft_strncmp(line, "C", 1)) || line[1] != ' ')
		return (false);
	line++;
	line = skip_space(line);
	clrs = ft_split(line, ',');
	if (ft_dstrlen(clrs) != 3 || !loop(game, clrs))
	{
		ft_freedstring(clrs);
		return (false);
	}
	ft_freedstring(clrs);
	return (true);
}
