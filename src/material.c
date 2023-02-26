/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:52:24 by gpinchuk          #+#    #+#             */
/*   Updated: 2023/01/27 19:38:09 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	sub_fill(int gloss, double reflection, \
	double refract, t_material* material)
{
	(*material).gloss = gloss;
	(*material).reflective = reflection;
	(*material).refract = refract;
}

void	second_part(int number, t_material* material, t_scene* scene)
{
	if (number == 2)
	{
		sub_fill(1000, 0.3, -1, material);
		material->texture = NULL;
		material->bump = NULL;
	}
	else if (number == 3)
	{
		sub_fill(-1, 0, 1.5, material);
		material->texture = NULL;
		material->bump = NULL;
	}
	else if (number == 4)//earth
	{
		sub_fill(-1, 0, -1, material);
		material->texture = read_xpm_file(scene->mlx->mlx, "textures/earth.xpm");
		material->bump = NULL;
	}
	else if (number == 5)
	{
		sub_fill(-1, 0.95, -1, material);
		material->texture = NULL;
		material->bump = NULL;
	}
}

void	checker_bord(t_material* material)
{
	material->texture = malloc(sizeof(t_texture));
	material->texture->height = 1;
	material->texture->width = 1;
	material->texture->pix_arr = NULL;
	material->bump = NULL;
}

t_material	init_material(void)
{
	t_material	ret;

	ret.bump = NULL;
	ret.texture = NULL;
	ret.gloss = -1;
	ret.reflective = -1;
	ret.refract = -1;
	return (ret);
}

t_material	fill_material(char** str, t_scene* scene)
{
	t_material	material;
	int			number;

	number = (int)stof(str, scene, 0);
	if (number == 1)
	{
		sub_fill(-1, 0, -1, &material);
		material.texture = NULL;
		material.bump = NULL;
	}
	else if (number > 1 && number < 6)
		second_part(number, &material, scene);
	else if (number == 6)//stars
	{
		sub_fill(-1, 0, -1, &material);
		material.texture = read_xpm_file(scene->mlx->mlx, "textures/starmap_g4k.xpm");
		material.bump = NULL;
	}
	else if (number == 7)
	{
		sub_fill(-1, 0, -1, &material);
		checker_bord(&material);
	}
	else if (number == 8)//sun
	{
		sub_fill(-1, 0, -1, &material);
		material.texture = read_xpm_file(scene->mlx->mlx, "textures/2k_sun.xpm");
		material.bump = NULL;
	}
	else if (number == 9)//moon
	{
		sub_fill(-1, 0, -1, &material);
		material.texture = read_xpm_file(scene->mlx->mlx, "textures/moon.xpm");
		material.bump = NULL;
	}
	else if (number == 10)//mars
	{
		sub_fill(-1, 0, -1, &material);
		material.texture = read_xpm_file(scene->mlx->mlx, "textures/mars.xpm");
		material.bump = NULL;
	}
	else if (number == 11)//mercury
	{
		sub_fill(-1, 0, -1, &material);
		material.texture = read_xpm_file(scene->mlx->mlx, "textures/Mercury.xpm");
		material.bump = NULL;
	}
	else if (number == 12)//venus
	{
		sub_fill(-1, 0, -1, &material);
		material.texture = read_xpm_file(scene->mlx->mlx, "textures/2k_venus_surface.xpm");
		material.bump = NULL;
	}
	else if (number == 13)//jupiter
	{
		sub_fill(-1, 0, -1, &material);
		material.texture = read_xpm_file(scene->mlx->mlx, "textures/jupiter.xpm");
		material.bump = NULL;
	}
	else if (number == 14)//earth + bump
	{
		sub_fill(-1, 0, -1, &material);
		material.texture = read_xpm_file(scene->mlx->mlx, "textures/earth.xpm");
		material.bump = read_xpm_file(scene->mlx->mlx, "textures/earth.xpm");
	}
	return (material);
}
