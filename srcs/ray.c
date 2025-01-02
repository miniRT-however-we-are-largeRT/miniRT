/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:12:06 by junhyeop          #+#    #+#             */
/*   Updated: 2025/01/02 15:32:59 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ray.h"

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

t_color3	ray_color(t_ray *r)
{
	double	t;

	t = 0.5 * (r->dir.y + 1.0);
	return (vadd(vmult_f(1.0 - t, color3(1, 1, 1)), \
				vmult_f(t, color3(0.5, 0.7, 1.0))));
}
