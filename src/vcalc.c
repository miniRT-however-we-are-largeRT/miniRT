/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vcalc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:13:30 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/11/07 22:13:26 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_vec3		vadd(t_vec3 vec1, t_vec3 vec2)
{
	vec1.x += vec2.x;
	vec1.y += vec2.y;
	vec1.z += vec2.z;
}

t_vec3		vsubtract(t_vec3 vec1, t_vec3 vec2);
t_vec3		vmult(t_vec3 vec1, t_vec3 vec2);
t_vec3		vdivide(t_vec3 vec1, double divider);
t_vec3		vlength(t_vec3 vec);