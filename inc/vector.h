/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:41:40 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/12/10 16:31:48 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
#define VECTOR_H

typedef struct  s_p3
{
	float	x;
	float	y;
	float	z;
}				t_p3;

void	vec_norm(t_p3 *vec);
float	vec_lenth(t_p3 *vec);
float	vec_lenth_sq(t_p3 *vec);
t_p3	*new_vec(float x, float y, float z);
float	vec_dot_product(t_p3 *vec1, t_p3 *vec2);

#endif