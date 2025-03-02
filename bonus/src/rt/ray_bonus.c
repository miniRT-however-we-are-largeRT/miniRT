/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:12:06 by junhyeop          #+#    #+#             */
/*   Updated: 2025/01/21 16:16:55 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt_bonus.h"

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

t_hit_record	record_init(void)
{
	t_hit_record	record;

	record.tmin = EPSILON;
	record.tmax = INFINITY;
	return (record);
}

t_color3	ray_color(t_scene *scene)
{
	scene->rec = record_init();
	if (hit(scene->world, &(scene->ray), &(scene->rec)))
		return (phong_lighting(scene));
	return (color3(0, 0, 0));
}
