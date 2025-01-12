/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:17:51 by jihyjeon          #+#    #+#             */
/*   Updated: 2025/01/12 18:13:34 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_bool	hit(t_obj *world, t_ray *ray, t_hit_record *rec)
{
	t_bool	hit_any;
	t_hit_record	tmp_rec;

	tmp_rec = *rec;
	hit_any = FALSE;
	while (world)
	{
		if (hit_obj(world, ray, &tmp_rec))
		{
			hit_any = TRUE;
			tmp_rec.tmax = tmp_rec.t;
			*rec = tmp_rec;
		}
		world = world->next;
	}
	return (hit_any);
}

t_bool	hit_obj(t_obj *world, t_ray *ray, t_hit_record *rec)
{
	t_bool	hit_result;

	hit_result = FALSE;
	if (world->id == id_sphere)
		hit_result = hit_sphere(world, ray, rec);
	else if (world->id == id_plane)
		hit_result = hit_plane(world, ray, rec);
	else if (world->id == id_cylinder)
		hit_result = hit_cylinder(world, ray, rec);
	return (hit_result);
}

t_bool	hit_sphere(t_obj *obj, t_ray *ray, t_hit_record *rec)
{
	t_vec3	oc;
	double	a;
	double	half_b;
	double	c;
	double	dscrm;
	double	sqrtd;
	double	root;
	t_sphere	*sp;

	sp = &(obj->object.sphere);
	oc = vsub(ray->orig, sp->center);
	a = vlen_sqr(ray->dir);
	half_b = vdot(oc, ray->dir);
	c = vlen_sqr(oc) - sp->r2;
	dscrm = half_b * half_b - a * c;
	if (dscrm < 0)
		return (FALSE);
	sqrtd = sqrt(dscrm);
	root = (-half_b - sqrtd) / a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
	}
	rec->t = root;
	rec->p = ray_at(*ray, root);
	rec->normal = uvec(vdiv_f(sp->radius, vsub(rec->p, sp->center)));
	rec->p = vadd(rec->p, vmult_f(fabs(EPSILON), rec->normal));
	rec->albedo = obj->albedo;
	set_face_normal(ray, rec);
	return (TRUE);
}

t_bool hit_plane(t_obj *obj, t_ray *ray, t_hit_record *rec)
{
	t_plane *pl = &(obj->object.plane);
	double denom = vdot(pl->orient, ray->dir);
	if (fabs(denom) > EPSILON)
	{
		double t = vdot(vsub(pl->coords, ray->orig), pl->orient) / denom;
		if (t < rec->tmin || t > rec->tmax)
			return (FALSE);
		rec->t = t;
		rec->p = ray_at(*ray, t);
		rec->normal = uvec(pl->orient);
			rec->p = vadd(rec->p, vmult_f(fabs(EPSILON), rec->normal));
		rec->albedo = obj->albedo;
		set_face_normal(ray, rec);
		return (TRUE);
	}
	return (FALSE);
}

t_bool hit_cylinder_caps(t_obj *obj, t_ray *ray, t_hit_record *rec, double *t)
{
    t_cylinder *cy = &(obj->object.cylinder);

    t_vec3 top_center = vadd(cy->coords, vmult_f(cy->height / 2.0, cy->orient));
    t_vec3 bottom_center = vsub(cy->coords, vmult_f(cy->height / 2.0, cy->orient));

    double t_top = vdot(vsub(top_center, ray->orig), cy->orient) / vdot(ray->dir, cy->orient);
    t_vec3 p_top = ray_at(*ray, t_top);
    if (t_top >= rec->tmin && t_top <= rec->tmax &&
        vlen_sqr(vsub(p_top, top_center)) <= cy->radius * cy->radius)
    {
        *t = t_top;
        rec->p = p_top;
        rec->normal = uvec(cy->orient);
        rec->albedo = obj->albedo;
        return (TRUE);
    }

    double t_bottom = vdot(vsub(bottom_center, ray->orig), cy->orient) / vdot(ray->dir, cy->orient);
    t_vec3 p_bottom = ray_at(*ray, t_bottom);
    if (t_bottom >= rec->tmin && t_bottom <= rec->tmax &&
        vlen_sqr(vsub(p_bottom, bottom_center)) <= cy->radius * cy->radius)
    {
        *t = t_bottom;
        rec->p = p_bottom;
        rec->normal = uvec(vmult_f(-1, cy->orient));
			rec->p = vadd(rec->p, vmult_f(fabs(EPSILON), rec->normal));

        rec->albedo = obj->albedo;
        return (TRUE);
    }

    return (FALSE);
}

t_bool hit_cylinder(t_obj *obj, t_ray *ray, t_hit_record *rec)
{
    t_cylinder *cy = &(obj->object.cylinder);
    t_vec3 oc = vsub(ray->orig, cy->coords);

    double a = vlen_sqr(vcross(ray->dir, cy->orient));
    double half_b = vdot(vcross(oc, cy->orient), vcross(ray->dir, cy->orient));
    double c = vlen_sqr(vcross(oc, cy->orient)) - pow(cy->radius, 2);
    double dscrm = half_b * half_b - a * c;

    if (dscrm < 0)
        return (FALSE);

    double sqrtd = sqrt(dscrm);
    double root = (-half_b - sqrtd) / a;
    if (root < rec->tmin || root > rec->tmax)
    {
        root = (-half_b + sqrtd) / a;
        if (root < rec->tmin || root > rec->tmax)
            return (FALSE);
    }

    // 측면 교차점 판별
    rec->t = root;
    rec->p = ray_at(*ray, root);
    double projection = vdot(vsub(rec->p, cy->coords), cy->orient);
    if (projection < -cy->height / 2.0 || projection > cy->height / 2.0)
        return (hit_cylinder_caps(obj, ray, rec, &rec->t)); // 뚜껑과 교차 여부 확인

    // 측면 노멀 계산
    t_vec3 projection_point = vadd(cy->coords, vmult_f(projection, cy->orient));
    rec->normal = uvec(vsub(rec->p, projection_point));	
		rec->p = vadd(rec->p, vmult_f(fabs(EPSILON), rec->normal));
    rec->albedo = obj->albedo;
    set_face_normal(ray, rec);
    return (TRUE);
}

void	set_face_normal(t_ray *r, t_hit_record *rec)
{
	rec->front_face = vdot(r->dir, rec->normal) < 0;
	rec->normal = (rec->front_face) ? rec->normal : vmult_f(-1, rec->normal);
}