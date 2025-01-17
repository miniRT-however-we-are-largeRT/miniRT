/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:30:57 by junhyeop          #+#    #+#             */
/*   Updated: 2025/01/17 21:41:01 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

#include "struct_set.h"

t_color3    phong_lighting(t_scene *scene);
t_color3	get_point_light(t_scene *scene, t_light *light);
t_color3	get_diffuse(t_scene *scene, t_light *light, t_light_var *var);
t_color3	get_specular(t_scene *scene, t_light_var *var);
t_vec3      reflect(t_vec3 v, t_vec3 n);
double      in_shadow(t_obj *objects, t_ray light_ray, double light_len);

#endif
