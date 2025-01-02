/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeong <junhyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:16:52 by junhyeong         #+#    #+#             */
/*   Updated: 2025/01/02 19:46:51 by junhyeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

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
	printf("path: %s\n", rt->path);
	printf("width: %f\n", rt->width);
	printf("height: %f\n", rt->height);
	printf("aspectratio: %f\n", rt->aspectratio);
	printf("camera coords: %f %f %f\n", rt->camera.coords.x, rt->camera.coords.y, rt->camera.coords.z);
	printf("camera orient: %f %f %f\n", rt->camera.orient.x, rt->camera.orient.y, rt->camera.orient.z);
	printf("camera fov: %lu\n", rt->camera.fov);
	printf("ambient lighting: %f\n", rt->ambient.lighting);
	printf("ambient color: %f %f %f\n", rt->ambient.color.r, rt->ambient.color.g, rt->ambient.color.b);

	// print all
	
	
}

int	main(int argc, char **argv)
{
	t_rt	*rt;

	if (argc != 2)
		error_handle(ARGC_ERROR);
	rt = get_rt();
	if (!open_file(rt, argv[1]))
		error_handle(OPEN_ERROR);
	
	print_rt(rt);
}