/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:35:36 by jihyjeon          #+#    #+#             */
/*   Updated: 2025/01/03 17:04:52 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "minirt.h"

t_scene     *scene_init(void);
t_canvas	canvas(int w, int h);
t_camera	camera(t_canvas *canvas, t_point3 origin);
t_sphere	sphere(t_point3 center, double radius);
// t_object    *object(t_object_type type, void *element, t_color3 albedo);
t_object *object(int id, t_light light, t_color3 albedo); // temp object init
t_object    *object_init_sphere(t_point3 center, double radius, t_color3 color, t_color3 albedo);
t_light	    *light_point(t_point3 light_origin, t_color3 light_color, double bright_ratio);


#endif