/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:19:52 by junhyeong         #+#    #+#             */
/*   Updated: 2025/01/11 21:49:12 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parse.h"
#include "../../lib/libft.h"

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
	data->scene->ambient.id = id_ambient;
	ft_free_split(split);
}

void	parse_camera(t_data *data, char *line)
{
	char		**split;
	t_camera	camera;

	split = ft_split(line, ' ');
	if (data->scene->camera.id)
		error_handle(RT_FILE_ERROR);
	ft_bzero(&camera, sizeof(t_camera));
	if (ft_split_size(split) != 4)
		error_handle(RT_FILE_ERROR);
	if (!parse_vector(split[1], &camera.origin))
		error_handle(RT_FILE_ERROR);
	if (!parse_vector(split[2], &camera.dir))
		error_handle(RT_FILE_ERROR);
	if (!parse_ulong(split[3], &camera.fov))
		error_handle(RT_FILE_ERROR);
	camera.id = id_camera;
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
	light = (t_light *)ft_calloc(sizeof(t_light), 1);
	if (!light)
		error_handle(MALLOC_ERROR);
	if (!parse_vector(split[1], &light->coords))
		error_handle(RT_FILE_ERROR);
	if (!parse_float(split[2], &light->brightness))
		error_handle(RT_FILE_ERROR);
	if (!parse_color(split[3], &light->color))
		error_handle(RT_FILE_ERROR);
	light->id = id_light;
	light->albedo = color3(0.2, 0.4, 0.6);
	light->next = NULL;
	push_light(data, light);
	ft_free_split(split);
}
