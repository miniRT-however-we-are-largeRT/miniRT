/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 20:47:47 by junhyeong         #+#    #+#             */
/*   Updated: 2025/01/08 19:00:37 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minirt.h"
# include "../lib/libft.h"
#include <math.h>

// utils.c
t_bool	ft_isfloat(char *str);
int	is_ulong(char *str);

// list.c
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);

// light.c
void	push_light(t_rt *rt, t_light *light);
void	free_lights(t_light **light);

// object.c
t_obj	*new_obj(int id);
void	push_obj(t_rt *rt, t_obj *obj);
t_vec3	*normalize(t_vec3 *v);
float	vectlen(t_vec3 v);

#endif