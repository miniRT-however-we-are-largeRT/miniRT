/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeong <junhyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:16:52 by junhyeong         #+#    #+#             */
/*   Updated: 2024/12/31 01:24:50 by junhyeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"

t_rt	*get_rt(void)
{
	t_rt	*rt;

	rt = (t_rt *)malloc(sizeof(t_rt));
	if (!rt)
		error_handle("Error: malloc error\n");
	return (rt);
}

int	main(int argc, char **argv)
{
	t_rt	*rt;

	if (argc != 2)
		error_handle(ARGC_ERROR);
	rt = get_rt();
}