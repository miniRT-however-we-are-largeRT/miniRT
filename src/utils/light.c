/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeong <junhyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 23:53:58 by junhyeong         #+#    #+#             */
/*   Updated: 2025/01/01 23:58:36 by junhyeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"
#include "../../inc/minirt.h"

void	push_light(t_rt *rt, t_light *light)
{
	t_light	*tmp;

	tmp = rt->light;
	if (!tmp)
	{
		rt->light = light;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = light;
	return ;
}

void	free_lights(t_light **light)
{
	t_light	*tmp;

	while (*light)
	{
		tmp = *light;
		*light = (*light)->next;
		free(tmp);
	}
}
