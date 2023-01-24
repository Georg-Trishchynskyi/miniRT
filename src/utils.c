/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:22:08 by fstaryk           #+#    #+#             */
/*   Updated: 2023/01/24 15:34:23 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

bool	is_thread_safe(t_figures *fig)
{
	while (fig)
	{
		if (fig->flag == CY)
			return (false);
		fig = fig->next;
	}
	return (true);
}

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
