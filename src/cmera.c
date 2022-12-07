/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmera.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:24:10 by admin             #+#    #+#             */
/*   Updated: 2022/12/06 19:26:57 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cams *new_camera(t_vector *pos, t_vector *dir, float angle)
{
	t_cams *camera;

	camera = (t_cams*)malloc(sizeof(t_cams));
	if (!camera)
		fatal_error("Camera was not allocated");
	camera->pos = pos;
	camera->direct = dir;
	camera->angle = angle;
	return (camera);
}