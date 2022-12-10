/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:47:30 by fstaryk           #+#    #+#             */
/*   Updated: 2022/12/10 19:01:05 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_p3    get_screen_coord(int x, int y, t_scene *scene)
{
	t_p3 ret;

	ret.x = ((2 * (x + 0.5)/scene->width) - 1) * scene->aspect_ratio * scene->camera->fov_l;
	ret.y = ((2 * (y + 0.5)/scene->height) - 1) * scene->aspect_ratio;
	ret.z = -1;
	return ret;
}

t_p3    look_at_pixel(t_p3 d, t_p3 cam_nv)
{
	t_p3    ref_up;
	t_p3    x_axis;
	t_p3    y_axis;
	t_p3    rotated;

	ref_up = new_vec(0, -1, 0);
	x_axis = _cross(_norm(ref_up), cam_nv);
	y_axis = _cross(cam_nv, x_axis);

	rotated = _add(_multy(x_axis, d.x), cam_nv);
	rotated = _add(_multy(y_axis, d.y), rotated);

	return rotated;
}

float   sphere_intersection(t_p3 d, t_p3 cam_nv, t_p3 sp_o, float r){
    t_p3 p;//makes vector p that goes from sphere origin to intersection
    float disc;
    float x1;
    float x2;
    float quad_kof[3];
    
    p = _substruct(cam_nv, sp_o);
    quad_kof[0] = _lenth_sq(d);
    quad_kof[1] = 2 * _dot(p, d);
    quad_kof[2] = _lenth_sq(p) - pow(r, 2);
    disc = pow(quad_kof[1], 2) + 4 * quad_kof[0] * quad_kof[2];
    if(disc < 0)
        return INFINITY;
    x1 = (-quad_kof[1] + sqrt(disc)) / 2 * quad_kof[0];
    x2 = (-quad_kof[1] - sqrt(disc)) / 2 * quad_kof[0];
    if(disc == 0 || x1 < x2)
        return x1;
    return x2;
}

float try_intersections(t_p3 d, t_p3 cam_nv, t_figures *fig, t_figures *closest_fig)
{
	float inter_dist;
    float closest_inter;
	
    closest_inter = INFINITY;
    while (fig)
	{
		if(fig->flag == SP)
            inter_dist = sphere_intersection(d, cam_nv, fig->figures.sp.centr, fig->figures.sp.radius);
        if(inter_dist < closest_inter && inter_dist > 0){
            closest_inter = inter_dist;
            *closest_fig = *fig;
        }
        fig = fig->next;
    }
	return closest_inter;
}


int trace_ray(t_p3 d, t_scene *scene)
{
    float   closest_inter;
    t_figures closest_figure;

    closest_figure.flag = 0;
    closest_inter = try_intersections(d, scene->camera->pos, scene->figures, &closest_figure);
    
    if(closest_inter != INFINITY)
        return scene->background;
    else
        return rgb_int(closest_figure.collor);
}

void render_scene(t_scene *scene)
{
	int y;
	int x;
	t_p3 dir_vec;
	int color;

	y = 0;
	while (y < scene->height)
	{
		x = 0;
		while (x < scene->width)
		{
			dir_vec = get_screen_coord(x, y, scene);
			dir_vec = look_at_pixel(dir_vec, scene->camera->pos);                     
			color = trace_ray(dir_vec, scene);
            my_mlx_pixel_put(scene, x, y, color); 
			x++;
		}
		y++;
	}
}