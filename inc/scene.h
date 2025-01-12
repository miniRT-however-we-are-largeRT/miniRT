/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:35:36 by jihyjeon          #+#    #+#             */
/*   Updated: 2025/01/12 18:13:34 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "minirt.h"

t_scene     *scene_init(void);
t_canvas	canvas(int w, int h);
void	    camera(t_data *data);
t_sphere	sphere(t_point3 center, double radius);
t_obj *object(int id, t_light light, t_color3 albedo); // temp object init
t_obj    *object_init_sphere(t_point3 center, double radius, t_color3 color, t_color3 albedo);
t_obj *object_init_plane(t_point3 coords, t_vec3 orient, t_color3 color, t_color3 albedo);
t_obj *object_init_cylinder(t_point3 coords, double radius, double height, t_color3 color, t_color3 albedo);
t_light	    *light_point(t_point3 light_origin, t_color3 light_color, double bright_ratio);


#endif