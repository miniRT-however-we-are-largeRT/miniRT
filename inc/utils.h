/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 20:47:47 by junhyeong         #+#    #+#             */
/*   Updated: 2025/01/18 14:36:23 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../lib/libft.h"
# include "minirt.h"
# include <math.h>

// utils.c
t_bool	ft_isdouble(char *str);
int		is_ulong(char *str);

// list.c
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);

// light.c
void	push_light(t_data *rt, t_light *light);
void	free_lights(t_light **light);

// object.c
t_obj	*new_obj(int id);
void	push_obj(t_data *rt, t_obj *obj);
t_vec3	*normalize(t_vec3 *v);
double	vectlen(t_vec3 v);
void	free_objs(t_data **data);

#endif