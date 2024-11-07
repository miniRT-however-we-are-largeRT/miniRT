/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:27:25 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/11/07 22:11:17 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

typedef struct s_vec3	t_vec3;
typedef struct s_vec3	t_point3;
typedef struct s_color3	t_color3;

struct s_vec3
{
	double	x;
	double	y;
	double	z;
};

struct	s_color3
{
	int	t;
	int	r;
	int	g;
	int	b;
};

t_vec3		vec3(double x, double y, double z);
t_point3	point3(double x, double y, double z);
t_color3	color3(int r, int g, int b, int t);
double		vdot(t_vec3 vec1, t_vec3 vec2);
t_vec3		vcross(t_vec3 vec1, t_vec3 vec2);
t_vec3		vunit(t_vec3 vec);
t_vec3		vadd(t_vec3 vec1, t_vec3 vec2);
t_vec3		vsubtract(t_vec3 vec1, t_vec3 vec2);
t_vec3		vmult(t_vec3 vec1, t_vec3 vec2);
t_vec3		vdivide(t_vec3 vec1, double divider);
t_vec3		vlength(t_vec3 vec);
#endif