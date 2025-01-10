/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:53:57 by junhyeop          #+#    #+#             */
/*   Updated: 2025/01/10 14:22:12 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int ft_draw(t_data *data)
{
	int i, j;
	int samples_per_pixel = 10;

	for (j = 0; j < data->scene->canvas.h; j++)
	{
		for (i = 0; i < data->scene->canvas.w; i++)
		{
			t_color3 pixel_color = anti_aliasing_color(data->scene, i, j, samples_per_pixel);

			int color = ((int)(255.999 * clamp(pixel_color.x, 0.0, 0.999)) << 16) |
						((int)(255.999 * clamp(pixel_color.y, 0.0, 0.999)) << 8) |
						((int)(255.999 * clamp(pixel_color.z, 0.0, 0.999)));

			my_mlx_pixel_put(data, i, j, color);
		}
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}

int handle_key_input(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int run(t_data *data)
{
	ft_draw(data);
	mlx_key_hook(data->mlx_win, handle_key_input, NULL);
	mlx_loop(data->mlx);
	return (0);
}
