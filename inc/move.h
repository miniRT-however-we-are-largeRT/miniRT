#ifndef MOVE_H
# define MOVE_H

void translate_object(t_object *obj, t_vec3 translation);
void translate_camera(t_camera *cam, t_vec3 translation);
t_vec3 rotate_vector(t_vec3 v, t_vec3 axis, double angle);
void rotate_object(t_object *obj, t_vec3 axis, double angle);
void rotate_camera(t_camera *cam, t_vec3 axis, double angle);

#endif //MOVE_H
