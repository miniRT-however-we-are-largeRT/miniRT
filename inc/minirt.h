/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeong <junhyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:03:36 by junhyeop          #+#    #+#             */
/*   Updated: 2024/12/31 02:00:12 by junhyeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// 구조체 다 때려박기

#ifndef MINIRT_H
# define MINIRT_H
# include "../minilibx_mms_20200219/mlx.h"
# include "../lib/libft.h"
# include <stdio.h>
# include <stdlib.h>

# define	UP          126
# define	DOWN        125
# define	LEFT        123
# define	RIGHT       124
# define 	ESC         53
# define 	KeyPress    2
# define 	KeyRelease  3

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

typedef struct 	s_rt
{
	t_data		*data;
	
}               t_rt;

#endif