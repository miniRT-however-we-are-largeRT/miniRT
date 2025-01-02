/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeong <junhyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:35:14 by junhyeong         #+#    #+#             */
/*   Updated: 2025/01/02 20:56:48 by junhyeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parse.h"
#include <fcntl.h>

char *sanitize_line(char *line)
{
	char *tmp;
	int i;

	i = 0;
	tmp = line;	
	while (tmp[i])
	{
		if (tmp[i] == '\t' || tmp[i] == '\n')
			tmp[i] = ' ';
		i++;
	}
	line = ft_strtrim(tmp, " ");
	return (line);
}

void	print_line(char *line)
{
	printf("line: %s\n", line);
}

t_bool read_file(t_rt *rt, int fd)
{
	char	*line;
	int		num;
	int		ret;

	ret = 1;
	num = 0;
	while (ret)
	{
		num++;
		line = get_next_line(fd);
		if (!line)
			break ;
		line = sanitize_line(line);
		print_line(line);
		parse_line(rt, line);
		free(line);
	}
	if (ret < 0)
		error_handle(READ_ERROR);
	close(fd);
	return (true);
}

t_bool is_rt_file(char *file)
{
	int len;

	len = ft_strlen(file);
	if (file[len - 1] == 't' && file[len - 2] == 'r' && file[len - 3] == '.')
		return (true);
	return (false);
}

t_bool open_file(t_rt *rt, char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_handle(OPEN_ERROR);
	if (!is_rt_file(file))
		error_handle(RT_FILE_ERROR);
	if (read_file(rt, fd))
		return (true);
	return (false);
}
