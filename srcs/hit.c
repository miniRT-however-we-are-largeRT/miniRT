/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 16:17:51 by jihyjeon          #+#    #+#             */
/*   Updated: 2025/01/03 17:05:44 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"


double	hit_sphere(t_sphere *sp, t_ray *ray)
{
	t_vec3	oc;
	double	a;
	double	b;
	double	c;
	double	dscrm;

	oc = vsub(ray->orig, sp->center);
	a = vdot(ray->dir, ray->dir);
	b = 2.0 * vdot(oc, ray->dir);
	c = vdot(oc, oc) - sp->radius2;
	dscrm = b * b - 4 * a * c;
	if (dscrm < 0)
		return (-1.0);
	else
		return ((-b - sqrt(dscrm)) /  (2.0 * a));
}