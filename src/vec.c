/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 22:08:42 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/11/07 22:11:46 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_vec3	vec3(double x, double y, double z)
{
	t_vec3	new_vec;

	new_vec.x = x;
	new_vec.y = y;
	new_vec.z = z;
	return (new_vec);
}

t_point3	point3(double x, double y, double z)
{
	t_point3	new_point;

	new_point.x = x;
	new_point.y = y;
	new_point.z = z;
	return (new_point);
}

t_color3	color3(int r, int g, int b, int t)
{
	t_color3	new_color;

	new_color.t = t;
	new_color.r = r;
	new_color.g = g;
	new_color.b = b;
	return (new_color);
}
