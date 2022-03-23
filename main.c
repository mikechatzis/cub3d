/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:12:33 by ekraujin          #+#    #+#             */
/*   Updated: 2022/03/23 18:46:40 by ekraujin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	finish_game(t_data *game)
{
	free_map(game);
	write(1, "Game closed!\n", 13);
	exit(0);
}

int	key_hook(int keycode, t_data *game)
{
	if (keycode == ESC)
		finish_game(game);
	return (0);
}

int	arg_check(t_data *game, int mfd)
{
	char	*temp;
	int		i = 0;
	
	if (!ft_strncmp(game->map_file + (ft_strlen(game->map_file) - 5), ".cub", 5))
		return (0);
	while (i <= 7)
	{
		// if (i <= 3)
		// {
		// 	game->textures[i][0] = ft_split(temp, ' ')[0];
		// 	game->textures[i][1] = ft_split(temp, ' ')[1];
		// }
		temp = get_next_line(mfd);
		free(temp);
		i++;
	}
	// int j = 0;
	// while (j < 4)
	// {
	// 	printf("%s\n", game->textures[j][]);
	// 	j++;
	// }
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	game;
	int	mfd;

	game.map_file = argv[1];
	mfd = open(game.map_file, O_RDONLY);
	if (argc != 2 || !arg_check(&game, mfd) || mfd <= 0)
		invalid_arg();
	if (!assign_map(&game, mfd))
		invalid_map_values();
	if (!check_map(&game))
		invalid_map(&game);
	close(mfd);
	game.mlx = mlx_init();
	game.mlx_win = mlx_new_window(game.mlx, 1920, 1080, "cub3d");
	mlx_key_hook(game.mlx_win, key_hook, &game);
	mlx_hook(game.mlx_win, ON_DESTROY, 0, finish_game, &game);
	mlx_loop(game.mlx);
}