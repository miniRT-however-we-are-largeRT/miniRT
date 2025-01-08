/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:19:52 by junhyeong         #+#    #+#             */
/*   Updated: 2025/01/08 21:04:18 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parse.h"
#include "../../lib/libft.h"

// #include "../../inc/utils.h"

void	parse_resolution(t_data *data, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (ft_split_size(split) != 3)
		error_handle(RT_FILE_ERROR);
	parse_float(split[1], &data->width);
	parse_float(split[2], &data->height);
	ft_free_split(split);
}

void	parse_ambient(t_data *data, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (ft_split_size(split) != 3)
		error_handle(RT_FILE_ERROR);
	if (!parse_float(split[1], &data->scene->ambient.lighting))
		error_handle(RT_FILE_ERROR);
	if (!parse_color(split[2], &data->scene->ambient.color))
		error_handle(RT_FILE_ERROR);
	ft_free_split(split);
}

void	parse_camera(t_data *data, char *line)
{
	char	**split;
	t_camera	camera;

	split = ft_split(line, ' ');
	if (data->scene->camera.id)
		error_handle(RT_FILE_ERROR);
	ft_bzero(&camera, sizeof(t_camera));
	if (ft_split_size(split) != 4)
		error_handle(RT_FILE_ERROR);
	if (!parse_vector(split[1], &data->scene->camera.coords))
		error_handle(RT_FILE_ERROR);
	if (!parse_vector(split[2], &data->scene->camera.orient))
		error_handle(RT_FILE_ERROR);
	if (!parse_ulong(split[3], &data->scene->camera.fov))
		error_handle(RT_FILE_ERROR);
	data->scene->camera = camera;
	ft_free_split(split);
}

void	parse_light(t_data *data, char *line)
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
	push_light(data, light);
	ft_free_split(split);
}
