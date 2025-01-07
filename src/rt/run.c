/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:53:57 by junhyeop          #+#    #+#             */
/*   Updated: 2025/01/04 22:21:29 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int ft_draw(t_data *data) // sce
{
	int i, j;
	t_scene	*scene;

	scene = scene_init();
	if (!scene)
		return (0);

	for (j = 0; j < scene->canvas.h; j++)
	{
		for (i = 0; i < scene->canvas.w; i++)
		{
			double u = (double)i / (scene->canvas.w - 1);
			double v = (double)(scene->canvas.h - 1 - j) / (scene->canvas.h - 1);
			scene->ray = ray_primary(&scene->camera, u, v);
			t_color3 pixel_color = ray_color(scene);

			int color = ((int)(255.999 * pixel_color.x) << 16) |
						((int)(255.999 * pixel_color.y) << 8) |
						((int)(255.999 * pixel_color.z));
			my_mlx_pixel_put(data, i, j, color);
		}
	}

	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}

int main_loop(t_data *data)
{
	ft_draw(data);
	return (0);
}

int run(void)
{
	t_data data;

	data.mlx = mlx_init();
	data.width = 600;
	data.height = 400;
	data.mlx_win = mlx_new_window(data.mlx, data.width, data.height, "miniRT");
	data.img = mlx_new_image(data.mlx, 600, 400);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_loop_hook(data.mlx, main_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
