/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 20:42:25 by junhyeong         #+#    #+#             */
/*   Updated: 2025/01/12 18:33:30 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parse.h"
#include "../../inc/utils.h"

t_bool	parse_double(char *str, double *num)
{
	if (!ft_isdouble(str))
		return (false);
	*num = ft_atod(str);
	return (true);
}

t_bool	parse_color(char *str, t_color3 *color)
{
	char	**split;

	split = ft_split(str, ',');
	if (ft_split_size(split) != 3)
		error_handle(RT_FILE_ERROR);
	color->x = ft_atod(split[0]) / 255;
	color->y = ft_atod(split[1]) / 255;
	color->z = ft_atod(split[2]) / 255;
	ft_free_split(split);
	return (true);
}

t_bool	parse_vector(char *str, t_vec3 *vector)
{
	char	**split;

	split = ft_split(str, ',');
	if (ft_split_size(split) != 3)
		error_handle(RT_FILE_ERROR);
	vector->x = ft_atod(split[0]);
	vector->y = ft_atod(split[1]);
	vector->z = ft_atod(split[2]);
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
