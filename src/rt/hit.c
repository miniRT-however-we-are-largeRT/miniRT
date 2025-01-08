/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:17:51 by jihyjeon          #+#    #+#             */
/*   Updated: 2025/01/08 19:27:37 by junhyeop         ###   ########.fr       */
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
	c = vlen_sqr(oc) - sp->radius2;
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
	rec->normal = vdiv_f(sp->radius, vsub(rec->p, sp->center));
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
		rec->normal = pl->orient;
		rec->albedo = obj->albedo;
		set_face_normal(ray, rec);
		return (TRUE);
	}
	return (FALSE);
}

t_bool hit_cylinder(t_obj *obj, t_ray *ray, t_hit_record *rec)
{
	t_cylinder *cy = &(obj->object.cylinder);
	t_vec3 oc = vsub(ray->orig, cy->coords);
	double a = pow(ray->dir.x, 2) + pow(ray->dir.z, 2);
	double half_b = ray->dir.x * oc.x + ray->dir.z * oc.z;
	double c = pow(oc.x, 2) + pow(oc.z, 2) - pow(cy->diameter, 2);
	double dscrm = half_b * half_b - a * c;
	if (dscrm < 0)
		return (FALSE);
	double sqrtd = sqrt(dscrm);
	double root = (-half_b - sqrtd) / a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < rec->tmin || rec->tmax < root)
			return (FALSE);
	}
	rec->t = root;
	rec->p = ray_at(*ray, root);
	rec->normal = vec3(rec->p.x - cy->coords.x, 0, rec->p.z - cy->coords.z);
	rec->albedo = obj->albedo;
	set_face_normal(ray, rec);
	return (TRUE);
}

void	set_face_normal(t_ray *r, t_hit_record *rec)
{
	rec->front_face = vdot(r->dir, rec->normal) < 0;
	rec->normal = (rec->front_face) ? rec->normal : vmult_f(-1, rec->normal);
}