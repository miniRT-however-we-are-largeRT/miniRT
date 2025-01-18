/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:17:51 by jihyjeon          #+#    #+#             */
/*   Updated: 2025/01/18 14:25:52 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_bool	hit(t_obj *world, t_ray *ray, t_hit_record *rec)
{
	t_bool			hit_any;
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
	t_discrm	var;
	t_sphere	*sp;

	sp = &(obj->object.sphere);
	var.oc = vsub(ray->orig, sp->center);
	var.a = vlen_sqr(ray->dir);
	var.half_b = vdot(var.oc, ray->dir);
	var.c = vlen_sqr(var.oc) - sp->r2;
	var.dscrm = var.half_b * var.half_b - var.a * var.c;
	if (var.dscrm < 0)
		return (FALSE);
	var.sqrtd = sqrt(var.dscrm);
	var.root = (-var.half_b - var.sqrtd) / var.a;
	if (var.root < rec->tmin || rec->tmax < var.root)
	{
		var.root = (-var.half_b + var.sqrtd) / var.a;
		if (var.root < rec->tmin || rec->tmax < var.root)
			return (FALSE);
	}
	rec->t = var.root;
	rec->p = ray_at(*ray, var.root);
	rec->normal = uvec(vdiv_f(sp->radius, vsub(rec->p, sp->center)));
	rec->albedo = obj->albedo;
	set_face_normal(ray, rec);
	return (TRUE);
}

t_bool	hit_plane(t_obj *obj, t_ray *ray, t_hit_record *rec)
{
	t_plane	*pl;
	double	denom;
	double	t;

	pl = &(obj->object.plane);
	denom = vdot(pl->orient, ray->dir);
	if (fabs(denom) > EPSILON)
	{
		t = vdot(vsub(pl->coords, ray->orig), pl->orient) / denom;
		if (t < rec->tmin || t > rec->tmax)
			return (FALSE);
		rec->t = t;
		rec->p = ray_at(*ray, t);
		rec->normal = uvec(pl->orient);
		rec->albedo = obj->albedo;
		set_face_normal(ray, rec);
		return (TRUE);
	}
	return (FALSE);
}

void	set_face_normal(t_ray *r, t_hit_record *rec)
{
	rec->front_face = vdot(r->dir, rec->normal) < 0;
	if (rec->front_face)
		rec->normal = rec->normal;
	else
		rec->normal = vmult_f(-1, rec->normal);
}
