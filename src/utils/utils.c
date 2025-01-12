/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 21:16:23 by junhyeong         #+#    #+#             */
/*   Updated: 2025/01/12 18:13:34 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"

t_bool	ft_isdouble(char *str)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			if (str[i] == '.' && !dot)
				dot++;
			else
				return (false);
		}
		i++;
	}
	return (true);
}

int	is_ulong(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i])
	{
		if (ft_isdigit(str[i]) != 1)
			return (0);
		i++;
	}
	return (1);
}
