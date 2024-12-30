/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:38:58 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/12/30 16:41:32 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/scene.h"

t_canvas	canvas(int width, int height)
{
	t_canvas canvas;

	canvas.w = width;
	canvas.h = height;
	canvas.aspect_ratio = (double)width / (double)height;
	return(canvas);
}