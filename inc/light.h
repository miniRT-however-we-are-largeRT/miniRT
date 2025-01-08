#ifndef LIGHT_H
# define LIGHT_H

t_color3    phong_lighting(t_scene *scene);
t_color3    diffuse(t_scene *scene, t_light *light);
t_vec3      reflect(t_vec3 v, t_vec3 n);
t_bool      in_shadow(t_object *objects, t_ray light_ray, double light_len);

#endif
