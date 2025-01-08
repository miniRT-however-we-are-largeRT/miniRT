/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 23:53:58 by junhyeong         #+#    #+#             */
/*   Updated: 2025/01/08 20:57:10 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/utils.h"
#include "../../inc/minirt.h"

void	push_light(t_data *data, t_light *light)
{
	t_light	*tmp;

	tmp = data->scene->light;
	if (!tmp)
	{
		data->scene->light = light;
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
