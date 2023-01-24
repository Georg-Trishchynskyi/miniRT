/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figures.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:31:03 by gpinchuk          #+#    #+#             */
/*   Updated: 2023/01/24 15:07:30 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIGURES_H
# define FIGURES_H
# define SP 1
# define PL 2
# define TR 3
# define CY 4
# define HY 5

# include "minirt.h"

typedef struct s_sphere
{
	t_p3		centr;
	double		radius;
	int			inside;
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
	t_p3		o;
	t_p3		nv;
	double		r;
	double		h;
	t_p3		normal;
	double		dist1;
	double		dist2;
}				t_cylinder;

typedef struct s_color
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	a;
}					t_color;

typedef struct s_texture
{
	int			width;
	int			height;	
	int			*pix_arr;	
}				t_texture;

typedef struct s_material
{
	int			gloss;
	double		reflective;
	double		refract;
	t_texture	*texture;
	t_texture	*bump;
}				t_material;

typedef struct s_hyper_b
{
	t_p3		o;
	t_p3		param;
	t_p3		nv;
	double		r;
}				t_hyper_b;

union u_figures
{
	t_sphere	sp;
	t_plane		pl;
	t_triangle	tr;
	t_cylinder	cy;
	t_hyper_b	hy;
};

typedef struct s_figures
{
	int					flag;
	union u_figures		figures;
	t_p3				collor;
	t_material			material;
	struct s_figures	*next;
}				t_figures;

#endif