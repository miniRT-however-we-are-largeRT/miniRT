/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_alias.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:25:29 by junhyeop          #+#    #+#             */
/*   Updated: 2025/01/14 16:57:45 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

double	random_double(void)
{
	return (rand() / (RAND_MAX + 1.0));
}

double	random_double_range(double min, double max)
{
	return (min + (max - min) * random_double());
}

double	clamp(double x, double min, double max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}

t_color3	average_color(t_color3 *colors, int sample_count)
{
	t_color3	avg_color;
	int			i;

	i = 0;
	avg_color = color3(0, 0, 0);
	while (i < sample_count)
	{
		avg_color = vadd(avg_color, colors[i]);
		i++;
	}
	return (vmult_f(1.0 / sample_count, avg_color));
}

t_color3	anti_aliasing_color(t_scene *scene, int i, int j)
{
	t_color3	pixel_color;
	int			h;
	int			s;
	double		u;
	double		v;

	s = 0;
	pixel_color = color3(0, 0, 0);
	h = scene->canvas.h;
	while (s < SPP)
	{
		u = ((double)i + random_double()) / (scene->canvas.w - 1);
		v = ((double)(h - 1 - j) + random_double()) / (h - 1);
		scene->ray = ray_primary(&scene->camera, u, v);
		pixel_color = vadd(pixel_color, ray_color(scene));
		s++;
	}
	return (vmult_f(1.0 / SPP, pixel_color));
}
