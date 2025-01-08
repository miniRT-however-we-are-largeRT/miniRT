/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:11:36 by junhyeop          #+#    #+#             */
/*   Updated: 2025/01/08 19:17:04 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "minirt.h"
# include "vec.h"

t_ray			ray_set(t_point3 origin, t_vec3 direction);
t_point3		ray_at(t_ray ray, double t);
t_ray			ray_primary(t_camera *cam, double u, double v);
t_color3		ray_color(t_scene *scene);
t_bool			hit(t_object *obj, t_ray *ray, t_hit_record *rec);
t_bool			hit_obj(t_object *obj, t_ray *ray, t_hit_record *rec);
t_bool			hit_sphere(t_object *obj, t_ray *ray, t_hit_record *rec);
t_bool hit_cylinder(t_object *obj, t_ray *ray, t_hit_record *rec);
t_bool hit_plane(t_object *obj, t_ray *ray, t_hit_record *rec);
void			set_face_normal(t_ray *r, t_hit_record *rec);

#endif
