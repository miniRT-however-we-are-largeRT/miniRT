/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeong <junhyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 22:32:38 by junhyeong         #+#    #+#             */
/*   Updated: 2025/01/09 17:29:18 by junhyeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parse.h"

void	parse_sphere(char **split, t_obj *obj)
{
	t_sphere	sphere;

	ft_bzero(&sphere, sizeof(t_sphere));
	if (!parse_vector(split[1], &obj->coords))
		error_handle(RT_FILE_ERROR);
	if (!parse_float(split[2], &sphere.diameter))
		error_handle(RT_FILE_ERROR);
	if (!parse_color(split[3], &obj->color))
		error_handle(RT_FILE_ERROR);
	sphere.coords = obj->coords;
	obj->object.sphere = sphere;
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
	if (!parse_color(split[3], &obj->color))
		error_handle(RT_FILE_ERROR);
	normalize(&plane.orient);
	plane.coords = obj->coords;
	obj->object.plane = plane;
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
	if (!parse_float(split[3], &cylinder.diameter))
		error_handle(RT_FILE_ERROR);
	if (!parse_float(split[4], &cylinder.height))
		error_handle(RT_FILE_ERROR);
	if (!parse_color(split[5], &cylinder.color))
		error_handle(RT_FILE_ERROR);
	normalize(&cylinder.orient);
	cylinder.coords = obj->coords;
	obj->object.cylinder = cylinder;
	return ;
}
