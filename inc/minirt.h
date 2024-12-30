/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:03:36 by junhyeop          #+#    #+#             */
/*   Updated: 2024/12/27 16:51:00 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H
# include "../lib/mlx/mlx.h"
# include "../lib/libft/libft.h"
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

int	run(void);

#endif