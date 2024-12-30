/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeong <junhyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:47:31 by junhyeong         #+#    #+#             */
/*   Updated: 2024/12/31 00:50:35 by junhyeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOOL_H
# define BOOL_H

# define true 1
# define false 0

typedef int bool;

// Boolean 값 출력 헬퍼 매크로
#define BOOL_TO_STRING(b) ((b) ? "true" : "false")

#endif // BOOL_H

