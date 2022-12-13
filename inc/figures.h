/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:45:17 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/12/13 13:38:45 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIGURES_H
# define FIGURES_H
# define SP 1
# define PL 2
# define TR 3
# define CY 4

# include "../inc/minirt.h"

typedef struct s_sphere
{
	t_p3		centr;
	float		radius;
}				t_sphere;

typedef struct s_plane
{
	t_p3		centr;
	t_p3		orient;
}				t_plane;

typedef struct s_triangle
{
	t_p3		p1;
	t_p3		p2;
	t_p3		p3;
}				t_triangle;

typedef struct s_cylinder
{
	t_p3		centr;
	t_p3		orient;
	float		di;
	float		height;
}				t_cylinder;

// typedef struct s_square
// {
// 	t_p3		centr;
// 	t_p3		orient;
// 	float		scale;
// }				t_square;

union u_figures
{
	t_sphere	sp;
	t_plane		pl;
	t_triangle	tr;
	t_cylinder	cy;
	// t_square	sq;
};

typedef struct s_figures
{
	int				flag;
	union u_figures	figures;
	t_p3			collor;
	// t_p3			*pos;
	struct s_figures *next;
}				t_figures;

//PARSE
void	parse_plane(char **str, t_figures **figures);
void	parse_sphere(char **str, t_figures **figures);
void	parse_triangle(char **str, t_figures ** figures);
void	parse_cylinder(char **str, t_figures ** figures);

#endif