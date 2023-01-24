/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:52:24 by gpinchuk          #+#    #+#             */
/*   Updated: 2023/01/24 15:24:18 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	sub_fill(int gloss, double reflection, \
			double refract, t_material *material)
{
	(*material).gloss = gloss;
	(*material).reflective = reflection;
	(*material).refract = refract;
}

void	second_part(int number, t_material *material, t_scene *scene)
{
	if (number == 2)
	{		
		sub_fill(1000, 0.3, -1, material);
		material->texture = NULL;
		material->bump = NULL;
	}
	else if (number == 3)
	{
		sub_fill(-1, 0, 1.2, material);
		material->texture = NULL;
		material->bump = NULL;
	}
	else if (number == 4)
	{
		sub_fill(-1, 0, -1, material);
	material->texture = read_xpm_file(scene->mlx->mlx, "textures/World.xpm");
		material->bump = read_xpm_file(scene->mlx->mlx, "textures/bump1.xpm");
	}
	else if (number == 5)
	{
		sub_fill(-1, 0.95, -1, material);
		material->texture = NULL;
		material->bump = NULL;
	}
}

void	checker_bord(t_material *material)
{
		material->texture = malloc(sizeof(t_texture));
		material->texture->height = 1;
		material->texture->width = 1;
		material->texture->pix_arr = NULL;
		material->bump = NULL;
}

t_material	fill_material(char **str, t_scene *scene)
{
	t_material	material;
	int			number;

	number = (int)stof(str, scene, 3);
	if (number == 1)
	{
		sub_fill(-1, 0, -1, &material);
		material.texture = NULL;
		material.bump = NULL;
	}
	else if (number > 1 && number < 6)
		second_part(number, &material, scene);
	else if (number == 6)
	{
		sub_fill(-1, 0, -1, &material);
	material.texture = read_xpm_file(scene->mlx->mlx, "textures/HemiSun.xpm");
		material.bump = NULL;
	}
	else if (number == 7)
	{
		sub_fill(-1, 0, -1, &material);
		checker_bord(&material);
	}
	return (material);
}
