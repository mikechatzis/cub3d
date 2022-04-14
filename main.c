/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:12:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/14 20:39:06 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_dir(const char *path)
{
	struct stat	path_stat;

	stat(path, &path_stat);
	return (S_ISDIR(path_stat.st_mode));
}

int	finish_game(t_data *game)
{
	free_map(game, 1);
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
	bool	b;

	b = 1;
	if (!ft_strncmp(game->map_file
			+ (ft_strlen(game->map_file) - 5), ".cub", 5))
		return (0);
	while (b)
	{
		temp = skip_empty_lines(game, mfd, temp);
		if (!check_validity(temp))
		{
			free(temp);
			break ;
		}
		else
			b = get_textures_n_colors(game, temp);
		free(temp);
	}
	b = check_if_map(game, temp);
	if (!b)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	game;
	int		mfd;

	initialize(&game, argv);
	mfd = open(game.map_file, O_RDONLY);
	if (argc != 2 || mfd <= 0 || is_dir(game.map_file)
		|| !arg_check(&game, mfd))
		invalid_arg(&game);
	if (!assign_map(&game, mfd))
		invalid_map_values();
	if (!check_map(&game))
		invalid_map(&game);
	close(mfd);
	direction_init(&game);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window
		(game.mlx, SCREEN_W, SCREEN_H, "cub3d");
	img_init(&game);
	init_map3d(&game);
	cast_rays2(&game);
	mlx_hook(game.mlx_win, 2, 0, key_hook, &game);
	mlx_hook(game.mlx_win, 17, 0, finish_game, &game);
	mlx_loop(game.mlx);
}
