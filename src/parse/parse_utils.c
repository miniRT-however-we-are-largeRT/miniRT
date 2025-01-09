/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeong <junhyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 20:42:25 by junhyeong         #+#    #+#             */
/*   Updated: 2025/01/09 17:28:31 by junhyeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parse.h"
#include "../../inc/utils.h"

t_bool	parse_float(char *str, float *num)
{
	if (!ft_isfloat(str))
		return (false);
	*num = ft_atof(str);
	return (true);
}

t_bool	parse_color(char *str, t_color *color)
{
	char	**split;

	split = ft_split(str, ',');
	if (ft_split_size(split) != 3)
		error_handle(RT_FILE_ERROR);
	color->r = ft_atof(split[0]) / 255;
	color->g = ft_atof(split[1]) / 255;
	color->b = ft_atof(split[2]) / 255;
	ft_free_split(split);
	return (true);
}

t_bool	parse_vector(char *str, t_vec3 *vector)
{
	char	**split;

	split = ft_split(str, ',');
	if (ft_split_size(split) != 3)
		error_handle(RT_FILE_ERROR);
	vector->x = ft_atof(split[0]);
	vector->y = ft_atof(split[1]);
	vector->z = ft_atof(split[2]);
	ft_free_split(split);
	return (true);
}

t_bool	parse_ulong(char *str, unsigned long *num)
{
	if (!is_ulong(str))
		return (false);
	*num = ft_atoi(str);
	return (true);
}
