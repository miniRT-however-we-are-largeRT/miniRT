/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeong <junhyeong@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:35:14 by junhyeong         #+#    #+#             */
/*   Updated: 2025/01/09 17:29:59 by junhyeong        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parse.h"
#include <fcntl.h>

char	*sanitize_line(char *line)
{
	char	*tmp;
	int		i;

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

t_bool	read_file(t_data *data, int fd)
{
	char	*line;
	int		num;

	num = 0;
	while (true)
	{
		num++;
		line = get_next_line(fd);
		if (!line)
			break ;
		line = sanitize_line(line);
		print_line(line);
		parse_line(data, line);
		free(line);
	}
	close(fd);
	return (true);
}

t_bool	is_rt_file(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (file[len - 1] == 't' && file[len - 2] == 'r' && file[len - 3] == '.')
		return (true);
	return (false);
}

t_bool	open_file(t_data *data, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_handle(OPEN_ERROR);
	if (!is_rt_file(file))
		error_handle(RT_FILE_ERROR);
	if (read_file(data, fd))
		return (true);
	return (false);
}
