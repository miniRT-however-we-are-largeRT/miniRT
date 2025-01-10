/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:41:38 by jihyjeon          #+#    #+#             */
/*   Updated: 2025/01/10 14:23:37 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

// t_camera	camera(t_canvas *canvas, t_point3 orgn)
// {
// 	t_camera	cam;
// 	double		focal_len;
// 	double		viewport_height;

// 	viewport_height = 2.0;
// 	focal_len = 1.0;
// 	cam.origin = orgn;
// 	cam.viewport_h = viewport_height;
// 	cam.viewport_w = viewport_height * canvas->aspect_ratio;
// 	cam.focal_len = fov;
// 	cam.horizontal = vec3(cam.viewport_w, 0, 0);
// 	cam.vertical = vec3(0, cam.viewport_h, 0);
// 	cam.lower_left = vsub(vsub(vsub(cam.origin, vdiv_f(2, cam.horizontal)), \
// 						vdiv_f(2, cam.vertical)), vec3(0, 0, focal_len));
// 	return (cam);
// }

// t_scene *scene_init(void)
// {
// 	t_scene     *scene;
// 	t_obj    *lights;
// 	double      ka; // 8.4 에서 설명

// 	scene = (t_scene *)malloc(sizeof(t_scene));
// 	if (!scene)
// 		return (NULL);
// 	scene->canvas = canvas(600, 400);
// 	// scene->camera = camera(&scene->canvas, point3(0, 0, 0));
// 	t_obj *sphere = object_init_sphere(point3(0, 0, -5), 2, color3(0.5, 0, 0), color3(0.9, 0.3, 0.5));
// 	t_obj *plane = object_init_plane(point3(0, -2, 0), vec3(0, 1, 0), color3(0.7, 0.7, 0.7), color3(0.8, 0.8, 0.8));
// 	t_obj *cylinder = object_init_cylinder(point3(2, 0, -6), 1, 4, color3(0, 0.5, 0.8), color3(0.6, 0.4, 0.8));

// 	// 객체 연결
// 	plane->next = sphere;
// 	sphere->next = cylinder;
// 	scene->world = plane;

// 	lights = object(id_light, *light_point(point3(0, 20, 0), color3(1, 1, 1), 0.5), color3(0, 0, 0));
// 	scene->light = lights;
// 	ka = 0.1; 
// 	scene->ambient = vmult_f(ka, color3(1,1,1));
// 	return (scene);
// }