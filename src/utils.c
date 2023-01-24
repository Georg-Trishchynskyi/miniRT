/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:22:08 by fstaryk           #+#    #+#             */
/*   Updated: 2023/01/24 14:22:23 by fstaryk          ###   ########.fr       */
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
