/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:03:36 by junhyeop          #+#    #+#             */
/*   Updated: 2025/01/21 14:53:47 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_BONUS_H
# define MINIRT_BONUS_H

# include "../lib/libft.h"
# include "../lib/mlx/mlx.h"
# include "bool_bonus.h"
# include "light_bonus.h"
# include "ray_bonus.h"
# include "struct_set_bonus.h"
# include "anti_alias_bonus.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define SPP 5
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