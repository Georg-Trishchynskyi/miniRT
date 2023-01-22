/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:14:41 by gpinchuk          #+#    #+#             */
/*   Updated: 2023/01/22 20:54:02 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	move_key(int key, t_scene *scene)
{
	if (key == 123)
		scene->camera->pos.x -= 0.2;
	else if (key == 124)
		scene->camera->pos.x += 0.2;
	else if (key == 125)
		scene->camera->pos.y += 0.2;
	else if (key == 126)
		scene->camera->pos.y -= 0.2;
	render_scene(scene);
}

int	key(int key, t_scene *scene)
{
	(void)scene;
	if (key >= 123 && key <= 126)
		move_key(key, scene);
	else if (key == 53)
	{
		free_scene(scene);
		exit(0);
	}
	return (0);
}

int	escape(t_scene *scene)
{
	free_scene(scene);
	exit(0);
	return (0);
}
