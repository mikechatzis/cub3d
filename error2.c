/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:12:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/03/27 16:45:18 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	**setdirec(void)
{
	char	**direction;

	direction = ft_calloc(4, sizeof(char *));
	direction[0] = ft_strdup("NO");
	direction[1] = ft_strdup("SO");
	direction[2] = ft_strdup("WE");
	direction[3] = ft_strdup("EA");
	return (direction);
}

void	freedirec(char **s)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (s[i])
			free(s[i]);
	free(s);
}

void	freedirec2(t_data *game)
{
	int	i;

	i = -1;
	while (++i < 4)
		if (game->textures[i])
			free(game->textures[i]);
}

bool	get_textures(t_data *game, char const *line, int i)
{
	char	**direction;

	direction = setdirec();
	while (*line == ' ')
		line++;
	if (!ft_strncmp(line, direction[i], 2) && line[2] == ' ')
	{
		line += 2;
		while (*line == ' ')
			line++;
		game->textures[i] = ft_substr(line, 0, ft_strlen(line) - 1);
	}
	else
	{
		freedirec(direction);
		return (false);
	}
	freedirec(direction);
	return (true);
}
