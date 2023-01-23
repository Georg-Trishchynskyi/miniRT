/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 14:28:53 by fstaryk           #+#    #+#             */
/*   Updated: 2023/01/22 22:03:22 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

static int	solve_tube(double *x, t_p3 d, t_p3 o, t_figures *cy)
{
	t_p3	v;
	t_p3	u;
	double	a;
	double	b;
	double	c;

	v = _multy(cy->figures.cy.nv, _dot(d, cy->figures.cy.nv));
	v = _substruct(d, v);//???vector from inter point to center nv of cylinder	
	u = _multy(cy->figures.cy.nv, _dot(_substruct(o, \
				cy->figures.cy.o), cy->figures.cy.nv));
	u = _substruct(_substruct(o, cy->figures.cy.o), u);
	a = _dot(v, v);
	b = 2 * _dot(v, u);
	c = _dot(u, u) - pow(cy->figures.cy.r, 2);
	x[0] = (-b + sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
	x[1] = (-b - sqrt(pow(b, 2) - 4 * a * c)) / (2 * a);
	if (x[0] != x[0] && x[1] != x[1])
		return (0);
	if (x[0] < EPSILON && x[1] < EPSILON)
		return (0);
	return (1);
}

t_p3	calc_cy_normal(double *x2, t_p3 o, t_p3 d, t_figures *fig)
{
	double	dist;
	double	x;

	if ((fig->figures.cy.dist1 >= 0 && \
			fig->figures.cy.dist1 <= fig->figures.cy.h
			&& x2[0] > EPSILON) && (fig->figures.cy.dist2 >= 0 \
			&&fig->figures.cy.dist2 <= fig->figures.cy.h && x2[1] > EPSILON))
	{
		dist = x2[0] < x2[1] ?fig->figures.cy.dist1 :fig->figures.cy.dist2;
		x = x2[0] < x2[1] ? x2[0] : x2[1];
	}
	else if (fig->figures.cy.dist1 >= 0 && fig->figures.cy.dist1 \
						<=fig->figures.cy.h && x2[0] > EPSILON)
	{
		dist = fig->figures.cy.dist1;
		x = x2[0];
	}
	else
	{
		dist = fig->figures.cy.dist2;
		x = x2[1];
	}
	x2[0] = x;
	return (_norm(_substruct(_substruct(_multy(d, x), \
	_multy(fig->figures.cy.nv, dist)), _substruct(fig->figures.cy.o, o))));
}

double	tube_intersection(t_p3 d, t_p3 cam_o, t_figures *cy)
{
	double	x2[2];

    //geting intersection with infinite cylinder equation
	if (solve_tube(x2, d, cam_o, cy) == 0)
		return (INFINITY);
    //checking if intersection is in boundries of our tube
	cy->figures.cy.dist1 = _dot(cy->figures.cy.nv, \
	_substruct(_multy(d, x2[0]), _substruct(cy->figures.cy.o, cam_o)));
	cy->figures.cy.dist2 = _dot(cy->figures.cy.nv, \
	_substruct(_multy(d, x2[1]), _substruct(cy->figures.cy.o, cam_o)));
	if (!((cy->figures.cy.dist1 >= 0 && cy->figures.cy.dist1 <= \
	cy->figures.cy.h && x2[0] > EPSILON) || (cy->figures.cy.dist2 \
	>= 0 && cy->figures.cy.dist2 <= cy->figures.cy.h && x2[0] > EPSILON)))
		return (INFINITY);
    //dont completely understand this one
	cy->figures.cy.normal = calc_cy_normal(x2, cam_o, d, cy);
	return (x2[0]);
}

double	caps_intersection(t_p3 d, t_p3 o, t_figures *cy)
{
	double	id1;
	double	id2;
	t_p3	ip1;
	t_p3	ip2;
	t_p3	c2;

	//center of the second plane
	c2 = _add(cy->figures.cy.o, _multy(cy->figures.cy.nv, cy->figures.cy.h));
	//intersection with top cap
	id1 = plane_intersection(d, o, cy->figures.cy.nv, cy->figures.cy.o);
	//intersection with bottom cap
	id2 = plane_intersection(d, o, cy->figures.cy.nv, c2);
	//checking if they are in the disc range
	if (id1 < INFINITY || id2 < INFINITY)
	{
		//top inter point
		ip1 = _add(o, _multy(d, id1));
		//botom inter point
		ip2 = _add(o, _multy(d, id2));
		//both of them are ni the range
		if ((id1 < INFINITY && distance(ip1, cy->figures.cy.o) <= cy->figures.cy.r)
				&& (id2 < INFINITY && distance(ip2, c2) <= cy->figures.cy.r))
			return (id1 < id2 ? id1 : id2);
		//only top cap is un range
		else if (id1 < INFINITY
						&& distance(ip1, cy->figures.cy.o) <= cy->figures.cy.r)
			return (id1);
		//only botom cap is in range
		else if (id2 < INFINITY && distance(ip2, c2) <= cy->figures.cy.r)
			return (id2);
		return (INFINITY);
	}
	return (INFINITY);
}

double	cylinder_intersection(t_p3 d, t_p3 cam_o, t_figures *cy)
{
	double	tube_inter;
	double	caps_inter;

	tube_inter = tube_intersection(d, cam_o, cy);
	caps_inter = caps_intersection(d, cam_o, cy);
	if (tube_inter < INFINITY || caps_inter < INFINITY)
	{
		if (tube_inter < caps_inter)
		{
			return (tube_inter);
		}
		cy->figures.cy.normal = cy->figures.cy.nv;
		return (caps_inter);
	}
	return (INFINITY);
}
