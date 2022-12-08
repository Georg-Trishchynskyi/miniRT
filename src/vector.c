/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:12:38 by admin             #+#    #+#             */
/*   Updated: 2022/12/08 13:50:02 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_p3 *new_vec(float x, float y, float z)
{
	t_p3 *vec;
	vec = (t_p3 *)malloc(sizeof(t_p3));
	if (!vec)
		fatal_error("Vector was not allocated");
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (vec);
}

float vec_lenth(t_p3 *vec)
{
	float ret;

	ret = sqrt((pow(vec->x, 2) + pow(vec->y, 2) + pow(vec->z, 2)));
	return (ret);
}

void vec_norm(t_p3 *vec)
{
	float len;

	len = vec_lenth(vec);
	vec->x /= len;
	vec->y /= len;
	vec->z /= len;
}

float vec_dot_product(t_p3 *vec1, t_p3 *vec2)
{
	float ret;

	ret = ((vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z));
	return ret; 
}