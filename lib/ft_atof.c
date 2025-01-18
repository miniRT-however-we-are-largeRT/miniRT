/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 15:05:56 by junhyeop          #+#    #+#             */
/*   Updated: 2025/01/18 15:11:08 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

static int	skip_whitespace_and_get_sign(const char **str)
{
	int	sign;

	sign = 1;
	while (ft_isspace(**str))
		(*str)++;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	return (sign);
}

static double	parse_integer_part(const char **str)
{
	double	result;

	result = 0;
	while (ft_isdigit(**str))
	{
		result = result * 10 + (**str - '0');
		(*str)++;
	}
	return (result);
}

static double	parse_decimal_part(const char **str)
{
	double	decimal;
	double	divisor;

	decimal = 0;
	divisor = 1;
	if (**str == '.')
	{
		(*str)++;
		while (ft_isdigit(**str))
		{
			decimal = decimal * 10 + (**str - '0');
			divisor *= 10;
			(*str)++;
		}
	}
	return (decimal / divisor);
}

double	ft_atod(const char *str)
{
	double	result;
	double	sign;

	sign = skip_whitespace_and_get_sign(&str);
	result = parse_integer_part(&str);
	result += parse_decimal_part(&str);
	return (sign * result);
}
