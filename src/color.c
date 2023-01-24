/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:04:30 by fstaryk           #+#    #+#             */
/*   Updated: 2023/01/24 13:52:16 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_p3	int_to_rgb(int x)
{
	return (new_vec((x & 0x00ff0000) >> 16, \
	(x & 0x0000ff00) >> 8, (x & 0x000000ff)));
}

int	_cproduct(int color, double coef)
{
	int	mask;
	int	r;
	int	g;
	int	b;

	mask = 255;
	r = coef * ((color & (mask << 16)) >> 16);
	g = coef * ((color & (mask << 8)) >> 8);
	b = coef * (color & mask);
	r = fmin(255, r);
	g = fmin(255, g);
	b = fmin(255, b);
	return ((r << 16) | (g << 8) | b);
}

int	_cadd(int color_a, int color_b)
{
	int	mask;
	int	r;
	int	g;
	int	b;

	mask = 255;
	r = ((color_a & (mask << 16)) + (color_b & (mask << 16))) & (mask << 16);
	g = ((color_a & (mask << 8)) + (color_b & (mask << 8))) & (mask << 8);
	b = ((color_a & mask) + (color_b & mask)) & mask;
	return (r | g | b);
}

t_p3	color_x_light(t_p3 base_color, t_p3 light_collor)
{
	t_p3	new;

	new.x = base_color.x - ((255 - light_collor.x) / 2);
	new.y = base_color.y - ((255 - light_collor.y) / 2);
	new.z = base_color.z - ((255 - light_collor.z) / 2);
	return (new);
}

