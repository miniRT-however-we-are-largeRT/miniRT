/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 18:25:20 by junhyeong         #+#    #+#             */
/*   Updated: 2025/01/12 18:13:34 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"
#include "../../inc/error_handle.h"
#include <math.h>

t_obj	*new_obj(int id)
{
	t_obj	*obj;

	obj = (t_obj *)ft_calloc(sizeof(t_obj), 1);
	if (!obj)
		error_handle(MALLOC_ERROR);
	obj->id = id;
	obj->next = NULL;
	return (obj);
}

void	push_obj(t_data *rt, t_obj *obj)
{
	t_obj	*tmp;

	tmp = rt->scene->world;
	if (!tmp)
	{
		rt->scene->world = obj;
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = obj;
	return ;
}

void	free_objs(t_data **data)
{
	t_obj	*tmp;
	t_obj	*rmv;

	tmp = (*data)->scene->world;
	while (tmp)
	{
		rmv = tmp;
		tmp = tmp->next;
		free(rmv);
	}
}

double	vectlen(t_vec3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vec3	*normalize(t_vec3 *v)
{
	double	norm;

	norm = 1 / vectlen(*v);
	v->x *= norm;
	v->y *= norm;
	v->z *= norm;
	return (v);
}
