/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:17:51 by jihyjeon          #+#    #+#             */
/*   Updated: 2025/01/04 22:16:13 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_bool	hit(t_object *world, t_ray *ray, t_hit_record *rec)
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

t_bool	hit_obj(t_object *obj, t_ray *ray, t_hit_record *rec)
{
	t_bool	hit_result;

	hit_result = FALSE;
	if (world->id == id_sphere)
		hit_result = hit_sphere(world, ray, rec);
	return (hit_result);
}

t_bool	hit_sphere(t_sphere *sp, t_ray *ray, t_hit_record *rec)
{
	t_vec3	oc;
	double	a;
	double	half_b;
	double	c;
	double	dscrm;
	double	sqrtd;
	double	root;

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
	set_face_normal(ray, rec);
	return (TRUE);
}

void	set_face_normal(t_ray *r, t_hit_record *rec)
{
	rec->front_face = vdot(r->dir, rec->normal) < 0;
    rec->normal = (rec->front_face) ? rec->normal : vmult_f(-1, rec->normal);
}