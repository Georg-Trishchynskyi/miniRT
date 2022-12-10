/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_shapes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:08:10 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/12/10 14:09:30 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void parse_plane(char **str, t_figures **figures)
{
	t_figures *temp;

	add_end_f(figures);
	temp = *figures;
	while(temp->next)
		temp = temp->next;
	temp->flag = PL;
	next(str);
	temp->figures.pl.centr = read_vec(str);
	next(str);
	temp->figures.pl.orient = read_vec(str);
	next(str);
	temp->collor = read_vec(str);
	
}

void parse_sphere(char **str, t_figures **figures)
{
	t_figures *temp;

	add_end_f(figures);
	temp = *figures;
	while(temp->next)
		temp = temp->next;
	temp->flag = SP;
	next(str);
	temp->figures.sp.centr = read_vec(str);
	next(str);
	temp->figures.sp.radius = stof(str);
	next(str);
	temp->collor = read_vec(str);
	
}

void parse_triangle(char **str, t_figures ** figures)
{
	t_figures *temp;

	add_end_f(figures);
	temp = *figures;
	while(temp->next)
		temp = temp->next;
	temp->flag = TR;
	next(str);
	temp->figures.tr.p1 = read_vec(str);
	next(str);
	temp->figures.tr.p2 = read_vec(str);
	next(str);
	temp->figures.tr.p3 = read_vec(str);
	next(str);
	temp->collor = read_vec(str);	
}

void parse_cylinder(char **str, t_figures ** figures)
{
	t_figures *temp;

	add_end_f(figures);
	temp = *figures;
	while(temp->next)
		temp = temp->next;
	temp->flag = CY;
	next(str);
	temp->figures.cy.centr = read_vec(str);
	next(str);
	temp->figures.cy.orient = read_vec(str);
	next(str);
	temp->figures.cy.di = stof(str);
	next(str);
	temp->figures.cy.height = stof(str);
	next(str);
	temp->collor = read_vec(str);
}