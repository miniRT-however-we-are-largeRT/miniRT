/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 13:53:57 by junhyeop          #+#    #+#             */
/*   Updated: 2025/01/14 17:03:03 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
#include "../../inc/scene.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	ft_draw(t_data *data)
{
	t_color3	pixel_color;
	int			color;
	int			i;
	int			j;

	camera(data);
	j = 0;
	while (j < data->scene->canvas.h)
	{
		i = 0;
		while (i < data->scene->canvas.w)
		{
			pixel_color = anti_aliasing_color(data->scene, i, j);

			color = ((int)(255.999 * clamp(pixel_color.x, 0.0, 0.999)) << 16);
			color += ((int)(255.999 * clamp(pixel_color.y, 0.0, 0.999)) << 8);
			color += ((int)(255.999 * clamp(pixel_color.z, 0.0, 0.999)));
			my_mlx_pixel_put(data, i, j, color);
			i++;
		}
		j++;
	}
	printf("\nRendering complete!\n");
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
	return (0);
}

int	handle_key_input(int keycode)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int	exit_hook(void)
{
	exit(0);
	return (0);
}

int	run(t_data *data)
{
	ft_draw(data);
	mlx_key_hook(data->mlx_win, handle_key_input, NULL);
	mlx_hook(data->mlx_win, 17, 0, exit_hook, NULL);
	mlx_loop(data->mlx);
	return (0);
}
