/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_maping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:55:26 by gpinchuk          #+#    #+#             */
/*   Updated: 2023/01/20 18:43:01 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void calcNormal(int x, int y, int width, int *heightmap) {
    t_p3 ret;
	
	t_p3 c4 = int_to_rgb(fig->material.texture->texture[(ind[1] * width - 1) + ind[0]]);
	t_p3 c3 = int_to_rgb(fig->material.texture->texture[(ind[1] * width + 1) + ind[0]]);
	t_p3 c2 = int_to_rgb(fig->material.texture->texture[ind[1] * width + (ind[0] + 1)]);
	t_p3 c1 = int_to_rgb(fig->material.texture->texture[ind[1] * width + (ind[0] - 1)]);

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

    // Sample the bump map at the UV coordinates
	if (uv_coord[0] > 0 && uv_coord[1] > 0  && uv_coord[0] < closest_figure->material.texture.hight && uv_coord[1] < closest_figure->material.texture.width)
		bump_norm = calcNormal(uv_coord[1], uv_coord[0], closest_figure->material.texture.width, closest_figure->material.texture->pix_arr);

    // Scale the bump map value and return
    //bump_norm = _multy(bump_norm, closest_figure->material.bump_scale);
	//bump_norm = _norm(bump_norm);
	
    return bump_norm;
}
