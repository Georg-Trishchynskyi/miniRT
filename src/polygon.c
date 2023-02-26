/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polygon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:59:08 by fstaryk           #+#    #+#             */
/*   Updated: 2023/01/24 13:59:26 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool	check_p_in_borders(t_p3 p1, t_p3 p2, t_p3 p3, t_p3 inter_p)
{
	t_p3	v1;
	t_p3	v2;
	t_p3	v3;
	t_p3	cross1;
	t_p3	cross2;

	v1 = _substruct(p2, p1);
	v2 = _substruct(p3, p1);
	v3 = _substruct(inter_p, p1);
	cross1 = _cross(v1, v2);
	cross2 = _cross(v1, v3);
	if (_dot(cross1, cross2) / _lenth(cross1) * _lenth(cross2) < 0)
		return (false);
	return (true);
}

t_p3	calculate_triangle_normal(t_triangle tri)
{
	return (_cross(_substruct(tri.p1, tri.p2), _substruct(tri.p1, tri.p3)));
}

double	trinagle_intersection(t_p3 d, t_p3 cam_o, t_triangle tri)
{
	t_p3	tri_norm;
	double	plane_inter;
	t_p3	inter_p;

	tri_norm = calculate_triangle_normal(tri);
	plane_inter = plane_intersection(d, cam_o, tri_norm, tri.p1);
	inter_p = _add(cam_o, _multy(d, plane_inter));
	if (!check_p_in_borders(tri.p1, tri.p2, tri.p3, inter_p))
		return (INFINITY);
	if (!check_p_in_borders(tri.p3, tri.p1, tri.p2, inter_p))
		return (INFINITY);
	if (!check_p_in_borders(tri.p2, tri.p3, tri.p1, inter_p))
		return (INFINITY);
	return (plane_inter);
}
