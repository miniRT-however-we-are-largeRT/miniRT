/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:01:43 by junhyeop          #+#    #+#             */
/*   Updated: 2025/01/12 18:13:34 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vec.h"

t_vec3	uvec(const t_vec3 v)
{
	return (vdiv_f(vlen(v), v));
}

t_vec3	vec3(const double x, const double y, const double z)
{
	return ((t_vec3){x, y, z});
}

// int		create_trgb(const int t, const int r, const int g, const int b)
// {
// 	return (t << 24 | r << 16 | g << 8 | b);
// }

t_color3	color3(double x, double y, double z)
{
	return ((t_color3){x, y, z});
}

t_point3	point3(double x, double y, double z)
{
	return ((t_point3){x, y, z});
}

t_point3	vmin(t_point3 a, t_point3 b)
{
	t_color3 result;

	result.x = (a.x < b.x) ? a.x : b.x;
	result.y = (a.y < b.y) ? a.y : b.y;
	result.z = (a.z < b.z) ? a.z : b.z;

	return result;
}