/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyeop <junhyeop@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:52:55 by jihyjeon          #+#    #+#             */
/*   Updated: 2025/01/08 19:39:02 by junhyeop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H

// # include <math.h>
// # include "minirt.h"


// # define		FALSE	0
// # define		TRUE	1

// # define		FALSE	0
// # define		TRUE	1
// # define		SP		0
// # define		EPSILON		1e-6
// # define		LUMEN	3

// typedef struct s_cam_scene_data
// {
// 	t_point3	viewpoint;
// 	t_vec3		dir;
// 	int			fov;
// }				t_cam_scene_data;

// typedef	struct s_camera
// {
// 	t_point3	origin;
// 	t_vec3		dir;
// 	double		cam_phi;
// 	double		cam_theta;
// 	t_vec3		w;
// 	t_vec3		u;
// 	t_vec3		v;
// 	double		viewport_h;
// 	double		viewport_w;
// 	t_point3	lower_left;
// 	double		focal_len;
// 	t_vec3		horizontal;
// 	t_vec3		vertical;
// }				t_camera;

// typedef struct s_canvas
// {
// 	double	w;
// 	double	h;
// 	double	aspect_ratio;
// 	t_vec3	vup;
// }				t_canvas;

// typedef struct s_sphere
// {
// 	t_point3	center;
// 	double		radius;
// 	double		radius2;
// }				t_sphere;

// typedef struct s_hit_record
// {
// 	t_point3	p;
// 	t_vec3		normal;
// 	double		tmin;
// 	double		tmax;
// 	double		t;
// 	t_bool		front_face;
// 	t_color3	albedo;
// }				t_hit_record;

// # define NB_PARAMS_PLANE 4
// # define NB_PARAMS_SPHERE 4
// # define NB_PARAMS_CYLINDER 6
// # define NB_PARAMS_CONE 7
// # define NB_PARAMS_TRIANGLE 5
// # define NB_PARAMS_TORUS 6

// typedef enum e_object_id
// {
// 	id_unset,
// 	id_ambient,
// 	id_light,
// 	id_camera,
// 	id_plane,
// 	id_cylinder,
// 	id_cone,
// 	id_sphere,
// 	id_triangle,
// 	id_torus
// }	t_obj_id;

// typedef struct s_plane
// {
// 	t_obj_id	id;
// 	t_vec3		coords;
// 	t_vec3		orient;
// 	t_color3		color;
// }	t_plane;

// typedef struct s_cylinder
// {
// 	t_obj_id	id;
// 	t_vec3		coords;
// 	t_vec3		orient;
// 	float		diameter;
// 	float		height;
// 	float		r2;
// 	t_vec3		p1;
// 	t_vec3		p2;
// 	t_vec3		delta_p;
// 	t_color3		color;
// }	t_cylinder;

// // typedef struct s_sphere
// // {
// // 	t_obj_id	id;
// // 	t_vec3		coords;
// // 	float		diameter;
// // 	float		r2;
// // 	t_color3		color;
// // }	t_sphere;

// typedef struct s_triangle
// {
// 	t_obj_id	id;
// 	t_vec3		c[3];
// 	t_vec3		edge[3];
// 	t_vec3		n;
// 	t_color3		color;
// 	float		area2;
// }	t_triangle;

// typedef struct s_cone
// {
// 	t_obj_id	id;
// 	t_vec3		coords;
// 	t_vec3		orient;
// 	float		h;
// 	float		h2;
// 	float		angle;
// 	float		cos2;
// 	t_vec3		c1;
// 	t_vec3		c2;
// 	float		r1;
// 	float		r2;
// 	t_color3		color;
// }	t_cone;

// typedef	struct s_torus
// {
// 	t_obj_id	id;
// 	t_vec3		coords;
// 	t_vec3		orient;
// 	float		sml_r;
// 	float		sml_r2;
// 	float		big_r;
// 	float		big_r2;
// 	t_color3		color;
// }	t_torus;

// typedef struct s_light
// {
// 	t_point3	origin;
// 	t_color3	light_color;
// 	double		bright_ratio;
// }	t_light;

// typedef union u_object
// {
// 	t_sphere	sphere;
// 	t_plane		plane;
// 	t_cylinder	cylinder;
// 	t_cone		cone;
// 	t_triangle	triangle;
// 	t_torus		torus;
// 	t_light		light;
// }	t_obj_union;

// typedef struct s_img
// {
// 	void	*img;
// 	char	*addr;
// 	char	*path;
// 	int		width;
// 	int		height;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// 	int		addr_incr;
// 	int		antialiasing_on;
// }	t_img;

// typedef struct s_object
// {
// 	t_obj_id		id;
// 	t_obj_union		object;
// 	float			speckv;
// 	float			specn;
// 	float			mirror;
// 	float			refract;
// 	t_vec3			ex;
// 	t_vec3			ey;
// 	t_vec3			ez;
// 	t_vec3			coords;
// 	t_color3		color;
// 	t_color3		color2;
// 	t_color3		albedo;
// 	float			h;
// 	float			pattern_len;
// 	int				pattern_num;
// 	float			alpha;
// 	float			bump_f;
// 	float			texture_f;
// 	t_bool			has_bump;
// 	t_bool			has_texture;
// 	t_img			bump;
// 	t_img			texture;
// 	struct s_object	*next;
// }	t_obj;

// typedef struct	s_ray
// {
// 	t_point3	orig;
// 	t_vec3		dir;
// }				t_ray;

// typedef struct  s_scene
// {
// 	t_canvas        canvas;
// 	t_camera        camera;
// 	t_obj        *world;
// 	t_obj        *light;
// 	t_color3         ambient; // 8.4에서 설명할 요소
// 	t_ray           ray;
// 	t_hit_record    rec;
// }	t_scene;

// t_camera		ft_camera_set(t_point3 pos, t_vec3 dir, double vfov);
// t_ray			ft_camera_get_ray(t_camera *cam, double u, double v);
// double			ft_degrees_to_radians(double degrees);

#endif