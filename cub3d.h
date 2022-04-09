/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:14:39 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/09 15:34:05 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include  <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdbool.h>
# include <stdio.h> //Delete when submitting
# define UP 13 
# define DOWN 1
# define LEFT 0
# define RIGHT 2
# define ESC 53
# define STRAFE_L 123
# define STRAFE_R 124
# define PI 3.14159265359

typedef struct s_ray
{
	int		mapx;
	int		mapy;
	short	stepx;
	short	stepy;
	bool	hit;
	bool	side;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
}t_ray;

typedef struct s_data
{	
	void	*mlx;
	void	*mlx_win;
	int		lc;
	size_t	l_max_len;
	int		player;
	char	**map;
	int		*fc[6];
	char	*map_file;
	int		ppos_x;
	int		ppos_y;
	double	angle;
	char	pdir;
	char	**textures;
	int		colors[6];
	int		x;
	int		y;
	double	dirx;
	double	diry;
	double	olddirx;
	size_t	raylen;
	int		xstart;
}				t_data;

// init.c
size_t	len_no_n(char *s);
void	initialize(t_data *game, char **argv);
void	direction_init(t_data *game);

// make_map.c
int		assign_map(t_data *game, int mfd);

//draw_map_2d.c
void	draw_map(t_data *game);
void	draw_wall(t_data *game, int x_start, int y_start, int rgb);
int		create_trgb(int t, int r, int g, int b);
void	draw_character(t_data *game, int rgb);

// draw_map_3d.c
void	init_map3d(t_data *game);
void	draw_3dmap(t_data *game, t_ray *ray);

// move.c
void	move(t_data *game, int keycode);
void	cast_rays(t_data *game);
bool	wall_colision_ray(t_data *game);
bool	wall_colision(t_data *game);

// move2.c
void	cast_ray(t_data *game);

// check_map.c
int		check_map(t_data *game);

// error.c
void	invalid_arg(t_data *game);
void	invalid_top(void);
void	invalid_map_values(void);
void	invalid_map(t_data *game);
void	free_map(t_data *game);

// error2.c
void	freedirec2(t_data *game);
bool	get_textures(t_data *game, char const *line, int i);

// error3.c
bool	get_colors(t_data *game, char *line, int i);

#endif