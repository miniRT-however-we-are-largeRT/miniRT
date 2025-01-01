/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeong <junhyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 20:43:23 by junhyeong         #+#    #+#             */
/*   Updated: 2025/01/01 23:59:10 by junhyeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

// #include "struct_set.h"
// #include "minirt.h"
#include "bool.h"
#include "utils.h"
#include "error_handle.h"

// file.c
t_bool	open_file(t_rt *rt, char *file);
t_bool	is_rt_file(char *file);
t_bool	read_file(t_rt *rt, int fd);
char	*sanitize_line(char *line);

// parse.c
void parse_line(t_rt *rt, char *line);

// parse_init.c
void parse_resolution(t_rt *rt, char *line);
void parse_ambient(t_rt *rt, char *line);
void parse_light(t_rt *rt, char *line);
void parse_camera(t_rt *rt, char *line);

// parse_utils.c
t_bool	parse_float(char *str, float *num);
t_bool	parse_color(char *str, t_color *color);
t_bool	parse_vector(char *str, t_vect *vector);
t_bool	parse_ulong(char *str, unsigned long *num);

#endif