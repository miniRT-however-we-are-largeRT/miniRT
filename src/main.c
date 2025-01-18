/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 19:16:52 by junhyeong         #+#    #+#             */
/*   Updated: 2025/01/18 20:00:52 by jihyjeon         ###   ########.fr       */
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

void	print_cone(t_data *data)
{
	t_obj* tmp = data->scene->world;
	while (tmp->next) {
		tmp = tmp->next;
	}
	t_cone cone = tmp->object.cone;

	printf("center\t: %f %f %f\n", tmp->coords.x, tmp->coords.y, tmp->coords.z);
	printf("normal\t: %f %f %f\n", cone.orient.x, cone.orient.y, cone.orient.z);
	printf("radius\t: %f\n", cone.radius);
	printf("height\t: %f\n", cone.height);
	printf("color\t: %f %f %f\n\n", cone.color.x, cone.color.y, cone.color.z);
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
	print_cone(data);
	run(data);
	rt_clear(data);
	return (0);
}
