/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:37:59 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/12/27 18:51:18 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void free_scene(t_scene *scene)
{
	t_figures	*temp;
	t_lights	*temp_l;
	
	while(scene->figures)
	{
		temp = scene->figures;
		scene->figures = scene->figures->next;
		free(temp);
	}
	while(scene->lights)
	{
		temp_l = scene->lights;
		scene->lights = scene->lights->next;
		free(temp_l);
	}
	free(scene->camera);
	free(scene);
}