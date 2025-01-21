/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 00:35:14 by junhyeong         #+#    #+#             */
/*   Updated: 2025/01/21 16:14:41 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/parse_bonus.h"
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
	free(tmp);
	return (line);
}

t_bool	is_invalid(t_data *data)
{
	if (!data->scene->ambient.id)
		return (false);
	if (!data->scene->camera.id)
		return (false);
	if (!data->scene->light)
		return (false);
	return (true);
}

t_bool	read_file(t_data *data, int fd)
{
	char	*line;
	t_bool	flag;

	flag = true;
	while (true)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line = sanitize_line(line);
		if (!parse_line(data, line))
			flag = false;
		free(line);
	}
	if (flag == false && !is_invalid(data))
		error_handle(RT_FILE_ERROR);
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
