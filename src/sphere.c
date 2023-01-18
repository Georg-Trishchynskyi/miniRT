/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:52:41 by admin             #+#    #+#             */
/*   Updated: 2023/01/18 14:07:08 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere *new_sphere(t_p3 vec, double rad)
{
	t_sphere *sphere;

	sphere = (t_sphere*)malloc(sizeof(t_sphere));
	if (!sphere)
		fatal_error("Sphere was not allocated");
	sphere->centr = vec;
	sphere->radius = rad;
	return (sphere);
}