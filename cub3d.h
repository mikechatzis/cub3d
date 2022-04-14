/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekraujin <ekraujin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:14:39 by ekraujin          #+#    #+#             */
/*   Updated: 2022/04/14 13:16:13 by ekraujin         ###   ########.fr       */
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
# define MOVESPEED 0.10
# define ROTSPEED 0.2
# define SCREEN_W 640
# define SCREEN_H 480
# define TEX_W 64
# define TEX_H 64

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
	int		*px_clrs;
}t_img;

typedef struct s_ray
{
	int		mapx;
	int		mapy;
	int		stepx;
	int		stepy;
	bool	hit;
	int		side;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	perpwalldist;
	double	camerax;
	double	raydirx;
	double	raydiry;
}t_ray;

typedef struct s_data
{	
	void	*mlx;
	void	*mlx_win;
	t_img	*frame;
	t_img	*tex_n;
	t_img	*tex_s;
	t_img	*tex_e;
	t_img	*tex_w;
	int		lc;
	size_t	l_max_len;
	int		player;
	char	**map;
	int		*fc[6];
	char	*map_file;
	double	ppos_x;
	double	ppos_y;
	char	pdir;
	char	**textures;
	int		colors[6];
	int		linestart;
	int		lineheight;
	int		x;
	int		y;
	double	dirx;
	double	diry;
	double	olddirx;
	double	planex;
	double	planey;
	double	oldplanex;
	double	step;
	double	texpos;
	int		texx;
}				t_data;

void	cast_rays2(t_data *game);

// textures.c
void	*choose_tex(t_data *game, t_ray *ray);

// init.c
size_t	len_no_n(char *s);
void	my_mlx_pixel_put(t_data *game, int x, int y, int color);
void	initialize(t_data *game, char **argv);
void	direction_init(t_data *game);

//img_init
void	img_init(t_data *game);
void	save_textures(t_data *game);

// make_map.c
int		assign_map(t_data *game, int mfd);

//draw_map_2d.c
void	draw_map(t_data *game);
void	draw_wall(t_data *game, int x_start, int y_start, int rgb);
int		create_trgb(int t, int r, int g, int b);
void	draw_character(t_data *game, int rgb);

// draw_map_3d.c
void	init_map3d(t_data *game);
void	draw_3dmap(t_data *game, t_ray *ray, int x);

// move.c
void	move(t_data *game, int keycode);
void	cast_rays(t_data *game);
bool	wall_colision_ray(t_data *game);
bool	wall_colision_up(t_data *game);
bool	wall_colision_down(t_data *game);
bool	wall_colision_left(t_data *game);
bool	wall_colision_right(t_data *game);

// move2.c
void	cast_ray(t_data *game, size_t i);

// check_map.c
int		check_map(t_data *game);

// error.c
void	invalid_arg(t_data *game);
void	invalid_top(void);
void	invalid_map_values(void);
void	invalid_map(t_data *game);
void	free_map(t_data *game, int check);
int		finish_game(t_data *game);

// error2.c
void	freedirec2(t_data *game);
bool	get_textures(t_data *game, char const *line, int i);

// error3.c
bool	get_colors(t_data *game, char *line, int i);

#endif