/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:37:59 by gpinchuk          #+#    #+#             */
/*   Updated: 2023/01/22 20:49:49 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_scene(t_scene *scene)
{
	t_figures	*temp;
	t_lights	*temp_l;

	while(scene->figures)
	{
		temp = scene->figures;
		if (temp->material.texture)
			free(temp->material.texture);
		scene->figures = scene->figures->next;
		free(temp);
	}
	while (scene->lights)
	{
		temp_l = scene->lights;
		scene->lights = scene->lights->next;
		free(temp_l);
	}
	if (scene->mlx)
	{
		mlx_destroy_window(scene->mlx->mlx, scene->mlx->window);
		mlx_destroy_image(scene->mlx->mlx, scene->mlx->img);
		free(scene->mlx);
	}
	free(scene->camera);
	free(scene);
}
