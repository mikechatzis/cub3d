/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:12:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/09 15:57:30 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_dir(const char *path)
{
	struct stat	path_stat;

	stat(path, &path_stat);
	return (S_ISDIR(path_stat.st_mode));
}

static int	finish_game(t_data *game)
{
	free_map(game);
	freedirec2(game);
	write(1, "Game closed!\n", 13);
	exit(0);
}

static int	key_hook(int keycode, t_data *game)
{
	if (keycode == ESC)
		finish_game(game);
	else
		move(game, keycode);
	return (0);
}

static int	arg_check(t_data *game, int mfd)
{
	char	*temp;
	int		i;
	bool	b;

	i = -1;
	if (!ft_strncmp(game->map_file
			+ (ft_strlen(game->map_file) - 5), ".cub", 5))
		return (0);
	while (++i <= 7)
	{
		temp = get_next_line(mfd);
		if (i <= 3 && ft_strcmp(temp, "\n"))
			b = get_textures(game, temp, i);
		else if (i == 5 || i == 6 && ft_strcmp(temp, "\n"))
			b = get_colors(game, temp, i);
		else if (i >= 0 && i <= 3)
		{
			free(temp);
			return (0);
		}
		free(temp);
		if (!b)
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	game;
	int		mfd;

	initialize(&game, argv);
	mfd = open(game.map_file, O_RDONLY);
	if (argc != 2 || !arg_check(&game, mfd)
		|| mfd <= 0 || is_dir(game.map_file))
		invalid_arg(&game);
	if (!assign_map(&game, mfd))
		invalid_map_values();
	if (!check_map(&game))
		invalid_map(&game);
	close(mfd);
	direction_init(&game);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window
		(game.mlx, 840, 480, "cub3d");
	// init_map3d(&game);
	draw_map(&game);
	cast_rays(&game);
	wall_colision(&game);
	mlx_hook(game.mlx_win, 2, 1L << 1, key_hook, &game);
	mlx_hook(game.mlx_win, 17, 0, finish_game, &game);
	mlx_loop(game.mlx);
}
