/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 15:16:57 by jihyjeon          #+#    #+#             */
/*   Updated: 2025/01/18 13:46:22 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_bool	hit_cylinder_caps(t_cylinder *cy, t_ray *ray, t_hit_record *rec, double *t)
{
	t_vec3		top_center;
	t_vec3		bottom_center;
	double		t_top;
	t_vec3		p_top;
	double		t_bottom;
	t_vec3		p_bottom;

	top_center = vadd(cy->coords, vmult_f(cy->height / 2.0, cy->orient));
	bottom_center = vsub(cy->coords, vmult_f(cy->height / 2.0, cy->orient));
	t_top = vdot(vsub(top_center, ray->orig), cy->orient) / vdot(ray->dir,
			cy->orient);
	p_top = ray_at(*ray, t_top);
	if (t_top >= rec->tmin && t_top <= rec->tmax && vlen_sqr(vsub(p_top,
				top_center)) <= cy->radius * cy->radius)
	{
		*t = t_top;
		rec->p = p_top;
		rec->normal = uvec(cy->orient);
		return (TRUE);
	}
	t_bottom = vdot(vsub(bottom_center, ray->orig), cy->orient) / vdot(ray->dir,
			cy->orient);
	p_bottom = ray_at(*ray, t_bottom);
	if (t_bottom >= rec->tmin && t_bottom <= rec->tmax
		&& vlen_sqr(vsub(p_bottom, bottom_center)) <= cy->radius * cy->radius)
	{
		*t = t_bottom;
		rec->p = p_bottom;
		rec->normal = uvec(vmult_f(-1, cy->orient));
		return (TRUE);
	}
	return (FALSE);
}

t_bool	hit_cylinder_cap(t_cylinder *cy, t_ray *ray, t_hit_record *rec, double *t, int dir)
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
		*t = cap_t;
		rec->p = cap_p;
		rec->normal = uvec(vmult_f(dir, cy->orient));
		return (TRUE);
	}
	return (FALSE);
}

t_bool	dscrm_cy(t_cylinder *cy, t_ray *ray, t_hit_record *rec, t_discrm *var)
{
	double	projection;
	t_vec3	projection_point;

	var->oc = vsub(ray->orig, cy->coords);
	var->a = vlen_sqr(vcross(ray->dir, cy->orient));
	var->half_b = vdot(vcross(var->oc, cy->orient), vcross(ray->dir, cy->orient));
	var->c = vlen_sqr(vcross(var->oc, cy->orient)) - pow(cy->radius, 2);
	var->dscrm = var->half_b * var->half_b - var->a * var->c;
	if (var->dscrm < 0)
		return (FALSE);
	var->sqrtd = sqrt(var->dscrm);
	var->root = (-var->half_b - var->sqrtd) / var->a;
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
		return (CHECK);
	projection_point = vadd(cy->coords, vmult_f(projection, cy->orient));
	rec->normal = uvec(vsub(rec->p, projection_point));
	return (TRUE);
}

t_bool	hit_cylinder(t_obj *obj, t_ray *ray, t_hit_record *rec)
{
	t_cylinder	*cy;
	t_discrm	var;
	t_bool		side;
	t_bool		top_cap;
	t_bool		bottom_cap;

	cy = &(obj->object.cylinder);
	side = dscrm_cy(cy, ray, rec, &var);
	if (side == FALSE)
		return (FALSE);
	else if (side == CHECK)
	{
		top_cap = hit_cylinder_cap(cy, ray, rec, &rec->t, TOP);
		bottom_cap = hit_cylinder_cap(cy, ray, rec, &rec->t, BOTTOM);
		if (top_cap == FALSE && bottom_cap == FALSE)
			return (FALSE);
	}
	rec->albedo = obj->albedo;
	set_face_normal(ray, rec);
	return (TRUE);
}
