/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:15:37 by junhyeop          #+#    #+#             */
/*   Updated: 2025/01/08 20:10:19 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minirt.h"

void	rt_init(t_data *rt, char *path)
{
	rt->mlx = mlx_init();
	if (!rt->width)
		rt->width = (float) WIN_WIDTH;
	if (!rt->height)
		rt->height = (float) WIN_HEIGHT;
	if (rt->height < rt->width)
		rt->aspectratio = rt->width / rt->height;
	else
		rt->aspectratio = rt->height / rt->width;
	rt->mlx_win = mlx_new_window(rt->mlx, rt->width, rt->height, "minirt");
	rt->path = path;
	rt->img.img = mlx_new_image(rt->mlx, rt->width, rt->height);
	rt->img.addr = mlx_get_data_addr(rt->img.img, &rt->img.bits_per_pixel,
			&rt->img.line_length, &rt->img.endian);
	rt->img.antialiasing_on = ANTIALIASING_ON;
	if (!rt->img.img)
		rt_clear(rt);
	rt->img.addr_incr = rt->img.bits_per_pixel / 8;
	hook_init(rt);
	rt->display_info = 0;
	rt->is_processing = false;
}

void	rt_clear(t_data *rt)
{
	if (rt->mlx_win)
		mlx_destroy_window(rt->mlx, rt->mlx_win);
	if (rt->img.img)
		mlx_destroy_image(rt->mlx, rt->img.img);
	if (rt->mlx)
		ft_memdel(&rt->mlx);
	rt_free(rt);
	exit(0);
}

void	rt_free(t_data *rt)
{
	if (rt)
	{
		if (rt->light)
			free_lights(&rt->light);
		if (rt->objs)
			free_objects(rt, &rt->objs);
		free(rt);
	}
}
