/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeong <junhyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 20:47:22 by junhyeong         #+#    #+#             */
/*   Updated: 2025/01/01 20:50:35 by junhyeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"
#include <math.h>

float	ft_atof(const char *str)
{
	float	result;
	float	sign;
	float	decimal;
	int		i;

	result = 0;
	sign = 1;
	decimal = 0;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		while (ft_isdigit(str[i]))
		{
			decimal = decimal * 10 + str[i] - '0';
			i++;
		}
	}
	return (sign * (result + decimal / pow(10, i)));
}