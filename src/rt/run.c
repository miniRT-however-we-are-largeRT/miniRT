/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:53:57 by junhyeop          #+#    #+#             */
/*   Updated: 2025/01/04 22:38:13 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int ft_move(t_data *data)
{
	if (data->left == 1 && data->x > 0)
	{
		data->x -= 3;
		printf("x = %d, y= %d\n", data->x, data->y);
	}
	if (data->right == 1 && data->x + 100 < data->width)
	{
		data->x += 3;
		printf("x = %d, y= %d\n", data->x, data->y);
	}
	if (data->up == 1 && data->y > 0)
	{
		data->y -= 3;
		printf("x = %d, y= %d\n", data->x, data->y);
	}
	if (data->down == 1 && data->y + 100 < data->height)
	{
		data->y += 3;
		printf("x = %d, y= %d\n", data->x, data->y);
	}
	return (0);
}

int ft_key_press(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
	if (keycode == LEFT)
		data->left = 1;
	if (keycode == RIGHT)
		data->right = 1;
	if (keycode == UP)
		data->up = 1;
	if (keycode == DOWN)
		data->down = 1;
	return (0);
}

int ft_key_release(int keycode, t_data *data)
{
	if (keycode == LEFT)
		data->left = 0;
	if (keycode == RIGHT)
		data->right = 0;
	if (keycode == UP)
		data->up = 0;
	if (keycode == DOWN)
		data->down = 0;
	return (0);
}

int ft_draw(t_data *data, t_rt *rt)
{
	int i;
	int j;
	t_canvas	canv;
	t_camera	cam;
	t_sphere	sphere;

	object_render(rt);

	canv = canvas(data->width, data->height);
	cam = camera(&canv, vec3(0, 0, 0));
	sphere.center = vec3(0, 0, -1);;
	sphere.radius = 0.5;
	sphere.radius2 = 0.5 * 0.5;
	for (j = 0; j < canv.h; j++)
    {
        for (i = 0; i < canv.w; i++)
        {
            double u = (double)i / (canv.w - 1);
            double v = (double)(canv.h - 1 - j) / (canv.h - 1);
            t_ray r = ray_primary(&cam, u, v);
            t_color3 pixel_color = ray_color(&r, &sphere);
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
	ft_move(data);
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
	data.x = 250;
	data.y = 150;
	mlx_hook(data.mlx_win, KeyPress, 1L << 0, ft_key_press, &data);
	mlx_hook(data.mlx_win, KeyRelease, 1L << 1, ft_key_release, &data);
	mlx_loop_hook(data.mlx, main_loop, &data);
	mlx_loop(data.mlx);
	return (0);
}
