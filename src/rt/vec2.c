/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeong <junhyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:01:00 by junhyeop          #+#    #+#             */
/*   Updated: 2025/01/02 20:19:23 by junhyeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vec.h"
#include <math.h>

t_vec3	ft_vec_div_f(const double t, const t_vec3 v)
{
	return (ft_vec_mul_f(1 / t, v));
}

double	ft_vec_dot(const t_vec3 u, const t_vec3 v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_vec3	ft_vec_cross(const t_vec3 u, const t_vec3 v)
{
	t_vec3	result;

	result.x = u.y * v.z - u.z * v.y;
	result.y = u.z * v.x - u.x * v.z;
	result.z = u.x * v.y - u.y * v.x;
	return (result);
}

double	ft_vec_len(const t_vec3 v)
{
	return (sqrt(ft_vec_sqr_len(v)));
}

double	ft_vec_sqr_len(const t_vec3 v)
{
	return (pow(v.x, 2.0) + pow(v.y, 2.0) + pow(v.z, 2.0));
}
