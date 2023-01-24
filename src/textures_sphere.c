/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_sphere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:28:28 by fstaryk           #+#    #+#             */
/*   Updated: 2023/01/24 13:54:44 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_p3	collorp_to_p3(t_color *pix)
{
	return (new_vec(pix->r, pix->g, pix->b));
}

void	cartesian_to_spherical(t_p3 p, double *rho, double *theta, double *phi)
{
	*rho = sqrt(p.x * p.x + p.y * p.y + p.z * p.z);
	*theta = atan2(p.y, p.x);
	*phi = acos(p.z / *rho);
}

void	get_sphere_texture_index(t_figures *fig, t_p3 inter_p, int ind[2])
{
	double	rho;
	double	theta;
	double	phi;
	double	u;
	double	v;

	cartesian_to_spherical(_substruct(inter_p, \
	fig->figures.sp.centr), &rho, &theta, &phi);
	u = (theta + M_PI) / (2 * M_PI);
	v = phi / M_PI;
	ind[0] = (u * fig->material.texture->width);
	ind[1] = (v * fig->material.texture->height);
}

t_p3	apply_texture_sphere(t_p3 p, t_figures *fig)
{
	int	ind[2];

	get_sphere_texture_index(fig, p, ind);
	return ((int_to_rgb(fig->material.texture->pix_arr[ind[1] * \
	fig->material.texture->width + ind[0]])));
	return (new_vec(0, 0, 0));
}

t_p3	apply_checkerboard_sphere(t_figures *fig, t_p3 p, \
							int checkered_w, int checkered_h)
{
	double	rho;
	double	theta;
	double	phi;
	int		u;
	int		v;

	cartesian_to_spherical(_substruct(p, \
	fig->figures.sp.centr), &rho, &theta, &phi);
	u = (int)(phi / (2 * M_PI) * checkered_w);
	v = (int)(theta / M_PI * checkered_h);
	if ((u + v) % 2 == 0)
		return (new_vec(250, 250, 250));
	return (new_vec(5, 5, 5));
}
