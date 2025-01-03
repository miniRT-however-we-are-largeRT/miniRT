/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:12:06 by junhyeop          #+#    #+#             */
/*   Updated: 2025/01/03 17:05:50 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_ray	ray_set(t_point3 origin, t_vec3 direction)
{
	t_ray	target;

	target.orig = origin;
	target.dir = direction;
	return (target);
}

t_point3	ray_at(t_ray ray, double t)
{
	t_point3	target;

	target = vec3(
			ray.orig.x + t * ray.dir.x,
			ray.orig.y + t * ray.dir.y,
			ray.orig.z + t * ray.dir.z);
	return (target);
}

t_ray	ray_primary(t_camera *cam, double u, double v)
{
	t_ray	ray;

	ray.orig = cam->origin;
	ray.dir = uvec(vsub(vadd(vadd(cam->lower_left, \
		vmult_f(u, cam->horizontal)), vmult_f(v, cam->vertical)), cam->origin));
	return (ray);
}

t_color3	ray_color(t_ray *r, t_sphere *sphere)
{
	t_bool	t;
	t_vec3	n;
	t_hit_record	rec;

	rec.tmin = 0;
	rec.tmax = INFINITY;
	t = hit_sphere(sphere, r, &rec);
	if (t == TRUE)
	{
		n = uvec(vsub(ray_at(*r, t), sphere->center));
		return (vmult_f(0.5, color3(n.x + 1, n.y + 1, n.z + 1)));
	}
	return (color3(1, 0, 0));
}
