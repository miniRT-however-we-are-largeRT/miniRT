/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:31:03 by jihyjeon          #+#    #+#             */
/*   Updated: 2025/01/03 17:05:47 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_sphere	sphere(t_point3 center, double radius)
{
	t_sphere	sp;

	sp.center = center;
	sp.radius = radius;
	sp.radius2 = radius * radius;
	return (sp);
}

// t_object    *object(t_object_type type, void *element, t_color3 albedo)
// {
// 	t_object    *new;
//
// 	if (!(new = (t_object *)malloc(sizeof(t_object))))
// 		return (NULL);
// 	new->type = type;
// 	new->element = element;
// 	new->next = NULL;
// 	/* * * * 추가 * * * */
// 	new->albedo = albedo;
// 	/* * * * 추가 끝 * * * */
// 	return (new);
// }

t_object *object(int id, t_light light, t_color3 albedo)
{
	if (id)
		;
	t_object *obj = (t_object *)malloc(sizeof(t_object));
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

t_object *object_init_sphere(t_point3 center, double radius, t_color3 color, t_color3 albedo)
{
	t_object *obj;

	obj = (t_object *)malloc(sizeof(t_object));
	if (!obj)
		return (NULL);
	obj->id = id_sphere;
	obj->object.sphere = sphere(center, radius);
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