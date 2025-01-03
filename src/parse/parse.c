/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 02:04:49 by junhyeong         #+#    #+#             */
/*   Updated: 2025/01/03 16:24:31 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parse.h"

void	parse_line(t_rt *rt, char *line)
{
	if (line[0] == 'R')
		parse_resolution(rt, line);
	else if (line[0] == 'A')
		parse_ambient(rt, line);
	else if (line[0] == 'C' && line[1] == ' ')
		parse_camera(rt, line);
	else if (line[0] == 'L')
		parse_light(rt, line);
	else if (line[0] == 's' && line[1] == 'p')
		parse_shape(rt, line, id_sphere, NB_PARAMS_SPHERE);
	else if (line[0] == 'p' && line[1] == 'l')
		parse_shape(rt, line, id_plane, NB_PARAMS_PLANE);
	else if (line[0] == 'c' && line[1] == 'o')
		parse_shape(rt, line, id_cone, NB_PARAMS_CONE);
	else if (line[0] == 'c' && line[1] == 'y')
		parse_shape(rt, line, id_cylinder, NB_PARAMS_CYLINDER);
	else if (line[0] == 't' && line[1] == 'r')
		parse_shape(rt, line, id_triangle, NB_PARAMS_TRIANGLE);
}

void	parse_shape(t_rt *rt, char *line, int id, int nb_params)
{
	t_obj	*obj;
	char	**split;
	
	split = ft_split(line, ' ');
	if (ft_split_size(split) < nb_params)
		error_handle(INVALID_SHAPE);
	obj = new_obj(id);
	if (line[0] == 's' && line[1] == 'p')
		parse_sphere(split, obj);
	else if (line[0] == 'p' && line[1] == 'l')
		parse_plane(split, obj);
	else if (line[0] == 'c' && line[1] == 'o')
		parse_cone(rt, split, obj);
	else if (line[0] == 'c' && line[1] == 'y')
		parse_cylinder(split, obj);
	else if (line[0] == 't' && line[1] == 'r')
		parse_triangle(split, obj);
	else
		error_handle("Error: invalid identifier\n");
	printf("CLEAR\n");

	push_obj(rt, obj);
	rt->num_objs++;
	ft_free_split(split);
}


