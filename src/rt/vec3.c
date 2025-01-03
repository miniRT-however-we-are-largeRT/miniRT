/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:01:43 by junhyeop          #+#    #+#             */
/*   Updated: 2025/01/02 15:24:04 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vec.h"

t_vec3	uvec(const t_vec3 v)
{
	return (vdiv_f(vlen(v), v));
}

t_vec3	vec3(const double x, const double y, const double z)
{
	return ((t_vec3){x, y, z});
}

// int		create_trgb(const int t, const int r, const int g, const int b)
// {
// 	return (t << 24 | r << 16 | g << 8 | b);
// }

t_color3	color3(double x, double y, double z)
{
	return ((t_color3){x, y, z});
}
