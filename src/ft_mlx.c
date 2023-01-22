/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:50:35 by fstaryk           #+#    #+#             */
/*   Updated: 2023/01/22 20:50:12 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	my_mlx_pixel_put(t_scene *scene, int x, int y, int color)
{
	char	*dst;

	if (x < scene->width && y <= scene->height && x > 0 && y > 0)
	{
		dst = scene->mlx->addr + (y * scene->mlx->line_length + \
					x * (scene->mlx->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}
