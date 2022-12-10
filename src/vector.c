/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:12:38 by admin             #+#    #+#             */
/*   Updated: 2022/12/10 19:01:24 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_p3 new_vec(float x, float y, float z)
{
	t_p3 vec;
	// vec = (t_p3)malloc(sizeof(t_p3));
	// if (!vec)
	// 	fatal_error("Vector was not allocated");
	vec.x = x;
	vec.y = y;
	vec.z = z;
	return (vec);
}

float _lenth(t_p3 vec)
{
	float ret;

	ret = sqrt((pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2)));
	return (ret);
}

float _lenth_sq(t_p3 vec)
{
	float ret;

	ret = (pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
	return (ret);
}

t_p3 _norm(t_p3 vec)
{
	float len;
	t_p3 ret;	

	len = _lenth(vec);
	ret.x /= len;
	ret.y /= len;
	ret.z /= len;
	return ret;
}

t_p3 _substruct(t_p3 vec1, t_p3 vec2)
{
	t_p3 new;

	new.x = vec1.x - vec2.x;
	new.y = vec1.x - vec2.x;
	new.z = vec1.x - vec2.x;

	return (new);
}

t_p3 _add(t_p3 vec1, t_p3 vec2)
{
	t_p3 new;

	new.x = vec1.x + vec2.x;
	new.y = vec1.x + vec2.x;
	new.z = vec1.x + vec2.x;

	return (new);
}

t_p3 _cross(t_p3 vec1, t_p3 vec2)
{
	t_p3 new;

	new.x = vec1.x * vec2.x;
	new.y = vec1.y * vec2.y;
	new.z = vec1.z * vec2.z;
	return (new);
}

t_p3 _multy(t_p3 vec1, float i)
{
	t_p3 new;

	new.x = vec1.x * i;
	new.y = vec1.y * i;
	new.z = vec1.z * i;
	return (new);
}

float _dot(t_p3 vec1, t_p3 vec2)
{
	float ret;

	ret = ((vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z));
	return ret; 
}