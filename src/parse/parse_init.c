/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeong <junhyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:19:52 by junhyeong         #+#    #+#             */
/*   Updated: 2025/01/02 21:13:16 by junhyeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parse.h"
#include "../../lib/libft.h"

// #include "../../inc/utils.h"

void	parse_resolution(t_rt *rt, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (ft_split_size(split) != 3)
		error_handle(RT_FILE_ERROR);
	parse_float(split[1], &rt->width);
	parse_float(split[2], &rt->height);
	rt->aspectratio = rt->width / rt->height;
	ft_free_split(split);
}

void	parse_ambient(t_rt *rt, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (ft_split_size(split) != 3)
		error_handle(RT_FILE_ERROR);
	if (!parse_float(split[1], &rt->ambient.lighting))
		error_handle(RT_FILE_ERROR);
	if (!parse_color(split[2], &rt->ambient.color))
		error_handle(RT_FILE_ERROR);
	ft_free_split(split);
}

void	parse_camera(t_rt *rt, char *line)
{
	char	**split;
	t_camera	camera;

	split = ft_split(line, ' ');
	if (rt->camera.id)
		error_handle(RT_FILE_ERROR);
	ft_bzero(&camera, sizeof(t_camera));
	if (ft_split_size(split) != 4)
		error_handle(RT_FILE_ERROR);
	if (!parse_vector(split[1], &rt->camera.coords))
		error_handle(RT_FILE_ERROR);
	if (!parse_vector(split[2], &rt->camera.orient))
		error_handle(RT_FILE_ERROR);
	if (!parse_ulong(split[3], &rt->camera.fov))
		error_handle(RT_FILE_ERROR);
	rt->camera = camera;
	ft_free_split(split);
}

void	parse_light(t_rt *rt, char *line)
{
	char	**split;
	t_light	*light;

	split = ft_split(line, ' ');
	if (ft_split_size(split) != 4)
		error_handle(RT_FILE_ERROR);
	light = (t_light *)malloc(sizeof(t_light));
	if (!light)
		error_handle(MALLOC_ERROR);
	parse_vector(split[1], &light->coords);
	parse_float(split[2], &light->brightness);
	parse_color(split[3], &light->color);
	push_light(rt, light);
	ft_free_split(split);
}
