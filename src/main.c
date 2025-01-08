/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:16:52 by junhyeong         #+#    #+#             */
/*   Updated: 2025/01/08 19:18:50 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
#include "../../inc/main.h"

t_rt	*get_rt(void)
{
	t_rt	*rt;

	rt = (t_rt *)ft_calloc(sizeof(t_rt), 1);
	if (!rt)
		error_handle("Error: malloc error\n");
	return (rt);
}

void	print_rt(t_rt *rt)
{
	t_obj *obj = rt->objs;
	printf("path: %s\n", rt->path);
	printf("width: %f\n", rt->width);
	printf("height: %f\n", rt->height);
	printf("aspectratio: %f\n", rt->aspectratio);
	printf("camera coords: %f %f %f\n", rt->camera.coords.x, rt->camera.coords.y, rt->camera.coords.z);
	printf("camera orient: %f %f %f\n", rt->camera.orient.x, rt->camera.orient.y, rt->camera.orient.z);
	printf("camera fov: %lu\n", rt->camera.fov);
	printf("ambient lighting: %f\n", rt->ambient.lighting);
	printf("ambient color: %f %f %f\n", rt->ambient.color.r, rt->ambient.color.g, rt->ambient.color.b);
	printf("sp: %f %f %f\n", obj->object.sphere.color.r, obj->object.sphere.coords.x, obj->object.sphere.diameter);
	obj = obj->next;
	printf("pl: %f %f %f\n", obj->object.plane.color.r, obj->object.plane.coords.x, obj->object.plane.orient.x);
	obj = obj->next;
	printf("cy: %f %f %f\n", obj->object.cylinder.color.r, obj->object.cylinder.coords.x, obj->object.cylinder.orient.x);
}

int	main(int argc, char **argv)
{
	t_rt	*rt;

	if (argc != 2)
		error_handle(ARGC_ERROR);
	rt = get_rt();
	if (!open_file(rt, argv[1]))
		error_handle(OPEN_ERROR);

	rt_init(rt, argv[1]);
	print_rt(rt);
	run();
}