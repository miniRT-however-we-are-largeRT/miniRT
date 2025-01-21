/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:51:44 by jihyjeon          #+#    #+#             */
/*   Updated: 2025/01/21 14:33:46 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_bool	hit_cone_cap(t_cone *co, t_ray *ray, t_hit_record *rec)
{
	t_vec3	center;
	double	cap_t;
	t_vec3	cap_p;

	center = co->coords;
	cap_t = vdot(vsub(center, ray->orig), co->orient) / vdot(ray->dir,
			co->orient);
	cap_p = ray_at(*ray, cap_t);
	if (cap_t >= rec->tmin && cap_t <= rec->tmax && vlen_sqr(vsub(cap_p,
				center)) <= co->radius * co->radius)
	{
		rec->t = cap_t;
		rec->p = cap_p;
		rec->normal = uvec(co->orient);
		return (TRUE);
	}
	return (FALSE);
}

void	dscrm_cone(t_cone *co, t_ray *ray, t_discrm *var)
{
	double	h_ratio;
	t_vec3	oc;

	h_ratio = co->r2 / (co->height * co->height);
	oc = vsub(ray->orig, co->coords);
	var->oc = oc;
	var->a = vdot(ray->dir, ray->dir) - vdot(ray->dir, co->orient)
		* vdot(ray->dir, co->orient) * (1 + h_ratio);
	var->half_b = vdot(ray->dir, oc) - vdot(oc, co->orient) * vdot(ray->dir,
			co->orient) * (1 + h_ratio) + h_ratio * co->height * vdot(ray->dir,
			co->orient);
	var->c = vdot(oc, oc) - vdot(oc, co->orient) * vdot(oc, co->orient) * (1
			+ h_ratio) - co->r2 + 2 * h_ratio * co->height * vdot(oc,
			co->orient);
	var->dscrm = var->half_b * var->half_b - var->a * var->c;
	var->sqrtd = sqrt(var->dscrm);
	var->root = (-var->half_b - var->sqrtd) / var->a;
}

void	get_cone_normal(t_hit_record *rec, t_cone *co, double proj)
{
	double	scalar;
	t_vec3	vec;
	t_vec3	height;

	proj = co->height - proj;
	scalar = vdot(vsub(rec->p, co->coords), co->orient);
	vec = vsub(rec->p, vadd(co->coords, vmult_f(scalar, co->orient)));
	rec->normal = uvec(vec);
	height = vmult_f(co->radius * proj / co->height, co->orient);
	rec->normal = uvec(vadd(height, vmult_f(proj, rec->normal)));
}

t_bool	hit_cone_side(t_cone *cone, t_discrm *var, t_ray *ray, \
						t_hit_record *rec)
{
	double		projection;

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
	projection = vdot(vsub(rec->p, cone->coords), cone->orient);
	if (projection > cone->height)
		return (FALSE);
	else if (projection < 0)
		return (CHECK);
	get_cone_normal(rec, cone, projection);
	return (TRUE);
}

t_bool	hit_cone(t_obj *obj, t_ray *ray, t_hit_record *rec)
{
	t_cone		*cone;
	t_discrm	var;
	t_bool		side;

	cone = &(obj->object.cone);
	dscrm_cone(cone, ray, &var);
	side = hit_cone_side(cone, &var, ray, rec);
	if (side == FALSE)
		return (FALSE);
	else if (side == CHECK)
	{
		if (hit_cone_cap(cone, ray, rec) == FALSE)
			return (FALSE);
	}
	rec->albedo = obj->albedo;
	set_face_normal(ray, rec);
	return (TRUE);
}
