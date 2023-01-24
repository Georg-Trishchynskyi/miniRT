/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:09:02 by fstaryk           #+#    #+#             */
/*   Updated: 2023/01/24 15:34:44 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_p3	look_at_pixel(t_p3 d, t_p3 cam_nv)
{
	t_p3	ref_up;
	t_p3	x_axis;
	t_p3	y_axis;
	t_p3	rotated;

	ref_up = new_vec(0, 1, 0);
	if (cam_nv.y == 1)
		x_axis = (t_p3){1, 0, 0};
	if (cam_nv.y == -1)
		x_axis = (t_p3){-1, 0, 0};
	else
		x_axis = _cross(ref_up, cam_nv);
	x_axis = _cross(ref_up, _norm(cam_nv));
	y_axis = _cross(_norm(cam_nv), x_axis);
	rotated = _add(_multy(x_axis, d.x), cam_nv);
	rotated = _add(_multy(y_axis, d.y), rotated);
	return (rotated);
}

t_p3	get_screen_coord(int x, int y, t_scene *scene)
{
	t_p3	ret;

	ret.x = ((2 * (x + 0.5) / scene->width) - 1) \
	* scene->aspect_ratio * scene->camera->fov_l;
	ret.y = (1 - (2 * (y + 0.5) / scene->height)) * scene->camera->fov_l;
	ret.z = -1;
	ret = look_at_pixel(ret, scene->camera->direct);
	return (ret);
}

void	render_scene(t_scene *scene)
{
	int		y;
	int		x;
	t_p3	dir_vec;
	int		color;

	y = 0;
	while (y < scene->height)
	{
		x = 0;
		while (x < scene->width)
		{
			dir_vec = get_screen_coord(x, y, scene);
			color = trace_ray(dir_vec, scene->camera->pos, scene, 2);
			my_mlx_pixel_put(scene, x, y, color);
			printf("\rRendering scene... [%f%%]", \
				((float)y / (float)scene->height) * 100);
			x++;
		}
		y++;
	}
}

void	render_scene_with_thread(t_scene *scene, int thread_id)
{
	int		y;
	int		x;
	t_p3	dir_vec;
	int		color;
	int		lines_to_render;

	lines_to_render = scene->height / NUM_THREADS;
	y = thread_id * lines_to_render;
	while (y < lines_to_render * (thread_id + 1))
	{
		x = 0;
		while (x < scene->width)
		{
			dir_vec = get_screen_coord(x, y, scene);
			color = trace_ray(dir_vec, scene->camera->pos, scene, 2);
			my_mlx_pixel_put(scene, x, y, color);
			if (thread_id == NUM_THREADS - 1)
				printf("\rRendering scene... [%f%%]", (100 * \
				(y % lines_to_render) / (float)lines_to_render));
			x++;
		}
		y++;
	}
}
