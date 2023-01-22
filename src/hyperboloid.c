/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hyperboloid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:47:47 by fstaryk           #+#    #+#             */
/*   Updated: 2023/01/22 20:53:38 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

//   double ox = ray.origin.x - center.x;
//   double oy = ray.origin.y - center.y;
//   double oz = ray.origin.z - center.z;
//   double dx = ray.direction.x;
//   double dy = ray.direction.y;
//   double dz = ray.direction.z;

//   double a2 = a*a;
//   double b2 = b*b;
//   double c2 = c*c;

//   double A = dx*dx / a2 + dy*dy / b2 - dz*dz / c2;
//   double B = 2*ox*dx / a2 + 2*oy*dy / b2 - 2*oz*dz / c2;
//   double C = ox*ox / a2 + oy*oy / b2 - oz*oz / c2 - 1;

double	hyperboloid_intersection(t_p3 d, t_p3 cam_o, t_hyper_b hy)
{
	t_p3	new_o;
	t_p3	param_sq;
	double	quad_kof[3];
	double	disc;
	double	x[2];
	//all the semi major parameteres squared, because we only use them like that 
	param_sq = new_vec(pow(hy.param.x, 2), \
	pow(hy.param.y, 2), pow(hy.param.z, 2));
	//shifting center of hyperboloid to point we need
	new_o = _substruct(cam_o, hy.o);
	//qudratic koificients from equation of hyperboloid with ray included as coordinates (t distance)
	//(C.x + t*D.x)^2 + (C.y + t*D.y)^2 - (C.z+t*D.z)^2 - k = 0
	quad_kof[0] = (d.x * d.x / param_sq.x) * hy.nv.x + \
	(d.y * d.y / param_sq.y) * hy.nv.y + (d.z * d.z / param_sq.z) * hy.nv.z;
	quad_kof[1] = (2 * new_o.x * d.x / param_sq.x) * hy.nv.x + \
	(2*new_o.y  * d.y / param_sq.y) * hy.nv.y + (2 * new_o.z * d.z / param_sq.z) * hy.nv.z;
	quad_kof[2] = (pow(new_o.x, 2) / param_sq.x)*hy.nv.x + \
	(pow(new_o.y, 2) / param_sq.y) * hy.nv.y + (pow(new_o.z, 2) / param_sq.z) * hy.nv.z - hy.r;
	//finding a discriminant
	disc = quad_kof[1] * quad_kof[1] - 4 * quad_kof[0] * quad_kof[2];
	if (disc < 0)
		return (INFINITY);
	//finding posible solution
	x[0] = (-quad_kof[1] + sqrt(disc)) / (2 * quad_kof[0]);
	x[1] = (-quad_kof[1] - sqrt(disc)) / (2 * quad_kof[0]);
	return (fmin(x[0], x[1]));
}

t_p3   hyberboloid_normal(t_p3 inter_p, t_hyper_b hy)
{
	t_p3	normal;
	t_p3	new_o;
	t_p3	param_sq;

	new_o = inter_p;
	param_sq = hy.param;
	normal = new_vec(2 * new_o.x / param_sq.x, 2 * \
	new_o.y / param_sq.y, -2 * new_o.z / param_sq.z);
	return (_norm(normal));
}