/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:04:30 by fstaryk           #+#    #+#             */
/*   Updated: 2023/01/08 18:50:10 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	rgb_int(t_p3 col)
{
	if(col.x > 253)
		col.x = 255;
	if(col.y > 253)
		col.y = 255;
	if(col.z > 253)
		col.z = 255;
	return (((int)col.x << 16) | ((int)col.y << 8) | (int)col.z);
}

int		_cproduct(int color, float coef)
{
	int mask;
	int r;
	int	g;
	int	b;

	mask = 255;
	r = coef * ((color & (mask << 16)) >> 16);
	g = coef * ((color & (mask << 8)) >> 8);
	b = coef * (color & mask);
	r = r > 255 ? 255 : r;
	g = g > 255 ? 255 : g;
	b = b > 255 ? 255 : b;
	return ((r << 16) | (g << 8) | b);
}

int		_cadd(int color_a, int color_b)
{
	int mask;
	int	r;
	int	g;
	int b;

	mask = 255;
	r = ((color_a & (mask << 16)) + (color_b & (mask << 16))) & (mask << 16);
	g = ((color_a & (mask << 8)) + (color_b & (mask << 8))) & (mask << 8);
	b = ((color_a & mask) + (color_b & mask)) & mask;
	return (r | g | b);
}

t_p3	color_x_light(t_p3 base_color, t_p3 light_collor)
{
    t_p3 new;
    
	new.x = base_color.x - ((255 - light_collor.x) / 2);
	new.y = base_color.y - ((255 - light_collor.y) / 2);
	new.z = base_color.z - ((255 - light_collor.z) / 2);
	return (new);
}

