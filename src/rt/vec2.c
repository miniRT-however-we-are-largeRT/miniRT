/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:01:00 by junhyeop          #+#    #+#             */
/*   Updated: 2025/01/12 18:13:34 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vec.h"

t_vec3	vdiv_f(const double t, const t_vec3 v)
{
	return (vmult_f(1 / t, v));
}

double	vdot(const t_vec3 u, const t_vec3 v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_vec3	vcross(const t_vec3 u, const t_vec3 v)
{
	t_vec3	result;

	result.x = u.y * v.z - u.z * v.y;
	result.y = u.z * v.x - u.x * v.z;
	result.z = u.x * v.y - u.y * v.x;
	return (result);
}

double	vlen(const t_vec3 v)
{
	return (sqrt(vlen_sqr(v)));
}

double	vlen_sqr(const t_vec3 v)
{
	return (pow(v.x, 2.0) + pow(v.y, 2.0) + pow(v.z, 2.0));
}
