/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:12:38 by admin             #+#    #+#             */
/*   Updated: 2022/12/06 18:54:27 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector *new_vec(float x, float y, float z)
{
	t_vector *vec;
	vec = (t_vector *)malloc(sizeof(new_vec));
	if (!new)
		fatal_error("Vector was not allocated");
	vec->x = x;
	vec->y = y;
	vec->z = z;
	return (new);
}

float vec_lenth(t_vector *vec)
{
	float ret;

	ret = sqrt((pow(vec->x, 2) + pow(vec->y, 2) + pow(vec->z, 2)));
	return (ret);
}

void vec_norm(t_vector *vec)
{
	float len;

	len = vec_lenth(vec);
	vec->x /= len;
	vec->y /= len;
	vec->z /= len;
}

float vec_dot_product(t_vector *vec1, t_vector *vec2)
{
	float ret;

	ret = ((vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z));
	return ret; 
}