/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 22:32:38 by junhyeong         #+#    #+#             */
/*   Updated: 2025/01/21 16:16:37 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parse_bonus.h"

void	parse_sphere(char **split, t_obj *obj)
{
	t_sphere	sphere;

	ft_bzero(&sphere, sizeof(t_sphere));
	if (!parse_vector(split[1], &obj->coords))
		error_handle(RT_FILE_ERROR);
	if (!parse_double(split[2], &sphere.diameter))
		error_handle(RT_FILE_ERROR);
	if (!parse_color(split[3], &sphere.color))
		error_handle(RT_FILE_ERROR);
	sphere.id = id_sphere;
	sphere.center = obj->coords;
	sphere.radius = sphere.diameter / 2;
	sphere.r2 = sphere.radius * sphere.radius;
	obj->object.sphere = sphere;
	obj->albedo = sphere.color;
	return ;
}

void	parse_plane(char **split, t_obj *obj)
{
	t_plane	plane;

	ft_bzero(&plane, sizeof(t_plane));
	if (!parse_vector(split[1], &obj->coords))
		error_handle(RT_FILE_ERROR);
	if (!parse_vector(split[2], &plane.orient))
		error_handle(RT_FILE_ERROR);
	if (!parse_color(split[3], &plane.color))
		error_handle(RT_FILE_ERROR);
	normalize(&plane.orient);
	plane.id = id_plane;
	plane.coords = obj->coords;
	obj->object.plane = plane;
	obj->albedo = plane.color;
	return ;
}

void	parse_cylinder(char **split, t_obj *obj)
{
	t_cylinder	cylinder;

	ft_bzero(&cylinder, sizeof(t_cylinder));
	if (!parse_vector(split[1], &obj->coords))
		error_handle(RT_FILE_ERROR);
	if (!parse_vector(split[2], &cylinder.orient))
		error_handle(RT_FILE_ERROR);
	if (!parse_double(split[3], &cylinder.diameter))
		error_handle(RT_FILE_ERROR);
	if (!parse_double(split[4], &cylinder.height))
		error_handle(RT_FILE_ERROR);
	if (!parse_color(split[5], &cylinder.color))
		error_handle(RT_FILE_ERROR);
	normalize(&cylinder.orient);
	cylinder.id = id_cylinder;
	cylinder.coords = obj->coords;
	cylinder.radius = cylinder.diameter / 2;
	obj->object.cylinder = cylinder;
	obj->albedo = cylinder.color;
	return ;
}

void	parse_cone(char **split, t_obj *obj)
{
	t_cone	cone;

	ft_bzero(&cone, sizeof(t_cone));
	if (!parse_vector(split[1], &obj->coords))
		error_handle(RT_FILE_ERROR);
	if (!parse_vector(split[2], &cone.orient))
		error_handle(RT_FILE_ERROR);
	if (!parse_double(split[3], &cone.diameter))
		error_handle(RT_FILE_ERROR);
	if (!parse_double(split[4], &cone.height))
		error_handle(RT_FILE_ERROR);
	if (!parse_color(split[5], &cone.color))
		error_handle(RT_FILE_ERROR);
	normalize(&cone.orient);
	cone.id = id_cone;
	cone.coords = obj->coords;
	cone.radius = cone.diameter / 2;
	cone.r2 = cone.radius * cone.radius;
	obj->object.cone = cone;
	obj->albedo = cone.color;
	return ;
}
