/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vcalc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:13:30 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/11/05 18:17:11 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/vec.h"

t_vec3		vadd(t_vec3 vec1, t_vec3 vec2);
t_vec3		vsubtract(t_vec3 vec1, t_vec3 vec2);
t_vec3		vmult(t_vec3 vec1, t_vec3 vec2);
t_vec3		vdivide(t_vec3 vec1, double divider);
t_vec3		vcross(t_vec3 vec1, t_vec3 vec2);