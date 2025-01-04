/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:12:06 by junhyeop          #+#    #+#             */
/*   Updated: 2025/01/04 22:17:23 by jihyjeon         ###   ########.fr       */
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

t_color3	ray_color(t_ray *r, t_object *world)
{
	t_vec3			n;
	t_hit_record	rec;

	rec.tmin = 0;
	rec.tmax = INFINITY;
	if (hit(world, r, &rec))
		return (vmult_f(0.5, vadd(rec.normal, color3(1, 1, 1))));
	return (color3(1, 0, 0));
}
