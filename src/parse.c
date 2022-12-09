/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:01:23 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/12/09 19:20:14 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_figures *new_lst(void)
{
	t_figures *new;

	new = (t_figures *)malloc(sizeof(t_figures));
	new->next = NULL;
	return new;
}

void addend(t_figures **figures)
{
	t_figures *temp;

	if(!(*figures))
	{
		*figures = new_lst();
		return ;
	}
	temp = *figures;
	while(temp->next)
		temp = temp->next;
	temp->next = new_lst();
}

void next(char **str)
{
	while(!(ft_isdigit(**str)) || **str == '-')
		(*str)++;
}

float stof(char **str)
{
	int		w;
	float	d;
	int		neg;

	w = 0;
	neg = 1;
	if (**str == '-' && *((*str)++))
		neg = -1;
	while (ft_isdigit(**str))
	{
		w = w * 10 + ((**str) - '0');
		(*str)++;
	}
	if (**str == '.')
		(*str)++;
	d = 0.0;
	while (ft_isdigit(**str))
		d = d * 10 + (*((*str)++) - '0');
	while (d >= 1)
		d /= 10;
	d += w;
	return (d * neg);
}

t_p3 read_vec(char **str)
{
	t_p3 new;

	new.x = stof(str);
	(*str)++;
	new.y = stof(str);
	(*str)++;
	new.z = stof(str);
	(*str)++;
	return new;
}

void parse_plane(char **str, t_figures **figures)
{
	t_figures *temp;

	addend(figures);
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

	addend(figures);
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

void parse_ambient(char **str, t_scene *scene)
{
	next(str);
	scene->a_scale = stof(str);
	next(str);
	scene->a_color = read_vec(str);
}

void parse_triangle(char **str, t_figures ** figures)
{
	t_figures *temp;

	addend(figures);
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

	addend(figures);
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

void parse(char *str, t_scene *scene)
{
	if (*str == 'p' && *(str + 1) == 'l' && str++)
		parse_plane(&str, &scene->figures);
	// else if (*str == 'l' && str++)
	// 	parse_ambient(&str, scene);
	else if (*str == 'A' && str++)
		parse_ambient(&str, scene);
	else if (*str == 'c' &&*(str + 1) == 'y' && str++)
		parse_cylinder(&str, &scene->figures);
	// else if (*str == 's' && *(str + 1) == 'q' && str++)
	// 	parse_plane(&str, figures);
	else if (*str == 's' && *(str + 1) == 'p' && str++)
		parse_sphere(&str, &scene->figures);
	else if (*str == 't' && *(str + 1) == 'r' && str++)
		parse_triangle(&str, &scene->figures);
}

t_scene *parse_scene(char *file_name)
{
	int fd = open(file_name, O_RDONLY);
	char *str;
	t_scene *scene;
	if(!fd)
		return NULL;
	scene = (t_scene *)malloc(sizeof(t_scene));
	scene->figures = NULL;
	str = get_next_line(fd);
	while (str)
	{
		parse(str, scene);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	return scene;
}
