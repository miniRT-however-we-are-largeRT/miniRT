/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:31:03 by jihyjeon          #+#    #+#             */
/*   Updated: 2025/01/10 12:46:01 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_sphere	sphere(t_point3 center, double radius)
{
	t_sphere	sp;

	sp.center = center;
	sp.radius = radius;
	sp.r2 = radius * radius;
	return (sp);
}

// t_obj    *object(t_obj_type type, void *element, t_color3 albedo)
// {
// 	t_obj    *new;
//
// 	if (!(new = (t_obj *)malloc(sizeof(t_obj))))
// 		return (NULL);
// 	new->type = type;
// 	new->element = element;
// 	new->next = NULL;
// 	/* * * * 추가 * * * */
// 	new->albedo = albedo;
// 	/* * * * 추가 끝 * * * */
// 	return (new);
// }

t_obj *object(int id, t_light light, t_color3 albedo)
{
	if (id)
		;
	t_obj *obj = (t_obj *)malloc(sizeof(t_obj));
	if (!obj)
		return (NULL);
	obj->id = id_light;
	obj->object.light = *light_point(light.origin, light.light_color, light.bright_ratio);
	// 광원 위치
	obj->color = light.light_color;  // 광원의 색상
	obj->albedo = albedo;  // 더미 albedo
	obj->next = NULL;
	return (obj);
}

t_obj *object_init_sphere(t_point3 center, double radius, t_color3 color, t_color3 albedo)
{
	t_obj *obj;

	obj = (t_obj *)malloc(sizeof(t_obj));
	if (!obj)
		return (NULL);
	obj->id = id_sphere;
	obj->object.sphere = sphere(center, radius);
	obj->color = color;
	obj->albedo = albedo;
	obj->next = NULL;
	return (obj);
}

t_obj *object_init_plane(t_point3 coords, t_vec3 orient, t_color3 color, t_color3 albedo)
{
	t_obj *obj = (t_obj *)malloc(sizeof(t_obj));
	if (!obj)
		return (NULL);
	obj->id = id_plane;
	obj->object.plane.coords = coords;
	obj->object.plane.orient = orient;
	obj->color = color;
	obj->albedo = albedo;
	obj->next = NULL;
	return (obj);
}

t_obj *object_init_cylinder(t_point3 coords, double radius, double height, t_color3 color, t_color3 albedo)
{
	t_obj *obj = (t_obj *)malloc(sizeof(t_obj));
	if (!obj)
		return (NULL);
	obj->id = id_cylinder;
	obj->object.cylinder.coords = coords;
	obj->object.cylinder.diameter = radius;
	obj->object.cylinder.height = height;
	obj->color = color;
	obj->albedo = albedo;
	obj->next = NULL;
	return (obj);
}

t_light	*light_point(t_point3 light_origin, t_color3 light_color, double bright_ratio)
{
	t_light	*light;

	light = (t_light *)malloc(sizeof(t_light));
	if (!light)
		return (0);
	light->origin = light_origin;
	light->light_color = light_color;
	light->bright_ratio = bright_ratio;
	return (light);
}