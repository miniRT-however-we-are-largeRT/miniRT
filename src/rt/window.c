/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:15:37 by junhyeop          #+#    #+#             */
/*   Updated: 2025/01/18 15:02:07 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
#include "../../inc/utils.h"

void	rt_init(t_data *data, char *path)
{
	data->mlx = mlx_init();
	if (!data->width)
		data->width = (double) WIN_WIDTH;
	if (!data->height)
		data->height = (double) WIN_HEIGHT;
	if (data->height < data->width)
		data->scene->canvas.aspect_ratio = data->width / data->height;
	else
		data->scene->canvas.aspect_ratio = data->height / data->width;
	data->scene->canvas.w = data->width;
	data->scene->canvas.h = data->height;
	data->mlx_win = mlx_new_window(data->mlx, data->width, \
									data->height, "miniRT");
	data->path = path;
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	if (!data->img)
		rt_clear(data);
}

void	rt_clear(t_data *data)
{
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->mlx)
		free(data->mlx);
	rt_free(data);
	exit(0);
}

void	rt_free(t_data *data)
{
	if (data)
	{
		if (data->scene->light)
			free_lights(&data->scene->light);
		if (data->scene->world)
			free_objs(&data);
		free(data);
	}
}
