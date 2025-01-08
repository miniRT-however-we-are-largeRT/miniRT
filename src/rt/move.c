#include "../../inc/minirt.h"

void translate_object(t_obj *obj, t_vec3 translation)
{
    if (obj->id == id_plane)
        obj->object.plane.coords = vadd(obj->object.plane.coords, translation);
    else if (obj->id == id_cylinder)
        obj->object.cylinder.coords = vadd(obj->object.cylinder.coords, translation);
}

void translate_camera(t_camera *cam, t_vec3 translation)
{
    cam->origin = vadd(cam->origin, translation);
    cam->lower_left = vadd(cam->lower_left, translation);
}

t_vec3 rotate_vector(t_vec3 v, t_vec3 axis, double angle)
{
    double cos_a = cos(angle);
    double sin_a = sin(angle);
    t_vec3 cross = vcross(axis, v);
    double dot = vdot(axis, v);

    return vadd(vadd(vmult_f(cos_a, v), vmult_f(sin_a, cross)), vmult_f((1 - cos_a) * dot, axis));
}

void rotate_object(t_obj *obj, t_vec3 axis, double angle)
{
    if (obj->id == id_plane)
    {
        obj->object.plane.orient = rotate_vector(obj->object.plane.orient, axis, angle);
    }
    else if (obj->id == id_cylinder)
    {
        obj->object.cylinder.orient = rotate_vector(obj->object.cylinder.orient, axis, angle);
    }
}

void rotate_camera(t_camera *cam, t_vec3 axis, double angle)
{
    cam->u = rotate_vector(cam->u, axis, angle);
    cam->v = rotate_vector(cam->v, axis, angle);
    cam->w = rotate_vector(cam->w, axis, angle);
}