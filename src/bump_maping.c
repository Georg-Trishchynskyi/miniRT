/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bump_maping.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:55:26 by gpinchuk          #+#    #+#             */
/*   Updated: 2023/01/19 16:38:39 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// void calcNormal(int x, int y, HeightValue heightmap[width][height], t_p3 *normal) {
//     // Get the height values of the surrounding pixels
//     HeightValue h1 = heightmap[x - 1][y];
//     HeightValue h2 = heightmap[x + 1][y];
//     HeightValue h3 = heightmap[x][y - 1];
//     HeightValue h4 = heightmap[x][y + 1];

//     // Calculate the partial derivatives using the finite difference method
//     normal->x = (h2.x - h1.x) / 2.0f;
//     normal->y = (h4.x - h3.x) / 2.0f;
//     normal->z = 1.0f; // The heightmap is in 2D, so dz = 1.0
// }

// t_p3 sample_bump_map(t_p3 inter_p, t_figures *closest_figure) {
//     int uv_coord[2];
//     t_p3 bump_norm;

//     // Calculate the UV coordinates of the intersection point
//    get_sphere_texture_index(closest_figure, inter_p, uv_coord);

//     // Sample the bump map at the UV coordinates
//     bump_norm = calcNormal(uv_coord[0], uv_coord[1], closest_figure);

//     // Scale the bump map value and return
//     bump_norm = _multy(bump_norm, closest_figure->material.bump_scale);

// 	bump_norm = _norm(bump_norm);
	
//     return bump_norm;
// }
