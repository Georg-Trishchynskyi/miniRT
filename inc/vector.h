/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:41:40 by gpinchuk          #+#    #+#             */
/*   Updated: 2023/01/18 14:07:08 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H

typedef struct  s_p3
{
	double	x;
	double	y;
	double	z;
}				t_p3;

t_p3	_norm(t_p3 vec);
double	_lenth(t_p3 vec);
double	_lenth_sq(t_p3 vec);
t_p3	_substruct(t_p3 vec1, t_p3 vec2);
t_p3	new_vec(double x, double y, double z);
t_p3	_multy(t_p3 vec1, double i);
double	_dot(t_p3 vec1, t_p3 vec2);
t_p3	_cross(t_p3 a, t_p3 b);
t_p3	_add(t_p3 vec1, t_p3 vec2);
double		distance(t_p3 p1, t_p3 p2);

#endif