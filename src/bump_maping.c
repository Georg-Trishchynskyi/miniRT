/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_maping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:55:26 by gpinchuk          #+#    #+#             */
/*   Updated: 2023/01/20 19:02:58 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_p3 calcNormal(int x, int y, int width, int *heightmap) {
    t_p3 ret;
	
	t_p3 c4 = int_to_rgb(heightmap[(y * width - 1) + x]);
	t_p3 c3 = int_to_rgb(heightmap[(y * width + 1) + x]);
	t_p3 c2 = int_to_rgb(heightmap[y * width + (x + 1)]);
	t_p3 c1 = int_to_rgb(heightmap[y * width + (x - 1)]);

	float dx = (c2.x - c1.x) / 2.0f;
    float dy = (c4.x - c3.x) / 2.0f;
    float dz = 1.0f;

	ret = new_vec(dx, dy, dz);
	_norm(ret);
	return(ret);
}

t_p3 sample_bump_map(t_p3 inter_p, t_figures *closest_figure)
{
    int uv_coord[2];
    t_p3 bump_norm;

    // Calculate the UV coordinates of the intersection point
   get_sphere_texture_index(closest_figure, inter_p, uv_coord);

	bump_norm = calcNormal(uv_coord[0], uv_coord[1], closest_figure->material.bump->width, closest_figure->material.bump->pix_arr);
	
    return bump_norm;
}
