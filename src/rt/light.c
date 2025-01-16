/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:17:28 by jihyjeon          #+#    #+#             */
/*   Updated: 2025/01/16 15:34:58 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_vec3	reflect(t_vec3 v, t_vec3 n)
{
	return (vsub(v, vmult_f(vdot(v, n) * 2, n)));
}

t_color3	diffuse(t_scene *scene)
{
	t_color3	diff;
	t_vec3		light_dir;
	double		light_len;
	t_ray		light_ray;
	double		kd;
	t_color3	specular;
	t_vec3		view_dir;
	t_vec3		reflect_dir;
	double		spec;
	t_light		*light;

	light = scene->light;
	light_dir = vsub(light->coords, scene->rec.p);
	light_len = vlen(light_dir);
	light_ray = ray_set(vadd(scene->rec.p, vmult_f(EPSILON, scene->rec.normal)),
			light_dir);
	if (in_shadow(scene->world, light_ray, light_len))
		return (color3(0, 0, 0));
	light_dir = uvec(light_dir);
	kd = fmax(vdot(scene->rec.normal, light_dir), 0.0);
	diff = vmult_f(kd, light->color);
	view_dir = uvec(vmult_f(-1, scene->ray.dir));
	reflect_dir = reflect(vmult_f(-1, light_dir), scene->rec.normal);
	spec = pow(fmax(vdot(view_dir, reflect_dir), 0.0), KSN);
	specular = vmult_f(spec, vmult_f(KS, light->color));
	return (vmult_f(light->brightness, vadd(diff, specular)));
}

t_color3	phong_lighting(t_scene *scene)
{
	t_color3	light_color;
	t_light		*lights;

	light_color = color3(0, 0, 0);
	lights = scene->light;
	while (lights)
	{
		if (lights->id == id_light)
			light_color = vadd(light_color, diffuse(scene));
		lights = lights->next;
	}
	light_color = vadd(light_color, vmult_f(scene->ambient.lighting,
				scene->ambient.color));
	return (vmin(vmult(light_color, scene->rec.albedo), color3(1, 1, 1)));
}

t_bool	in_shadow(t_obj *objects, t_ray light_ray, double light_len)
{
	t_hit_record	rec;

	rec.tmin = 0;
	rec.tmax = light_len;
	if (hit(objects, &light_ray, &rec))
		return (TRUE);
	return (FALSE);
}
