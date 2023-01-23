/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:12:38 by admin             #+#    #+#             */
/*   Updated: 2023/01/22 21:50:55 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_p3	_norm(t_p3 vec)
{
	t_p3	nv;
	double	mod;

	mod = sqrt((double)vec.x * (double)vec.x + (double)vec.y \
	* (double)vec.y + (double)vec.z * (double)vec.z);
	if (mod == 0)
		return (vec);
	nv.x = vec.x / mod;
	nv.y = vec.y / mod;
	nv.z = vec.z / mod;
	return (nv);
}

t_p3	_substruct(t_p3 vec1, t_p3 vec2)
{
	t_p3	new;

	new.x = vec1.x - vec2.x;
	new.y = vec1.y - vec2.y;
	new.z = vec1.z - vec2.z;

	return (new);
}

t_p3	_add(t_p3 vec1, t_p3 vec2)
{
	t_p3	new;

	new.x = vec1.x + vec2.x;
	new.y = vec1.y + vec2.y;
	new.z = vec1.z + vec2.z;

	return (new);
}

double	distance(t_p3 p1, t_p3 p2)
{
	double	d;

	d = sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2) + pow(p2.z - p1.z, 2));
	return (d);
}
