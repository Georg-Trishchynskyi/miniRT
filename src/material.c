/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:52:24 by gpinchuk          #+#    #+#             */
/*   Updated: 2023/01/22 18:39:25 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_material fill_material(char **str, t_scene *scene)
{
	t_material	material;
	int			number;

	number =  (int)stof(str, scene, -1);
	fprintf(stderr, "\n%d\n", number);
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
		material.bump = read_xpm_file(scene->mlx->mlx, "textures/bump-map-textur-fuer-3d-material-zum-rendern-und-erstellen-von-shadern_101553-2158.xpm");
	}
	else if(number == 5)
	{
		material.gloss = -1;
		material.reflective = 0.95;
		material.refract = -1;
		material.bump_scale = -1;
		material.texture = NULL;//load_textures(scene->mlx->mlx, "textures/The_world.xpm");
		material.bump = NULL;
	}
	else if(number == 6)
	{
		material.gloss = -1;
		material.reflective = 0;
		material.refract = -1;
		material.bump_scale = -1;
		material.texture = read_xpm_file(scene->mlx->mlx, "/Users/fstaryk/Desktop/miniRT/textures/HFD_HemiSunset01_SmlSample.jpeg.xpm");
		material.bump = NULL;
	}
	else if(number == 7)
	{
		material.gloss = -1;
		material.reflective = 0;
		material.refract = -1;
		material.bump_scale = -1;
		material.texture = malloc(sizeof(t_texture));
		material.texture->height = 1;
		material.texture->width = 1;
		material.texture->pix_arr = NULL;
		material.bump = NULL;
	}
	else
	{
		material.gloss = -1;
		material.reflective = 0;
		material.refract = -1;
		material.bump_scale = -1;
		material.texture = NULL;//read_xpm_file(scene->mlx->mlx, "/Users/fstaryk/Desktop/miniRT/textures/HFD_HemiSunset01_SmlSample.jpeg.xpm");
		material.bump = NULL;

	}
	return (material);
}