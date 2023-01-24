/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:54:54 by gpinchuk          #+#    #+#             */
/*   Updated: 2023/01/24 15:02:22 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void	sub_reflection(t_p3 inter_p, t_p3 d, t_figures *fig, t_p3 *refl)
{
	t_p3	bump_norm;

	*refl = _substruct(inter_p, fig->figures.sp.centr);
	if (vcos(d, *refl) > 0)
	{
		*refl = _multy(*refl, -1);
		fig->figures.sp.inside = 1;
	}
	else
		fig->figures.sp.inside = 0;
	if (fig->material.bump != NULL)
	{
		bump_norm = sample_bump_map(inter_p, fig);
		*refl = bump_norm;
	}
}

t_p3	calculate_base_reflection(t_p3 inter_p, t_p3 d, t_figures *fig)
{
	t_p3	refl;

	if (fig->flag == SP)
	{
		sub_reflection(inter_p, d, fig, &refl);
	}
	else if (fig->flag == PL)
		refl = fig->figures.pl.orient;
	else if (fig->flag == CY)
		refl = fig->figures.cy.normal;
	else if (fig->flag == HY)
		refl = hyberboloid_normal(inter_p, fig->figures.hy);
	else if (fig->flag == TR)
		refl = calculate_triangle_normal(fig->figures.tr);
	return (refl);
}

bool	is_blocked(t_p3 dir_to_light, t_p3 inter_p, t_figures *fig)
{
	double	inter;

	while (fig)
	{
		if (fig->flag == SP && fig->material.refract <= 0)
			inter = sphere_intersection(dir_to_light, inter_p, fig);
		else if (fig->flag == PL)
			inter = plane_intersection(dir_to_light, inter_p, \
			fig->figures.pl.orient, fig->figures.pl.centr);
		else if (fig->flag == HY)
			inter = hyperboloid_intersection(dir_to_light, \
			inter_p, fig->figures.hy);
		else if (fig->flag == CY)
			inter = cylinder_intersection(dir_to_light, inter_p, fig);
		else if (fig->flag == TR)
			inter = trinagle_intersection(dir_to_light, \
			inter_p, fig->figures.tr);
		if (inter > 1e-4 && inter < 1)
			return (true);
		fig = fig->next;
	}
	return (false);
}

double	calculate_gloss(t_inter inter, \
t_figures figure, t_lights *light, t_p3 view_vec)
{
	t_p3	r_vec;
	t_p3	dir_to_light;

	dir_to_light = _substruct(light->light.pos, inter.p);
	r_vec = _substruct(_multy(_multy(inter.n, 2), \
	_dot(inter.n, dir_to_light)), dir_to_light);
	if (_dot(r_vec, view_vec) > 0)
	{
		return (light->light.scale * \
		powf(vcos(r_vec, view_vec), figure.material.gloss));
	}
	else
		return (0);
}

//change figure to pointer
int	calculate_light(t_inter i, t_scene *scene, t_p3 view_vec, t_figures figure)
{
	double		ret_light;
	t_lights	*light;
	t_p3		dilight;
	t_p3		rgb;

	light = scene->lights;
	ret_light = 0.0f;
	rgb = new_vec(0, 0, 0);
	add_coeficient(&rgb, scene->a_scale, scene->a_color);
	while (light)
	{
		dilight = _substruct(light->light.pos, i.p);
		if (_dot(i.n, dilight) > 0 && !is_blocked(dilight, i.p, scene->figures))
		{
			ret_light = (light->light.scale * vcos(i.n, dilight));
			add_coeficient(&rgb, ret_light, light->light.rgb);
		}
		if (figure.material.gloss != -1)
		{
			ret_light = calculate_gloss(i, figure, light, view_vec);
			add_coeficient(&rgb, ret_light, light->light.rgb);
		}
		light = light->next;
	}
	return (rgb_to_int(get_collor_fig(&figure, i.p), rgb));
}
