/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:16:52 by junhyeong         #+#    #+#             */
/*   Updated: 2025/01/10 12:41:21 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
#include "../inc/main.h"

t_data	*get_data(void)
{
	t_data	*data;
	t_scene	*scene;

	data = (t_data *)ft_calloc(sizeof(t_data), 1);
	if (!data)
		error_handle("Error: malloc error\n");
	scene = (t_scene *)ft_calloc(sizeof(t_scene), 1);
	if (!scene)
		return (NULL);
	data->scene = scene;
	return (data);
}

void	print_data(t_data *rt)
{
	t_obj *obj = rt->scene->world;
	printf("path: %s\n", rt->path);
	printf("width: %f\n", rt->width);
	printf("height: %f\n", rt->height);

	printf("camera coords: %f %f %f\n", rt->scene->camera.origin.x, rt->scene->camera.origin.y, rt->scene->camera.origin.z);
	printf("camera orient: %f %f %f\n", rt->scene->camera.dir.x, rt->scene->camera.dir.y, rt->scene->camera.dir.z);
	printf("camera fov: %lu\n", rt->scene->camera.fov);
	printf("ambient lighting: %f\n", rt->scene->ambient.lighting);
	printf("ambient color: %f %f %f\n", rt->scene->ambient.color.r, rt->scene->ambient.color.g, rt->scene->ambient.color.b);
	printf("sp: %f %f %f\n", obj->object.sphere.color.r, obj->object.sphere.center.x, obj->object.sphere.diameter);
	obj = obj->next;
	printf("pl: %f %f %f\n", obj->object.plane.color.r, obj->object.plane.coords.x, obj->object.plane.orient.x);
	obj = obj->next;
	printf("cy: %f %f %f\n", obj->object.cylinder.color.r, obj->object.cylinder.coords.x, obj->object.cylinder.orient.x);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		error_handle(ARGC_ERROR);
	data = get_data();
	if (!open_file(data, argv[1]))
		error_handle(OPEN_ERROR);
	rt_init(data, argv[1]);
	// print_data(data);
	run(data);
}