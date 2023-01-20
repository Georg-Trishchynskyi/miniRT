/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:52:24 by gpinchuk          #+#    #+#             */
/*   Updated: 2023/01/20 18:48:15 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_material fill_material(char **str, t_scene *scene)
{
	t_material	material;
	int			number;

	number =  (int)stof(str, scene, 3);
	if (number == 1)
	{
		material.gloss = -1;
		material.reflective = 0;
		material.refract = -1;
		material.texture = NULL;
		material.bump = NULL;
	}
	else if  (number == 2)
	{		
		material.gloss = 1000;
		material.reflective = 0.3;
		material.refract = -1;
		material.bump_scale = -1;
		material.texture = NULL;
		material.bump = NULL;
	}
	else if  (number == 3)
	{
		material.gloss = -1;
		material.reflective = 0.2;
		material.refract = 1.2;
		material.bump_scale = -1;
		material.texture = NULL;
		material.bump = NULL;
	}
	else if(number == 4)
	{
		material.gloss = -1;
		material.reflective = 0;
		material.refract = -1;
		material.bump_scale = -1;
		material.texture = read_xpm_file(scene->mlx->mlx, "textures/The_world.xpm");
		material.bump = read_xpm_file(scene->mlx->mlx, "textures/The_world.xpm");
	}
	else if(number == 5)
	{
		material.gloss = -1;
		material.reflective = 0.8;
		material.refract = -1;
		material.bump_scale = -1;
		material.texture = NULL;//load_textures(scene->mlx->mlx, "textures/The_world.xpm");
		material.bump = NULL;
	}
	// else if(number == 5)
	// {
	// 	material.gloss = -1;
	// 	material.reflective = 0;
	// 	material.refract = -1;
	// 	material.bump_scale = -1;
	// 	material.texture = NULL//load_textures(scene->mlx->mlx, "textures/The_world.xpm");
	// }
	else
	{
		material.gloss = -1;
		material.reflective = 0;
		material.refract = -1;
		material.bump_scale = 1;
		// material.texture = load_textures(scene->mlx->mlx, "The_world.xpm");
		fprintf(stderr, "%i, %i", material.texture->height, material.texture->width);
	}
	return (material);
}