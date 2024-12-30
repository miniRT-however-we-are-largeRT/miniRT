/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:11:36 by junhyeop          #+#    #+#             */
/*   Updated: 2024/12/30 21:13:49 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H
# include "vec.h"

typedef struct	s_ray
{
	t_point3	orig;
	t_vec3		dir;
}				t_ray;

t_ray			ray_set(t_point3 origin, t_vec3 direction);
t_point3		ray_at(t_ray ray, double t);
#endif
