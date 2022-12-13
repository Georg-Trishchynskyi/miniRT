/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:04:30 by fstaryk           #+#    #+#             */
/*   Updated: 2022/12/13 21:30:40 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

int	rgb_int(t_p3 col)
{
	return (((int)col.x << 16) | ((int)col.y << 8) | (int)col.z);
}

t_p3	color_x_light(t_p3 base_color, t_p3 light_collor)
{
    t_p3 new;
    
	new.x = base_color.x - ((255 - light_collor.x) / 2);
	new.y = base_color.y - ((255 - light_collor.y) / 2);
	new.z = base_color.z - ((255 - light_collor.z) / 2);
	return (new);
}
