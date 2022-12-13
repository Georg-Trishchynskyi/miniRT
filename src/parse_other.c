/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:11:57 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/12/13 13:39:14 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_lights *new_lst_l(void)
{
	t_lights *new;

	new = (t_lights *)malloc(sizeof(t_lights));
	new->next = NULL;
	return new;
}

void add_end_l(t_lights **light)
{
	t_lights *temp;

	if(!(*light))
	{
		*light = new_lst_l();
		return ;
	}
	temp = *light;
	while(temp->next)
		temp = temp->next;
	temp->next = new_lst_l();
}

void parse_ambient(char **str, t_scene *scene)
{
	next(str);
	scene->a_scale = stof(str);
	next(str);
	scene->a_color = read_vec(str);
	scene->aspect_ratio = (float)scene->width / (float)scene->height;
}

void parse_camera(char **str, t_scene *scene)
{
	scene->camera = (t_cam*)malloc(sizeof(t_cam));
	if (!scene->camera)
		fatal_error("Camera was not allocated");
	next(str);
	scene->camera->pos = read_vec(str);
	next(str);
	scene->camera->direct = read_vec(str);
	next(str);
	scene->camera->fov = stof(str);
	scene->camera->fov_l = tan((scene->camera->fov * M_PI / 180) / 2);
}

void parse_light(char **str, t_lights **light)
{
	t_lights *temp;

	add_end_l(light);
	temp = *light;
	while(temp->next)
		temp = temp->next;
	next(str);
	temp->light.pos = read_vec(str);
	next(str);
	temp->light.scale = stof(str);
	next(str);
	temp->light.rgb = read_vec(str);
}
