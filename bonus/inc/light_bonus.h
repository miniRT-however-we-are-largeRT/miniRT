/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:30:57 by junhyeop          #+#    #+#             */
/*   Updated: 2025/01/21 14:53:52 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_BONUS_H
# define LIGHT_BONUS_H

# include "struct_set_bonus.h"

t_color3	phong_lighting(t_scene *scene);
t_color3	get_point_light(t_scene *scene, t_light *light);
t_color3	get_diffuse(t_scene *scene, t_light *light, t_light_var *var);
t_color3	get_specular(t_scene *scene, t_light_var *var);
double		in_shadow(t_obj *objects, t_ray light_ray, double light_len);

#endif
