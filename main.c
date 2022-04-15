/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:12:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/15 12:16:25 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	err_mlx(t_data *game)
{
	freedirec2(game);
	free_map(game, 0);
	printf("Error\nmlx decided to fail for some reason\n");
	exit(1);
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

int	arg_check(t_data *game, int mfd)
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
	init_check(&game, argc, mfd);
	game.mlx = mlx_init();
	if (!game.mlx)
		err_mlx(&game);
	game.mlx_win = mlx_new_window
		(game.mlx, SCREEN_W, SCREEN_H, "cub3d");
	if (!game.mlx_win)
	{
		mlx_destroy_window(game.mlx, game.mlx_win);
		err_mlx(&game);
	}
	img_init(&game);
	init_map3d(&game);
	cast_rays2(&game);
	mlx_hook(game.mlx_win, 2, 0, key_hook, &game);
	mlx_hook(game.mlx_win, 17, 0, finish_game, &game);
	mlx_loop(game.mlx);
}
