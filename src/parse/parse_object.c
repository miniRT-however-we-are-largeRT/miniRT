/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 22:32:38 by junhyeong         #+#    #+#             */
/*   Updated: 2025/01/03 16:22:56 by junhyeop         ###   ########.fr       */
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

void	parse_cone(t_rt *rt, char **line, t_obj *obj) 
{
	(void)rt;
	(void)line;
	(void)obj;
	// char	**split;
	// t_cone	*cone;

	// split = ft_split(line, ' ');
	// if (ft_split_size(split) != 6)
	// 	error_handle(RT_FILE_ERROR);
	// cone = (t_cone *)malloc(sizeof(t_cone));
	// if (!cone)
	// 	error_handle(MALLOC_ERROR);
	// if (parse_vector(split[1], &cone->coords))
	// 	error_handle(RT_FILE_ERROR);
	// if (parse_vector(split[2], &cone->orient))
	// 	error_handle(RT_FILE_ERROR);
	// if (parse_float(split[3], &cone->angle))
	// 	error_handle(RT_FILE_ERROR);
	// if (parse_float(split[4], &cone->height))
	// 	error_handle(RT_FILE_ERROR);
	// if (parse_color(split[5], &cone->color))
	// 	error_handle(RT_FILE_ERROR);
	// ft_lstadd_back(&rt->objects, ft_lstnew(cone));
	// ft_free_split(split);
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

void	parse_triangle(char **split, t_obj *obj)
{
	t_triangle	triangle;

	ft_bzero(&triangle, sizeof(t_triangle));
	if (parse_vector(split[1], &triangle.c[0]))
		error_handle(RT_FILE_ERROR);
	if (parse_vector(split[2], &triangle.c[1]))
		error_handle(RT_FILE_ERROR);
	if (parse_vector(split[3], &triangle.c[2]))
		error_handle(RT_FILE_ERROR);
	if (parse_color(split[4], &obj->color))
		error_handle(RT_FILE_ERROR);
	triangle.color = obj->color;
	obj->object.triangle = triangle;
}

