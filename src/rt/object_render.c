/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_render.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 22:22:11 by junhyeop          #+#    #+#             */
/*   Updated: 2025/01/08 19:01:58 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "vec.h"

// void	cylinder_set(t_cylinder *cy)
// {
// 	normalize(&cy->orient);
// 	cy->r2 = cy->diameter * cy->diameter * 0.25;
// 	cy->delta_p = (cy->orient, cy->height);
// 	cy->p1 = vect_mul(cy->orient, -0.5 * cy->height);
// 	cy->p1 = vect_add(cy->p1, cy->coords);
// 	cy->p2 = vect_mul(cy->orient, 0.5 * cy->height);
// 	cy->p2 = vect_add(cy->p2, cy->coords);
// }

// void	object_render(t_rt *rt)
// {
// 	t_obj	*objs;

// 	objs = rt->objs;
// 	rt->aspectratio = (float) rt->width / rt->height;
// 	rt->img.addr = rt->img.bits_per_pixel / 8;
	
// 	while (objs)
// 	{
// 		if (objs->id == id_sphere)
// 			objs->object.sphere.r2 = pow(objs->object.sphere.diameter / 2, 2);
// 		if (objs->id == id_cylinder)
// 			cylinder_set(&objs->object.cylinder);
// 		objs = objs->next;
// 	}
// }