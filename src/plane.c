/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:02:37 by fstaryk           #+#    #+#             */
/*   Updated: 2023/01/24 14:02:57 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

double	plane_intersection(t_p3 d, t_p3 cam_o, t_p3 pl_n, t_p3 pl_o)
{
	double	inter_proj;//projection of intersecting normal and direction of camera
	double	inter;

	inter_proj = _dot(d, pl_n);
	if(inter_proj == 0)//this means that plane doesnt intersect with the ray
		return (INFINITY);
	inter = _dot(_substruct(pl_o, cam_o)/*vector to posible inter*/, pl_n) / inter_proj;
	//if inter == 0 vector is || to plane
	//if < 0 its on the oposite side of the cam
	//if > 0 it intersects
	if (inter <= 0)
		return (INFINITY);
	else
		return (inter);
}
