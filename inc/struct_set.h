/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_set.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:36:06 by junhyeong         #+#    #+#             */
/*   Updated: 2025/01/17 21:16:30 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_SET_H
# define STRUCT_SET_H

#include "bool.h"
#include <unistd.h>
# include "vec.h"

# define		FALSE	0
# define		TRUE	1
# define		EPSILON		1e-6
# define		LUMEN	2

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

typedef struct s_discrm
{
	t_vec3	oc;
	double	a;
	double	half_b;
	double	c;
	double	dscrm;
	double	sqrtd;
	double	root;
}	t_discrm;

typedef struct s_hit_record
{
	t_point3	p;
	t_vec3		normal;
	double		tmin;
	double		tmax;
	double		t;
	t_bool		front_face;
	t_color3	albedo;
}				t_hit_record;

typedef struct s_ambient
{
	t_obj_id	id;
	double		lighting;
	t_color3	color;
}	t_ambient;

typedef struct s_plane
{
	t_obj_id	id;
	t_point3	coords;
	t_vec3		orient;
	t_color3	color;
}	t_plane;

typedef struct s_cylinder
{
	t_obj_id	id;
	t_point3	coords;
	t_vec3		orient;
	double		diameter;
	double		radius;
	double		height;
	double		r2;
	t_vec3		p1;
	t_vec3		p2;
	t_vec3		delta_p;
	t_color3	color;
}	t_cylinder;

typedef struct s_sphere
{
	t_obj_id	id;
	t_vec3		center;
	double		diameter;
	double		radius;
	double		r2;
	t_color3	color;
}	t_sphere;

typedef union u_object
{
	t_sphere	sphere;
	t_plane		plane;
	t_cylinder	cylinder;
}	t_obj_union;


typedef struct s_obj
{
	t_obj_id		id;
	t_obj_union		object;
	double			speckv;
	double			specn;
	double			mirror;
	double			refract;
	t_vec3			ex;
	t_vec3			ey;
	t_vec3			ez;
	t_vec3			coords;
	t_color3		color;
	t_color3		color2;
	t_color3		albedo;
	double			h;
	double			pattern_len;
	int				pattern_num;
	double			alpha;
	double			bump_f;
	double			texture_f;
	t_bool			has_bump;
	t_bool			has_texture;
	struct s_obj	*next;
}	t_obj;

typedef struct	s_ray
{
	t_vec3		orig;
	t_vec3		dir;
}				t_ray;

// typedef struct s_rays
// {
// 	t_ray		prime_ray;
// 	t_ray		shadowray;
// 	t_hit		hit;
// 	t_hit		shadow_hit;
// 	t_obj		*closest_obj;
// }	t_rays;

typedef struct s_colors
{
	t_color3	ambient;
	t_color3	diffuse;
	t_color3	specular;
	// t_color3	reflect;
	// t_color3	refract;
	double		is_shadow;
	double		attenuation;
}	t_colors;

typedef struct s_light_var
{
	t_color3	light;	
	t_vec3		light_dir;
	t_vec3		u_dir;
	double		light_len;
	t_ray		light_ray;
	t_vec3		view_dir;
	t_vec3		reflect_dir;
}	t_light_var;

typedef struct s_light
{
	t_obj_id		id;
	t_vec3			coords;
	double			brightness;
	double			constant;
	double			linear;
	double			quadratic;
	t_color3		color;
	t_color3        albedo;
	t_color3		ambient;		
	struct s_light	*next;
}	t_light;

typedef struct s_camera
{
	t_obj_id	id;
	t_point3	origin;
	t_vec3		dir;
	double		focal_len;
	size_t		fov;
	double		scale;
	double		cam_phi;
	double		cam_theta;
	t_vec3		w;
	t_vec3		u;
	t_vec3		v;
	double		viewport_h;
	double		viewport_w;
	t_point3	lower_left;
	t_vec3		horizontal;
	t_vec3		vertical;
}	t_camera;

typedef struct s_canvas
{
	double	w;
	double	h;
	double	aspect_ratio;
	t_vec3	vup;
}				t_canvas;

typedef struct s_scene
{
	t_canvas		canvas;
	t_camera		camera;
	t_obj			*world;
	t_light			*light;
	t_ambient		ambient;
	t_ray           ray;
	t_hit_record    rec;
}	t_scene;

typedef struct s_img
{
	void	*img;
	char	*addr;
	char	*path;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		addr_incr;
	int		antialiasing_on;
}	t_img;

#endif