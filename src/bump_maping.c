/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_maping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:55:26 by gpinchuk          #+#    #+#             */
/*   Updated: 2023/01/23 14:43:26 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_p3	calcnormal(int x, int y, int width, int *heightmap)
{
	t_p3	ret;
	t_p3	c1;
	t_p3	c2;
	t_p3	c3;
	t_p3	c4;

	c4 = int_to_rgb(heightmap[(y * width - 1) + x]);
	c3 = int_to_rgb(heightmap[(y * width + 1) + x]);
	c2 = int_to_rgb(heightmap[y * width + (x + 1)]);
	c1 = int_to_rgb(heightmap[y * width + (x - 1)]);
	ret = new_vec(((c2.x - c1.x) / 2.0f), ((c4.x - c3.x) / 2.0f), 1.0);
	_norm(ret);
	return (ret);
}

t_p3	sample_bump_map(t_p3 inter_p, t_figures *closest_figure)
{
	int		uv_coord[2];
	t_p3	bump_norm;

	// Calculate the UV coordinates of the intersection point
	get_sphere_texture_index(closest_figure, inter_p, uv_coord);
	bump_norm = calcnormal(uv_coord[0], uv_coord[1], \
		closest_figure->material.bump->width, \
		closest_figure->material.bump->pix_arr);
	return (bump_norm);
}
