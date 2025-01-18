/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:03:36 by junhyeop          #+#    #+#             */
/*   Updated: 2025/01/18 14:50:00 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 구조체 다 때려박기

#ifndef MINIRT_H
# define MINIRT_H

# include "../lib/libft.h"
# include "../lib/mlx/mlx.h"
# include "bool.h"
# include "light.h"
# include "ray.h"
# include "struct_set.h"
# include <math.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>

# define SPP 3
# define KSN 64
# define KS 0.7
# define BRIGHTNESS 2

# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ESC 53
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define MAX_KEY 65535

# define SPECULAR_KV 0.5
# define SPECULAR_N 20
# define MIRROR 0.0
# define REFRACT 0.0
# define PATTERN_LEN 0.0
# define PATTERN_NUM 0
# define FOCAL_DIST 0.5
# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define DECO_WIDTH 60
# define COLORDEF 0x81A1C1
# define BG_COLOR 0xCFCFFF
# define WHITE 0x00FFFFFF
# define BLACK 0x0000000
# define DARKGREY 0x333333
# define MAX_KEY 65535
# define MAX_REFLECT 5
# define ANTIALIASING_ON 0
# define PROGBAR_TEXT_W 90
# define PROGBAR_TEXT_H 12
# define PROGBAR_W 180
# define PROGBAR_H 12
# define MAX_THREADS 10
# define IS_LINUX 0
# define ESC_KEY 53
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define C_KEY 5
# define I_KEY 34
# define P_KEY 35
# define L_KEY 37
# define LEFT_CLICK 1
# define RIGHT_CLICK 2

typedef struct s_event
{
	int		x;
	int		y;
	int		lastx;
	int		lasty;
	int		key[MAX_KEY];
	int		mouse;
	t_obj	*selection;
	t_bool	torender;
}			t_event;

typedef struct s_data
{
	char	*path;
	size_t	num_objs;
	void	*mlx;
	void	*mlx_win;
	t_scene	*scene;
	double	width;
	double	height;
	int		x;
	int		y;
	int		up;
	int		down;
	int		left;
	int		right;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

int			run(t_data *data);

// window.c
void		rt_clear(t_data *rt);
void		rt_free(t_data *rt);
void		rt_init(t_data *data, char *path);

// anti_alias.c
t_color3	anti_aliasing_color(t_scene *scene, int i, int j);
t_color3	average_color(t_color3 *colors, int sample_count);
double		clamp(double x, double min, double max);
double		random_double_range(double min, double max);
double		random_double(void);

// light.c
void		free_lights(t_light **light);

#endif