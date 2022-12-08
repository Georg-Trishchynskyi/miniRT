/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 19:24:10 by admin             #+#    #+#             */
/*   Updated: 2022/12/08 13:50:19 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cam *new_camera(t_p3 *pos, t_p3 *dir, float angle)
{
	t_cam *camera;

	camera = (t_cam*)malloc(sizeof(t_cam));
	if (!camera)
		fatal_error("Camera was not allocated");
	camera->pos = pos;
	camera->direct = dir;
	camera->angle = angle;
	return (camera);
}