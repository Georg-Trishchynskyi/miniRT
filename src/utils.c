/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:22:08 by fstaryk           #+#    #+#             */
/*   Updated: 2023/01/24 15:02:46 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	double_inter_case_cylinder(double *dist, double *x, \
									double *x2, t_figures *fig)
{
	if (x2[0] < x2[1])
		*dist = fig->figures.cy.dist1;
	else
		*dist = fig->figures.cy.dist2;
	*x = fmin(x2[0], x2[1]);
}

void	add_coeficient(t_p3 *rgb, double coef, t_p3 color)
{
	(*rgb).x += coef * color.x / 255;
	(*rgb).y += coef * color.y / 255;
	(*rgb).z += coef * color.z / 255;
}
