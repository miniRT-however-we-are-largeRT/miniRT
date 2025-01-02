/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeong <junhyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:00:08 by junhyeop          #+#    #+#             */
/*   Updated: 2024/12/31 15:31:03 by junhyeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vec.h"

t_vec3	ft_vec_add(const t_vec3 u, const t_vec3 v)
{
	return ((t_vec3){u.x + v.x, u.y + v.y, u.z + v.z});
}

t_vec3	ft_vec_sub(const t_vec3 u, const t_vec3 v)
{
	return ((t_vec3){u.x - v.x, u.y - v.y, u.z - v.z});
}

t_vec3	ft_vec_mul(const t_vec3 u, const t_vec3 v)
{
	return ((t_vec3){u.x * v.x, u.y * v.y, u.z * v.z});
}

t_vec3	ft_vec_div(const t_vec3 u, const t_vec3 v)
{
	return ((t_vec3){u.x / v.x, u.y / v.y, u.z / v.z});
}

t_vec3	ft_vec_mul_f(const double t, const t_vec3 v)
{
	return ((t_vec3){v.x * t, v.y * t, v.z * t});
}
