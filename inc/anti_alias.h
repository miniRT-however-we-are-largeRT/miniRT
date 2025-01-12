/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anti_alias.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:31:28 by junhyeop          #+#    #+#             */
/*   Updated: 2025/01/12 18:13:34 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANTI_ALIAS_H
# define ANTI_ALIAS_H

#include "struct_set.h"

double random_double(void);
double random_double_range(double min, double max);
double clamp(double x, double min, double max);
t_color3 average_color(t_color3 *colors, int sample_count);
t_color3 anti_aliasing_color(t_scene *scene, int i, int j, int samples_per_pixel);

#endif
