/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general_intesections.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:00:46 by fstaryk           #+#    #+#             */
/*   Updated: 2023/01/24 14:43:45 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

double	try_intersections(t_p3 d, t_p3 cam_o, t_figures *fig,
										t_figures *closest_fig)
{
	double	inter_dist;
	double	closest_inter;

	closest_inter = INFINITY;
	while (fig)
	{
		if (fig->flag == SP)
			inter_dist = sphere_intersection(d, cam_o, fig);
		else if (fig->flag == PL)
			inter_dist = plane_intersection(d, cam_o, \
			fig->figures.pl.orient, fig->figures.pl.centr);
		else if (fig->flag == TR)
			inter_dist = trinagle_intersection(d, cam_o, fig->figures.tr);
		else if (fig->flag == CY)
			inter_dist = cylinder_intersection(d, cam_o, fig);
		else if (fig->flag == HY)
			inter_dist = hyperboloid_intersection(d, cam_o, fig->figures.hy);
		if (inter_dist < closest_inter && inter_dist > 1e-3)
		{
			closest_inter = inter_dist;
			*closest_fig = *fig;
		}
		fig = fig->next;
	}
	return (closest_inter);
}
