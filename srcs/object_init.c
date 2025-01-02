/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:31:03 by jihyjeon          #+#    #+#             */
/*   Updated: 2025/01/02 15:35:25 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/structure.h"

t_sphere	sphere(t_point3 center, double radius)
{
	t_sphere	sp;

	sp.center = center;
	sp.radius = radius;
	sp.radius2 = radius * radius;
	return (sp);
}
