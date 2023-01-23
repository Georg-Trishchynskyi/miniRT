/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:48:19 by gpinchuk          #+#    #+#             */
/*   Updated: 2023/01/22 21:49:30 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_p3	new_vec(double x, double y, double z)
{
	t_p3	vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

double	_mod(t_p3 v)
{
	return (sqrt(_dot(v, v)));
}

double	vcos(t_p3 v1, t_p3 v2)
{
	return (_dot(v1, v2) / (_mod(v1) * _mod(v2)));
}

double	_lenth(t_p3 vec)
{
	double	ret;

	ret = sqrt((pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2)));
	return (ret);
}


double	_lenth_sq(t_p3 vec)
{
	double	ret;

	ret = (pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
	return (ret);
}
