/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:16:57 by jihyjeon          #+#    #+#             */
/*   Updated: 2025/01/21 19:44:43 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_bool	hit_cylinder_cap(t_cylinder *cy, t_ray *ray, t_hit_record *rec, int dir)
{
	t_vec3		center;
	double		cap_t;
	t_vec3		cap_p;

	center = vadd(cy->coords, vmult_f(dir * cy->height / 2.0, cy->orient));
	cap_t = vdot(vsub(center, ray->orig), cy->orient) / vdot(ray->dir,
			cy->orient);
	cap_p = ray_at(*ray, cap_t);
	if (cap_t >= rec->tmin && cap_t <= rec->tmax && vlen_sqr(vsub(cap_p,
				center)) <= cy->radius * cy->radius)
	{
		rec->t = cap_t;
		rec->p = cap_p;
		rec->tmax = rec->t;
		rec->normal = uvec(vmult_f(dir, cy->orient));
		return (TRUE);
	}
	return (FALSE);
}

void	dscrm_cy(t_cylinder *cy, t_ray *ray, t_discrm *var)
{
	t_vec3	cr_rcy;

	cr_rcy = vcross(ray->dir, cy->orient);
	var->oc = vsub(ray->orig, cy->coords);
	var->a = vlen_sqr(cr_rcy);
	var->half_b = vdot(vcross(var->oc, cy->orient), cr_rcy);
	var->c = vlen_sqr(vcross(var->oc, cy->orient)) - pow(cy->radius, 2);
	var->dscrm = var->half_b * var->half_b - var->a * var->c;
	var->sqrtd = sqrt(var->dscrm);
	var->root = (-var->half_b - var->sqrtd) / var->a;
}

t_bool	hit_cylinder_side(t_cylinder *cy, t_discrm *var, t_hit_record *rec, \
							t_ray *ray)
{
	double	projection;
	t_vec3	projection_point;

	if (var->dscrm < 0)
		return (FALSE);
	if (var->root < rec->tmin || var->root > rec->tmax)
	{
		var->root = (-var->half_b + var->sqrtd) / var->a;
		if (var->root < rec->tmin || var->root > rec->tmax)
			return (FALSE);
	}
	rec->t = var->root;
	rec->p = ray_at(*ray, var->root);
	projection = vdot(vsub(rec->p, cy->coords), cy->orient);
	if (projection < -cy->height / 2.0 || projection > cy->height / 2.0)
		return (FALSE);
	projection_point = vadd(cy->coords, vmult_f(projection, cy->orient));
	rec->normal = uvec(vsub(rec->p, projection_point));
	return (TRUE);
}

t_bool	hit_cylinder(t_obj *obj, t_ray *ray, t_hit_record *rec)
{
	t_cylinder	*cy;
	t_discrm	var;
	t_cyl_hit	hit;

	cy = &(obj->object.cylinder);
	dscrm_cy(cy, ray, &var);
	hit.top_cap = hit_cylinder_cap(cy, ray, rec, TOP);
	hit.bottom_cap = hit_cylinder_cap(cy, ray, rec, BOTTOM);
	hit.side = hit_cylinder_side(cy, &var, rec, ray);
	if (hit.top_cap == FALSE && hit.bottom_cap == FALSE && hit.side == FALSE)
		return (FALSE);
	rec->albedo = obj->albedo;
	set_face_normal(ray, rec);
	return (TRUE);
}
