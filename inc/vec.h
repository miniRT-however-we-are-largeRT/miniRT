/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:17:38 by junhyeop          #+#    #+#             */
/*   Updated: 2024/12/30 21:12:38 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

typedef struct s_vec3
{
	float        x;
	float        y;
	float        z;
}              t_vec3;

typedef struct	s_t
{
	double		min;
	double		max;
}				t_t;
typedef struct	s_coef
{
	double		a;
	double		half_b;
	double		c;
}				t_coef;

t_vec3			vadd(const t_vec3 u, const t_vec3 v);
t_vec3			vsub(const t_vec3 u, const t_vec3 v);
t_vec3			vmult(const t_vec3 u, const t_vec3 v);
t_vec3			vdiv(const t_vec3 u, const t_vec3 v);
t_vec3			vmult_f(const double t, const t_vec3 v);
t_vec3			vdiv_f(const double t, const t_vec3 v);
double			vdot(const t_vec3 u, const t_vec3 v);
t_vec3			vcross(const t_vec3 u, const t_vec3 v);
double			vlen(const t_vec3 v);
double			vlen_sqr(const t_vec3 v);
t_vec3			uvec(const t_vec3 v);
t_vec3			vec3(const double x, const double y, const double z);
int				create_trgb(const int t, const int r, const int g, const int b);
typedef t_vec3	t_point3;
typedef t_vec3	t_color;

#endif