/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:53:57 by junhyeop          #+#    #+#             */
/*   Updated: 2025/01/08 19:19:43 by junhyeop         ###   ########.fr       */
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
	int samples_per_pixel = 10;

	for (j = 0; j < data->scene->canvas.h; j++)
	{
		for (i = 0; i < data->scene->canvas.w; i++)
		{
			t_color3 pixel_color = anti_aliasing_color(data->scene, i, j, samples_per_pixel);

			// 색상값을 0~255 범위로 변환
			int color = ((int)(255.999 * clamp(pixel_color.x, 0.0, 0.999)) << 16) |
						((int)(255.999 * clamp(pixel_color.y, 0.0, 0.999)) << 8) |
						((int)(255.999 * clamp(pixel_color.z, 0.0, 0.999)));

			my_mlx_pixel_put(data, i, j, color);
		}
	}

	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}

int handle_key_input(int keycode, t_data *data)
{
	t_scene *scene = data->scene;

	if (keycode == UP)
		translate_camera(&scene->camera, vec3(0, 10, 0));  // 카메라 위로 이동
	else if (keycode == DOWN)
		translate_camera(&scene->camera, vec3(0, -10, 0));  // 카메라 아래로 이동
	else if (keycode == LEFT)
		rotate_camera(&scene->camera, vec3(0, 10, 0), M_PI / 3);  // 좌회전
	else if (keycode == RIGHT)
		rotate_camera(&scene->camera, vec3(0, 10, 0), -M_PI / 18);  // 우회전
	else if (keycode == 53)  // ESC 키
		exit(0);

	mlx_clear_window(data->mlx, data->mlx_win);
	ft_draw(data);
	return (0);
}

int main_loop(t_data *data)
{
	ft_draw(data);
	return (0);
}

int	exit_hook(void)
{
	exit(0);
	return (0);
}

int run(t_data *data)
{
	mlx_key_hook(data->mlx_win, handle_key_input, data);
	mlx_hook(data->mlx_win, 17, 0, exit_hook, data);
	mlx_loop(data->mlx);
	return (0);
}
