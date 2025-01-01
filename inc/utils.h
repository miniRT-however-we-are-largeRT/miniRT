/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeong <junhyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 20:47:47 by junhyeong         #+#    #+#             */
/*   Updated: 2025/01/01 23:58:48 by junhyeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "minirt.h"
# include "../lib/libft.h"

// ft_split_utils.c
void	ft_free_split(char **split);
int		ft_split_size(char **split);

// ft_atof.c
float	ft_atof(const char *str);

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

#endif