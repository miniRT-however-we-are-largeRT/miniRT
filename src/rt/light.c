/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:17:28 by jihyjeon          #+#    #+#             */
/*   Updated: 2025/01/18 15:26:17 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_color3	phong_lighting(t_scene *scene)
{
	t_color3	light_color;
	t_light		*lights;

	light_color = vmult_f(scene->ambient.lighting, scene->ambient.color);
	lights = scene->light;
	while (lights)
	{
		if (lights->id == id_light)
			light_color = vadd(light_color, get_point_light(scene, lights));
		lights = lights->next;
	}
	return (vmin(vmult(light_color, scene->rec.albedo), color3(1, 1, 1)));
}

t_color3	get_point_light(t_scene *scene, t_light *light)
{
	t_light_var	var;
	t_colors	phong;
	t_color3	point_light;
	t_vec3		p_normal;

	phong.diffuse = get_diffuse(scene, light, &var);
	phong.specular = get_specular(scene, &var);
	var.light_len = vlen(var.light_dir);
	p_normal = vadd(scene->rec.p, vmult_f(EPSILON, scene->rec.normal));
	var.light_ray = ray_set(p_normal, var.u_dir);
	phong.is_shadow = in_shadow(scene->world, var.light_ray, var.light_len);
	point_light = vadd(phong.specular, phong.diffuse);
	point_light = vmult_f(1 - phong.is_shadow, point_light);
	return (point_light);
}

t_color3	get_diffuse(t_scene *scene, t_light *light, t_light_var *var)
{
	double	kd;

	var->light = vmult_f(light->brightness, light->color);
	var->light_dir = vsub(light->coords, scene->rec.p);
	var->u_dir = uvec(var->light_dir);
	kd = fmax(vdot(scene->rec.normal, var->u_dir), 0.0);
	return (vmult_f(kd, var->light));
}

t_color3	get_specular(t_scene *scene, t_light_var *var)
{
	double	spec;
	t_vec3	v;
	t_vec3	n;

	var->view_dir = uvec(vmult_f(-1, scene->ray.dir));
	v = vmult_f(-1, var->u_dir);
	n = scene->rec.normal;
	var->reflect_dir = vsub(v, vmult_f(vdot(v, n) * 2, n));
	spec = pow(fmax(vdot(var->view_dir, var->reflect_dir), 0.0), KSN);
	return (vmult_f(spec, vmult_f(KS, var->light)));
}

double	in_shadow(t_obj *objects, t_ray light_ray, double light_len)
{
	t_hit_record	rec;

	rec.tmin = EPSILON;
	rec.tmax = light_len;
	if (hit(objects, &light_ray, &rec))
		return (1.0);
	return (0.0);
}
