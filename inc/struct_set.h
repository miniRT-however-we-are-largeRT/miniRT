/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_set.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:36:06 by junhyeong         #+#    #+#             */
/*   Updated: 2025/01/10 13:07:40 by jihyjeon         ###   ########.fr       */
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
# define		LUMEN	3

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

typedef struct s_img	t_img;

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

typedef struct s_quadratic
{
	float	a;
	float	b;
	float	c;
	float	delta;
	float	t1;
	float	t2;
}	t_quadratic;

typedef struct s_color
{
	float	r;
	float	g;
	float	b;
}	t_color; //no usage, t_color3 (derived by t_point3) instead

typedef struct s_hit
{
	t_vec3	nhit;
	t_vec3	phit;
	float	t;
	t_color	color;
}	t_hit; //use when?

typedef struct s_colors
{
	t_color	ambient;
	t_color	diffuse;
	t_color	specular;
	t_color	reflect;
	t_color	refract;
	int		is_shadow;
}	t_colors;

typedef struct s_ambient
{
	t_obj_id	id;
	float		lighting;
	t_color		color;
}	t_ambient;

typedef struct s_light
{
	t_obj_id		id;
	t_vec3			coords;
	float			brightness;
	t_color			color;
	struct s_light	*next;
}	t_light;

typedef struct s_camera
{
	t_obj_id	id;
	t_point3	origin;
	t_vec3		dir;
	size_t		fov;
	float		scale;
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

typedef struct s_plane
{
	t_obj_id	id;
	t_vec3		coords;
	t_vec3		orient;
	t_color		color;
}	t_plane;

typedef struct s_cylinder
{
	t_obj_id	id;
	t_vec3		coords;
	t_vec3		orient;
	float		diameter;
	float		height;
	float		r2;
	t_vec3		p1;
	t_vec3		p2;
	t_vec3		delta_p;
	t_color		color;
}	t_cylinder;

typedef struct s_sphere
{
	t_obj_id	id;
	t_vec3		center;
	float		diameter;
	double		radius; //init needed
	float		r2;
	t_color		color;
}	t_sphere;

typedef struct s_triangle
{
	t_obj_id	id;
	t_vec3		c[3];
	t_vec3		edge[3];
	t_vec3		n;
	t_color		color;
	float		area2;
}	t_triangle;

typedef struct s_cone
{
	t_obj_id	id;
	t_vec3		coords;
	t_vec3		orient;
	float		h;
	float		h2;
	float		angle;
	float		cos2;
	t_vec3		c1;
	t_vec3		c2;
	float		r1;
	float		r2;
	t_color		color;
}	t_cone;

typedef	struct s_torus
{
	t_obj_id	id;
	t_vec3		coords;
	t_vec3		orient;
	float		sml_r;
	float		sml_r2;
	float		big_r;
	float		big_r2;
	t_color		color;
}	t_torus;

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
	t_vec3			ex;
	t_vec3			ey;
	t_vec3			ez;
	t_vec3			coords;
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

typedef struct	s_ray
{
	t_vec3		orig;
	t_vec3		dir;
}				t_ray;

typedef struct s_rays
{
	t_ray		prime_ray;
	t_ray		shadowray;
	t_hit		hit;
	t_hit		shadow_hit;
	t_obj		*closest_obj;
}	t_rays;

typedef struct s_canvas
{
	double	w;
	double	h;
	double	aspect_ratio;
	t_vec3	vup;
}				t_canvas;

typedef struct  s_scene
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