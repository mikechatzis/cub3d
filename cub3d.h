/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:14:39 by ekraujin          #+#    #+#             */
/*   Updated: 2022/03/27 16:48:15 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdbool.h>
# include <stdio.h> //Delete when submitting
# define UP 13 
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53

enum {
	ON_DESTROY = 17
};

typedef struct s_data
{	
	void	*mlx;
	void	*mlx_win;
	int		lc;
	int		player;
	int		**map;
	int		*fc[6];
	char	*map_file;
	int		ppos_x;
	int		ppos_y;
	char	pdir;
	char	**textures;
	char	*colors[6];
}				t_data;

// make_map.c
int		assign_map(t_data *game, int mfd);

// check_map.c
int		check_map(t_data *game);

// error.c
void	invalid_arg(t_data *game);
void	invalid_top(void);
void	invalid_map_values(void);
void	invalid_map(t_data *game);
void	free_map(t_data *game);
void	freedirec2(t_data *game);
size_t	len_no_n(char *s);
void	initialize(t_data *game, char **argv);
bool	get_textures(t_data *game, char const *line, int i);

#endif