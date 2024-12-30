/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handle.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeong <junhyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:36:54 by junhyeong         #+#    #+#             */
/*   Updated: 2024/12/31 01:26:07 by junhyeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLE_H
# define ERROR_HANDLE_H

#include <stdio.h>
#include <stdlib.h>

#define OPEN_ERROR "Error: open error\n"
#define ARGC_ERROR "Error: Invalid arguments\n"
#define MALLOC_ERROR "Error: malloc error\n"
#define RT_FILE_ERROR "Error: Invalid rt file\n"

void error_handle(char *msg);

#endif