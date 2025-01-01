/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeong <junhyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 02:04:49 by junhyeong         #+#    #+#             */
/*   Updated: 2025/01/01 20:45:37 by junhyeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parse.h"

void	parse_line(t_rt *rt, char *line)
{
	if (line[0] == 'R')
		parse_resolution(rt, line);
	else if (line[0] == 'A')
		parse_ambient(rt, line);
	else if (line[0] == 'C' && line[1] == ' ')
		parse_camera(rt, line);
	else if (line[0] == 'L')
		parse_light(rt, line);
	else if (line[0] == 's' && line[1] == 'p')
		parse_sphere(rt, line);
	else if (line[0] == 'p' && line[1] == 'l')
		parse_plane(rt, line);
	else if (line[0] == 's' && line[1] == 'q')
		parse_square(rt, line);
	else if (line[0] == 'c' && line[1] == 'y')
		parse_cylinder(rt, line);
}


