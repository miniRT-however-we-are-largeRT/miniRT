/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:03:36 by junhyeop          #+#    #+#             */
/*   Updated: 2025/01/18 15:43:42 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../lib/libft.h"
# include "../lib/mlx/mlx.h"
# include "bool.h"
# include "light.h"
# include "ray.h"
# include "struct_set.h"
# include "anti_alias.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define SPP 10
# define KSN 64
# define KS 0.7
# define BRIGHTNESS 2

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define MAX_KEY 65535
# define ESC_KEY 53

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

// camera.c
void		camera(t_data *data);

// light.c
void		free_lights(t_light **light);

#endif