/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:16:52 by junhyeong         #+#    #+#             */
/*   Updated: 2025/01/18 15:37:17 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/main.h"
#include "../inc/minirt.h"

t_data	*get_data(void)
{
	t_data	*data;
	t_scene	*scene;

	data = (t_data *)ft_calloc(sizeof(t_data), 1);
	if (!data)
		error_handle("Error: malloc error\n");
	scene = (t_scene *)ft_calloc(sizeof(t_scene), 1);
	if (!scene)
		return (NULL);
	data->scene = scene;
	return (data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
		error_handle(ARGC_ERROR);
	data = get_data();
	if (!open_file(data, argv[1]))
		error_handle(OPEN_ERROR);
	rt_init(data, argv[1]);
	run(data);
	rt_clear(data);
	return (0);
}
