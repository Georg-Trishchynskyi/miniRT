/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:52:41 by admin             #+#    #+#             */
/*   Updated: 2022/12/06 18:55:56 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere *new_sphere(t_vector *vec, float rad)
{
	t_sphere *sphere;

	sphere = (t_sphere*)malloc(sizeof(t_sphere));
	if (!sphere)
		fatal_error("Sphere was not allocated");
	sphere->centr = vec;
	sphere->radius = rad;
	return (sphere);
}