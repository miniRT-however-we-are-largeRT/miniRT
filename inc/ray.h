/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:11:36 by junhyeop          #+#    #+#             */
/*   Updated: 2024/11/08 17:13:07 by junhyeop         ###   ########.fr       */
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

t_ray			ft_ray_set(t_point3 origin, t_vec3 direction);
t_point3		ft_ray_at(t_ray ray, double t);
#endif
