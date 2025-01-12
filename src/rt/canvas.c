/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 16:38:58 by jihyjeon          #+#    #+#             */
/*   Updated: 2025/01/12 15:59:51 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minirt.h"

t_canvas	canvas(int width, int height)
{
	t_canvas canvas;

	canvas.w = width;
	canvas.h = height;
	canvas.aspect_ratio = (double)width / (double)height;
	return (canvas);
}

void	camera(t_data *data)
{
	t_canvas 	canvas;
	double		focal_len;
	double		viewport_height;

	canvas = data->scene->canvas;
	viewport_height = 2 * tan((data->scene->camera.fov * M_PI / 180) / 2);
	focal_len = 1.0; //value calc needed
	data->scene->camera.viewport_h = viewport_height;
	data->scene->camera.viewport_w = viewport_height * canvas.aspect_ratio;
	data->scene->camera.w = uvec(vmult_f(-1, data->scene->camera.dir));
	data->scene->camera.u = uvec(vcross(vec3(0, 1, 0), data->scene->camera.w));
	data->scene->camera.v = vcross(data->scene->camera.w, data->scene->camera.u);
	data->scene->camera.focal_len = focal_len;
	// data->scene->camera.horizontal = vec3(data->scene->camera.viewport_w, 0, 0);
	// data->scene->camera.vertical = vec3(0, data->scene->camera.viewport_h, 0);
	// data->scene->camera.lower_left = vsub(vsub(vsub(data->scene->camera.origin, vdiv_f(2, data->scene->camera.horizontal)), \
	// 					vdiv_f(2, data->scene->camera.vertical)), vec3(0, 0, focal_len));
	data->scene->camera.horizontal = vmult_f(data->scene->camera.viewport_w, data->scene->camera.u);
	data->scene->camera.vertical = vmult_f(viewport_height, data->scene->camera.v);
	data->scene->camera.lower_left = vsub(vsub(vsub(data->scene->camera.origin,
				vdiv_f(2, data->scene->camera.horizontal)),
				vdiv_f(2, data->scene->camera.vertical)),
				vmult_f(focal_len, data->scene->camera.w));
	
}


// t_camera camera(t_scene *data)
// {
// 	t_camera cam;
// 	t_vec3   right;
// 	t_vec3   up;
//
// 	// RT 파일에서 가져온 값 설정
// 	cam.origin = scene->camera.coords;  // 카메라 좌표
// 	cam.dir = uvec(scene->camera.orient);  // 방향 벡터 정규화
// 	cam.fov = scene->camera.fov;  // 시야각(FOV)
//
// 	// FOV 기반으로 수직 및 수평 viewport 크기 계산
// 	cam.focal_len = 1.0;  // 기본 초점 거리 (focal length)
// 	double viewport_height = 2.0 * tan((cam.fov * M_PI / 180.0) / 2.0);  // 수직 뷰포트
// 	double viewport_width = viewport_height * scene->canvas.aspect_ratio;  // 종횡비에 따른 수평 뷰포트
//
// 	// 카메라 기준 벡터 계산
// 	right = vcross(vec3(0, 1, 0), cam.dir);  // X축 벡터(수평)
// 	if (vlen(right) < EPSILON)
// 		right = vec3(1, 0, 0);  // 방향이 z축과 수직인 경우 예외 처리
// 	up = vcross(cam.dir, right);  // Y축 벡터(수직)
//
// 	// 카메라 뷰포트 설정
// 	cam.horizontal = vmult_f(viewport_width, uvec(right));  // 수평 벡터
// 	cam.vertical = vmult_f(viewport_height, uvec(up));  // 수직 벡터
// 	cam.lower_left = vsub(vsub(vsub(cam.origin, vdiv_f(2, cam.horizontal)), vdiv_f(2, cam.vertical)), vmult_f(cam.focal_len, cam.dir));  // 좌하단 좌표
//
// 	return cam;
// }
//
//void set_fixed_camera(t_data *data)
//{
//	t_camera *cam = &data->scene->cameraera;
//
//	// 카메라 하드코딩 값 설정
//	cam->origin = vec3(-50.0, 0.0, 20.0);  // 카메라 좌표
//	cam->dir = uvec(vec3(0.0, 0.0, 1.0));  // 방향 벡터 (정규화)
//	cam->fov = 70;  // 수평 시야각
//
//	// Viewport 계산
//	double focal_len = 1.0;  // 초점 거리 (일반적으로 1.0 사용)
//	double viewport_height = 2.0 * tan((cam->fov * M_PI / 180.0) / 2.0);
//	double viewport_width = viewport_height * data->scene->canvas.aspect_ratio;
//
//	// 카메라의 수평(horizontal) 및 수직(vertical) 벡터 계산
//	t_vec3 right = vec3(1.0, 0.0, 0.0);  // 단순히 X축 기준 (카메라가 z축 방향을 보기 때문)
//	t_vec3 up = vec3(0.0, 1.0, 0.0);     // Y축 기준 (위쪽 방향)
//
//	cam->horizontal = vmult_f(viewport_width, right);
//	cam->vertical = vmult_f(viewport_height, up);
//	cam->focal_len = focal_len;
//
//	// 뷰포트의 좌하단(left lower corner) 좌표 계산
//	cam->lower_left = vsub(vsub(vsub(cam->origin, vdiv_f(2, cam->horizontal)), vdiv_f(2, cam->vertical)), vmult_f(cam->focal_len, cam->dir));
//}
