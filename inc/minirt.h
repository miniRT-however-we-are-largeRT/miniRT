/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:03:36 by junhyeop          #+#    #+#             */
/*   Updated: 2025/01/04 22:10:37 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 구조체 다 때려박기

#ifndef MINIRT_H
# define MINIRT_H

# include "../lib/libft.h"
// # include "struct_set.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include "bool.h"
# include "../lib/mlx/mlx.h"
# include "vec.h"
# include "structure.h"
# include "ray.h"
# include "scene.h"
# include "light.h"
# include "anti_alias.h"
# include "move.h"

# define	UP          126
# define	DOWN        125
# define	LEFT        123
# define	RIGHT       124
# define 	ESC         53
# define 	KeyPress    2
# define 	KeyRelease  3
# define 	MAX_KEY     65535

// typedef struct s_event
// {
// 	int		x;
// 	int		y;
// 	int		lastx;
// 	int		lasty;
// 	int		key[MAX_KEY];
// 	int		mouse;
// 	t_obj	*selection;
// 	t_bool	torender;
// }	t_event;

// typedef struct s_rt
// {
// 	char			*path;
// 	float			width;
// 	float			height;
// 	float			aspectratio;
// 	float			cam_matrix[4][4];
// 	void			*mlx;
// 	void			*mlx_win;
// 	t_img			img;
// 	t_camera		camera;
// 	t_ambient		ambient;
// 	t_light			*light;
// 	t_obj			*objs;
// 	size_t			num_objs;
// 	t_event			event;
// 	int				display_info;
// 	t_color			bg_color;
// 	int				lnum;
// 	int				pnum;
// 	int				process;
// 	pthread_mutex_t	process_lock;
// 	char			*process_text;
// 	t_bool			is_processing;
// }	t_rt;

// typedef struct s_line_trd
// {
// 	int			i;
// 	t_rt		*rt;
// 	pthread_t	trd;
// }	t_line_trd;

typedef struct 	s_data
{
	void    *mlx;
	void    *mlx_win;
	t_scene	*scene;
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

#endif