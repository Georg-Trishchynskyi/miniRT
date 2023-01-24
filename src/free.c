/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:37:59 by gpinchuk          #+#    #+#             */
/*   Updated: 2023/01/24 17:50:25 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_figures(t_figures *fig)
{
	t_figures	*temp;

	while (fig)
	{
		temp = fig;
		if (temp->material.texture != NULL)
		{
			free(temp->material.texture);
		}
		if (temp->material.bump != NULL)
		{
			free(temp->material.bump);
		}
		fig = fig->next;
		free(temp);
	}
	exit(0);
}

void	free_mlx(t_mlx *mlx)
{
	if (mlx)
	{
		mlx_destroy_window(mlx->mlx, mlx->window);
		mlx_destroy_image(mlx->mlx, mlx->img);
		// free(mlx->addr);
		free(mlx);
	}
}

void	free_light(t_lights *lights)
{
	t_lights	*temp_l;

	while (lights)
	{
		temp_l = lights;
		lights = lights->next;
		free(temp_l);
	}
}

void	free_scene(t_scene *scene)
{
	free_figures(scene->figures);
	free_mlx(scene->mlx);
	free_light(scene->lights);
	free(scene->camera);
	free(scene);
}
