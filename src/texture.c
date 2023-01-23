/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:56:35 by gpinchuk          #+#    #+#             */
/*   Updated: 2023/01/22 21:57:16 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_p3	get_collor_fig(t_figures *fig, t_p3 p)
{
	if (fig->material.texture == NULL)
		return (fig->collor);
	else if (fig->flag == SP && fig->material.texture->width == 1 \
							&& fig->material.texture->height == 1)
		return (apply_checkerboard_sphere(fig, p, 30, 15));
	else if (fig->flag == SP)
		return (apply_texture_sphere(p, fig));
	return (fig->collor);
}
