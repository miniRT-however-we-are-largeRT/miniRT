/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:03:36 by junhyeop          #+#    #+#             */
/*   Updated: 2025/01/08 19:11:15 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 구조체 다 때려박기

#ifndef MINIRT_H
# define MINIRT_H

# include "../lib/libft.h"
# include "struct_set.h"
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include "../lib/mlx/mlx.h"

# define	UP          126
# define	DOWN        125
# define	LEFT        123
# define	RIGHT       124
# define 	ESC         53
# define 	KeyPress    2
# define 	KeyRelease  3
# define 	MAX_KEY     65535

# define EPSILON 0.0001
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
# define ANTIALIASING_ON false
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
}	t_event;

typedef struct s_rt
{
	char			*path;
	float			width;
	float			height;
	float			aspectratio;
	float			cam_matrix[4][4];
	void			*mlx;
	void			*mlx_win;
	t_img			img;
	t_camera		camera;
	t_ambient		ambient;
	t_light			*light;
	t_obj			*objs;
	size_t			num_objs;
	t_event			event;
	int				display_info;
	t_color			bg_color;
	int				lnum;
	int				pnum;
	int				process;
	pthread_mutex_t	process_lock;
	char			*process_text;
	t_bool			is_processing;
}	t_rt;

typedef struct s_line_trd
{
	int			i;
	t_rt		*rt;
	pthread_t	trd;
}	t_line_trd;

typedef struct 	s_data
{
	void    *mlx;
	void    *mlx_win;
	int     width, height;
	int     x, y;
	int     up, down, left, right;
	void    *img;
	char    *addr;
	int     bits_per_pixel;
	int     line_length;
	int     endian;
}               t_data;

int	run(void);

// window.c
void	rt_init(t_rt *rt, char *path);
void	rt_clear(t_rt *rt);
void	rt_free(t_rt *rt);

void	object_render(t_rt *rt);


#endif