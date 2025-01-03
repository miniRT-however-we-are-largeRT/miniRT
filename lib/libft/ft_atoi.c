/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 17:02:15 by junhyeop          #+#    #+#             */
/*   Updated: 2023/11/05 17:39:28 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	res = 0;
	i = 0;
	sign = 1;
	if (*str == 0)
		return (0);
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
	}
	if (*str < '0' || *str > '9')
		return (0);
	while (*str != 0)
	{
		if (*str < '0' || *str > '9')
			break ;
		res = (res * 10) + *str++ - 48;
	}
	return (res * (sign));
}

// #include <stdio.h>
// int main(void) {
// 	printf("%d\n", ft_atoi("-+1"));
// }