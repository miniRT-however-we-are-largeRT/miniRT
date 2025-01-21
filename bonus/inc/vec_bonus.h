/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 14:17:38 by junhyeop          #+#    #+#             */
/*   Updated: 2025/01/21 14:53:25 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_BONUS_H
# define VEC_BONUS_H

# include <math.h>

typedef struct s_point3
{
	double			x;
	double			y;
	double			z;
}					t_point3;

typedef struct s_t
{
	double			min;
	double			max;
}					t_t;

typedef struct s_coef
{
	double			a;
	double			half_b;
	double			c;
}					t_coef;

typedef t_point3	t_vec3;
typedef t_point3	t_color3;
t_vec3				vadd(const t_vec3 u, const t_vec3 v);
t_vec3				vsub(const t_vec3 u, const t_vec3 v);
t_vec3				vmult(const t_vec3 u, const t_vec3 v);
t_vec3				vdiv(const t_vec3 u, const t_vec3 v);
t_vec3				vmult_f(const double t, const t_vec3 v);
t_vec3				vdiv_f(const double t, const t_vec3 v);
double				vdot(const t_vec3 u, const t_vec3 v);
t_vec3				vcross(const t_vec3 u, const t_vec3 v);
double				vlen(const t_vec3 v);
double				vlen_sqr(const t_vec3 v);
t_vec3				uvec(const t_vec3 v);
t_point3			vmin(t_point3 a, t_point3 b);
t_vec3				vup(t_vec3 vec);
t_vec3				vec3(const double x, const double y, const double z);
t_color3			color3(double x, double y, double z);
t_point3			point3(double x, double y, double z);
#endif