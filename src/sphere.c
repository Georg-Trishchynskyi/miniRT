/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:52:41 by admin             #+#    #+#             */
/*   Updated: 2023/01/24 14:05:08 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere	*new_sphere(t_p3 vec, double rad)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sphere)
		fatal_error("Sphere was not allocated");
	sphere->centr = vec;
	sphere->radius = rad;
	return (sphere);
}

void	solve_sphere(t_p3 d, t_p3 cam_o, t_sphere sp, double x[2])
{
	t_p3	p;
	double	disc;
	t_p3	sp_o;
	double	r;
	double	quad_kof[3];

	r = sp.radius;
	sp_o = sp.centr;
	p = _substruct(cam_o, sp_o);
	quad_kof[0] = _dot(d, d);
	quad_kof[1] = 2 * _dot(p, d);
	quad_kof[2] = _dot(p, p) - r * r;
	disc = quad_kof[1] * quad_kof[1] - 4 * quad_kof[0] * quad_kof[2];
	if (disc < 0)
	{
		x[0] = INFINITY;
		x[1] = INFINITY;
		return ;
	}
	x[0] = (-quad_kof[1] + sqrt(disc)) / (2 * quad_kof[0]);
	x[1] = (-quad_kof[1] - sqrt(disc)) / (2 * quad_kof[0]);
}

double	sphere_intersection(t_p3 d, t_p3 o, t_figures *lst)
{
	double	closest;
	double	x[2];
	t_p3	ip1;
	t_p3	ip2;

	closest = INFINITY;
	solve_sphere(d, o, lst->figures.sp, x);
	if (x[0] > EPSILON && x[0] < INFINITY)
		closest = x[0];
	if (x[1] > EPSILON && x[1] < INFINITY)
		if (x[1] < x[0])
			closest = x[1];
	return (closest);
}
