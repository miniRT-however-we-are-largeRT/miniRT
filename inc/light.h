/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:30:57 by junhyeop          #+#    #+#             */
/*   Updated: 2025/01/12 18:13:34 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

#include "struct_set.h"

t_color3    phong_lighting(t_scene *scene);
t_color3    diffuse(t_scene *scene);
t_vec3      reflect(t_vec3 v, t_vec3 n);
t_bool      in_shadow(t_obj *objects, t_ray light_ray, double light_len);

#endif
