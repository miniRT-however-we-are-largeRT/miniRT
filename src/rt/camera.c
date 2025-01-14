/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:38:58 by jihyjeon          #+#    #+#             */
/*   Updated: 2025/01/14 17:25:58 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

void	set_viewport_value(t_scene *scene)
{
	double		viewport_height;

	viewport_height = 2 * tan((scene->camera.fov * M_PI / 180) / 2);
	scene->camera.focal_len = 1.0;
	scene->camera.viewport_h = viewport_height;
	scene->camera.viewport_w = viewport_height * scene->canvas.aspect_ratio;
}

void	set_uvw(t_camera *cam)
{
	cam->w = uvec(vmult_f(-1, cam->dir));
	cam->u = uvec(vcross(vec3(0, 1, 0), cam->w));
	cam->v = vcross(cam->w, cam->u);
}

void	draw_viewport(t_camera *cam)
{
	t_vec3	h_move;
	t_vec3	wh_move;

	cam->horizontal = vmult_f(cam->viewport_w, cam->u);
	cam->vertical = vmult_f(cam->viewport_h, cam->v);
	h_move = vsub(cam->origin, vdiv_f(2, cam->horizontal));
	wh_move = vsub(h_move, vdiv_f(2, cam->vertical));
	cam->lower_left = vsub(wh_move, vmult_f(cam->focal_len, cam->w));
}

void	camera(t_data *data)
{
	set_viewport_value(data->scene);
	set_uvw(&(data->scene->camera));
	draw_viewport(&(data->scene->camera));
}
