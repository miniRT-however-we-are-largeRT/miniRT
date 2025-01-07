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
	int samples_per_pixel = 30;

	scene = scene_init();
	if (!scene)
		return (0);

	for (j = 0; j < scene->canvas.h; j++)
	{
		for (i = 0; i < scene->canvas.w; i++)
		{
			t_color3 pixel_color = anti_aliasing_color(scene, i, j, samples_per_pixel);

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
		translate_camera(&scene->camera, vec3(0, 1, 0));  // 카메라 위로 이동
	else if (keycode == DOWN)
		translate_camera(&scene->camera, vec3(0, -1, 0));  // 카메라 아래로 이동
	else if (keycode == LEFT)
		rotate_camera(&scene->camera, vec3(0, 1, 0), M_PI / 18);  // 좌회전
	else if (keycode == RIGHT)
		rotate_camera(&scene->camera, vec3(0, 1, 0), -M_PI / 18);  // 우회전
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

void init_hooks(t_data *data) {
	mlx_key_hook(data->mlx_win, handle_key_input, data);  // 키 입력 처리
	mlx_loop_hook(data->mlx, main_loop, data);  // 매 프레임 렌더링}
}

int run(void)
{
	t_data data;

	data.mlx = mlx_init();
	if (!data.mlx)
	{
		ft_putendl_fd("Error: MLX initialization failed", 2);
		return (1);
	}

	data.width = 600;
	data.height = 400;
	data.mlx_win = mlx_new_window(data.mlx, data.width, data.height, "miniRT");
	if (!data.mlx_win)
	{
		ft_putendl_fd("Error: Failed to create window", 2);
		return (1);
	}

	data.img = mlx_new_image(data.mlx, data.width, data.height);
	if (!data.img)
	{
		ft_putendl_fd("Error: Failed to create image", 2);
		return (1);
	}

	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
	if (!data.addr)
	{
		ft_putendl_fd("Error: Failed to get image data address", 2);
		return (1);
	}

	data.scene = scene_init();  // 씬 초기화

	ft_draw(&data);  // 첫 프레임 렌더링
	init_hooks(&data);  // 입력 처리 연결
	mlx_loop(data.mlx);

	return (0);
}
