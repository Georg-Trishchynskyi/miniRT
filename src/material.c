/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:52:24 by gpinchuk          #+#    #+#             */
/*   Updated: 2023/01/18 14:12:51 by gpinchuk         ###   ########.fr       */
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
	}
	else if  (number == 2)
	{		
		material.gloss = 1000;
		material.reflective = 0.3;
		material.refract = -1;
	}
	else if  (number == 3)
	{
		material.gloss = -1;
		material.reflective = 0;
		material.refract = 1.2;
	}
	else
	{
		material.gloss = -1;
		material.reflective = 0;
		material.refract = -1;	
	}
	return (material);
}