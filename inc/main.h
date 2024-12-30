/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeong <junhyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:47:19 by junhyeong         #+#    #+#             */
/*   Updated: 2024/12/31 01:59:43 by junhyeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

#include "error_handle.h"
#include "ray.h"
#include "minirt.h"
#include "bool.h"

// file.c
bool open_file(t_rt *rt, char *file);
bool is_rt_file(char *file);
bool read_file(t_rt *rt, int fd);
char *sanitize_line(char *line);

#endif