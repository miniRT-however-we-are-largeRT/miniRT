/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:29:29 by junhyeop          #+#    #+#             */
/*   Updated: 2025/01/12 18:13:34 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

#include "struct_set.h"

void translate_object(t_obj *obj, t_vec3 translation);
void translate_camera(t_camera *cam, t_vec3 translation);
t_vec3 rotate_vector(t_vec3 v, t_vec3 axis, double angle);
void rotate_object(t_obj *obj, t_vec3 axis, double angle);
void rotate_camera(t_camera *cam, t_vec3 axis, double angle);

#endif //MOVE_H
