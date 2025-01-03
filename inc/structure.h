/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:52:55 by jihyjeon          #+#    #+#             */
/*   Updated: 2025/01/03 17:04:56 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

# include <math.h>
# include "minirt.h"


# define		FALSE	0
# define		TRUE	1

typedef struct s_cam_scene_data
{
	t_point3	viewpoint;
	t_vec3		dir;
	int			fov;
}				t_cam_scene_data;

typedef	struct s_camera
{
	t_point3	origin;
	t_vec3		dir;
	double		cam_phi;
	double		cam_theta;
	t_vec3		w;
	t_vec3		u;
	t_vec3		v;
	double		viewport_h;
	double		viewport_w;
	t_point3	lower_left;
	double		focal_len;
	t_vec3		horizontal;
	t_vec3		vertical;
}				t_camera;

typedef struct s_canvas
{
	double	w;
	double	h;
	double	aspect_ratio;
	t_vec3	vup;
}				t_canvas;

typedef struct s_sphere
{
	t_point3	center;
	double		radius;
	double		radius2;
}				t_sphere;


// t_camera		ft_camera_set(t_point3 pos, t_vec3 dir, double vfov);
// t_ray			ft_camera_get_ray(t_camera *cam, double u, double v);
// double			ft_degrees_to_radians(double degrees);

#endif