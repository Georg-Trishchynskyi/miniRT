/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:50:05 by gpinchuk          #+#    #+#             */
/*   Updated: 2023/01/22 21:50:49 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_p3	_cross(t_p3 a, t_p3 b)
{
	t_p3	cp;
	cp.x = a.y * b.z - a.z * b.y;
	cp.y = a.z * b.x - a.x * b.z;
	cp.z = a.x * b.y - a.y * b.x;

	return (cp);
}

t_p3	_multy(t_p3 vec1, double i)
{
	t_p3	new;

	new.x = vec1.x * i;
	new.y = vec1.y * i;
	new.z = vec1.z * i;
	return (new);
}

t_p3	_div(t_p3 vec1, double i)
{
	t_p3	new;

	new.x = vec1.x / i;
	new.y = vec1.y / i;
	new.z = vec1.z / i;
	return (new);
}

double	_dot(t_p3 vec1, t_p3 vec2)
{
	double	ret;

	ret = ((vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z));
	return (ret); 
}
