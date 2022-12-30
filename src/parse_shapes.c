/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:08:10 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/12/28 14:07:31 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void parse_plane(char **str, t_scene *scene)
{
	t_figures *temp;

	add_end_f(&scene->figures);
	temp = scene->figures;
	while(temp->next)
		temp = temp->next;
	temp->flag = PL;
	next(str, scene);
	temp->figures.pl.centr = read_vec(str, scene, 0);
	next(str, scene);
	temp->figures.pl.orient = read_vec(str, scene, 2);
	next(str, scene);
	temp->collor = read_vec(str, scene, 1);
	temp->blesk = -1;
}

void parse_sphere(char **str, t_scene *scene)
{
	t_figures *temp;

	add_end_f(&scene->figures);
	temp = scene->figures;
	while(temp->next)
		temp = temp->next;
	temp->flag = SP;
	next(str, scene);
	temp->figures.sp.centr = read_vec(str, scene, 0);
	next(str, scene);
	temp->figures.sp.radius = stof(str, scene, 2) / 2;
	next(str, scene);
	temp->collor = read_vec(str, scene, 1);
	temp->blesk = -1; 
}

void parse_triangle(char **str, t_scene *scene)
{
	t_figures *temp;
	
	add_end_f(&scene->figures);
	temp = scene->figures;
	while(temp->next)
		temp = temp->next;
	temp->flag = TR;
	next(str, scene);
	temp->figures.tr.p1 = read_vec(str, scene, 0);
	next(str, scene);
	temp->figures.tr.p2 = read_vec(str, scene, 0);
	next(str, scene);
	temp->figures.tr.p3 = read_vec(str, scene, 0);
	next(str, scene);
	temp->collor = read_vec(str, scene, 1);	
}

void parse_cylinder(char **str, t_scene *scene)
{
	t_figures *temp;

	add_end_f(&scene->figures);
	temp = scene->figures;
	while(temp->next)
		temp = temp->next;
	temp->flag = CY;
	next(str, scene);
	temp->figures.cy.centr = read_vec(str, scene, 0);
	next(str, scene);
	temp->figures.cy.orient = read_vec(str, scene, 0);
	next(str, scene);
	temp->figures.cy.di = stof(str, scene, 0);
	next(str, scene);
	temp->figures.cy.height = stof(str, scene, 0);
	next(str, scene);
	temp->collor = read_vec(str, scene, 1);
}