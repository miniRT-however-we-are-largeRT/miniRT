/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec1_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:00:08 by junhyeop          #+#    #+#             */
/*   Updated: 2025/01/21 16:16:59 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vec_bonus.h"

t_vec3	vadd(const t_vec3 u, const t_vec3 v)
{
	return ((t_vec3){u.x + v.x, u.y + v.y, u.z + v.z});
}

t_vec3	vsub(const t_vec3 u, const t_vec3 v)
{
	return ((t_vec3){u.x - v.x, u.y - v.y, u.z - v.z});
}

t_vec3	vmult(const t_vec3 u, const t_vec3 v)
{
	return ((t_vec3){u.x * v.x, u.y * v.y, u.z * v.z});
}

t_vec3	vdiv(const t_vec3 u, const t_vec3 v)
{
	return ((t_vec3){u.x / v.x, u.y / v.y, u.z / v.z});
}

t_vec3	vmult_f(const double t, const t_vec3 v)
{
	return ((t_vec3){v.x * t, v.y * t, v.z * t});
}
