/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:35:36 by jihyjeon          #+#    #+#             */
/*   Updated: 2025/01/02 16:16:36 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "structure.h"

t_canvas	canvas(int w, int h);
t_camera	camera(t_canvas *canvas, t_point3 origin);
t_sphere	sphere(t_point3 center, double radius);

#endif