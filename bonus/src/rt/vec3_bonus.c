/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:01:43 by junhyeop          #+#    #+#             */
/*   Updated: 2025/01/21 16:17:03 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vec_bonus.h"

t_vec3	uvec(const t_vec3 v)
{
	return (vdiv_f(vlen(v), v));
}

t_vec3	vec3(const double x, const double y, const double z)
{
	return ((t_vec3){x, y, z});
}

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
	t_color3	result;

	if (a.x < b.x)
		result.x = a.x;
	else
		result.x = b.x;
	if (a.y < b.y)
		result.y = a.y;
	else
		result.y = b.y;
	if (a.z < b.z)
		result.z = a.z;
	else
		result.z = b.z;
	return (result);
}
