/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeong <junhyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:01:43 by junhyeop          #+#    #+#             */
/*   Updated: 2024/12/31 15:31:18 by junhyeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vec.h"

t_vec3	ft_vec_unit_vec(const t_vec3 v)
{
	return (ft_vec_div_f(ft_vec_len(v), v));
}

t_vec3	ft_vec_set_xyz(const double x, const double y, const double z)
{
	return ((t_vec3){x, y, z});
}

int		create_trgb(const int t, const int r, const int g, const int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}