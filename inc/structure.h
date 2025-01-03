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

# include "minirt.h"


# define		FALSE	0
# define		TRUE	1
typedef int		t_object_type;;
# define		SP		0

typedef struct s_object t_object;
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

typedef struct s_hit_record
{
	t_point3	p;
	t_vec3		normal;
	double		tmin;
	double		tmax;
	double		t;
	t_bool		front_face;
}				t_hit_record;

# define NB_PARAMS_PLANE 4
# define NB_PARAMS_SPHERE 4
# define NB_PARAMS_CYLINDER 6
# define NB_PARAMS_CONE 7
# define NB_PARAMS_TRIANGLE 5
# define NB_PARAMS_TORUS 6

typedef enum e_object_id
{
	id_unset,
	id_ambient,
	id_light,
	id_camera,
	id_plane,
	id_cylinder,
	id_cone,
	id_sphere,
	id_triangle,
	id_torus
}	t_obj_id;

typedef union u_object
{
	t_sphere	sphere;
	t_plane		plane;
	t_cylinder	cylinder;
	t_cone		cone;
	t_triangle	triangle;
	t_torus		torus;
}	t_obj_union;

typedef struct s_obj
{
	t_obj_id		id;
	t_obj_union		object;
	float			speckv;
	float			specn;
	float			mirror;
	float			refract;
	t_vect			ex;
	t_vect			ey;
	t_vect			ez;
	t_vect			coords;
	t_color			color;
	t_color			color2;
	float			h;
	float			pattern_len;
	int				pattern_num;
	float			alpha;
	float			bump_f;
	float			texture_f;
	t_bool			has_bump;
	t_bool			has_texture;
	t_img			bump;
	t_img			texture;
	struct s_obj	*next;
}	t_obj;

// t_camera		ft_camera_set(t_point3 pos, t_vec3 dir, double vfov);
// t_ray			ft_camera_get_ray(t_camera *cam, double u, double v);
// double			ft_degrees_to_radians(double degrees);

#endif