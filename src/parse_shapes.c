/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:08:10 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/12/08 16:06:14 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

new_ambient(char **source, t_scene *scene)
{
	
}

void create_plane(char **source, t_scene *scene)
{
	union u_figures	*plane;
	t_p3	*vec1;
	t_p3	*vec2;
	t_p3	*collor;

	vec1 = transform_to_float(source[1]);
	vec2 = transform_to_float(source[2]);
	collor = transform_to_float(source[3]);
	plane->pl = new_plane(vec1, vec2);
	add_figure(create_figure(plane, collor));
}

t_p3 *transform_to_float(char *str)
{
	
}

t_plane *new_plane(t_p3 *centr, t_p3 *orient)
{
	t_plane *new;

	new = (t_plane *)malloc(sizeof(t_plane));
	if (!new)
		fatal_error("plane was not allocated");
	new->centr = centr;
	new->orient = orient;
	return (new);
}

void add_figure(t_figures **head, t_figures *new)
{
	t_figures *temp;

	if (!(*head))
	{
		(*head) = new;
		return ;
	}
	if (!new)
		return ;
	temp = *head;
	while (temp->next)
		temp = temp->next;
	temp->next = new;	
}

t_figures *create_figure(union u_figures *figure, t_p3 *collor)
{
	t_figures *new;

	new = (t_figures*)malloc(sizeof(t_figures));
	if(!new)
		fatal_error("fugure was not allocated");
	new->figures = figure;
	new->collor = collor;
	new->next = NULL;
	return (new);
}