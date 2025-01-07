/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:41:38 by jihyjeon          #+#    #+#             */
/*   Updated: 2025/01/03 16:38:45 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_camera	camera(t_canvas *canvas, t_point3 orgn)
{
	t_camera	cam;
	double		focal_len;
	double		viewport_height;

	viewport_height = 2.0;
	focal_len = 1.0;
	cam.origin = orgn;
	cam.viewport_h = viewport_height;
	cam.viewport_w = viewport_height * canvas->aspect_ratio;
	cam.focal_len = focal_len;
	cam.horizontal = vec3(cam.viewport_w, 0, 0);
	cam.vertical = vec3(0, cam.viewport_h, 0);
	cam.lower_left = vsub(vsub(vsub(cam.origin, vdiv_f(2, cam.horizontal)), \
						vdiv_f(2, cam.vertical)), vec3(0, 0, focal_len));
	return (cam);
}

t_scene *scene_init(void)
{
	t_scene     *scene;
	t_object    *world;
	t_object    *lights;
	double      ka; // 8.4 에서 설명

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene->canvas = canvas(600, 400);
	scene->camera = camera(&scene->canvas, point3(0, 0, 0));
	world = object_init_sphere(point3(0, 0, -5), 2, color3(0.5, 0, 0), color3(0.9, 0.3, 0.5));
	scene->world = world;
	lights = object(id_light, *light_point(point3(0, 5, 0), color3(1, 1, 1), 0.5), color3(0, 0, 0));
	scene->light = lights;
	ka = 0.1; // 8.4 에서 설명
	scene->ambient = vmult_f(ka, color3(1,1,1)); // 8.4 에서 설명
	return (scene);
}