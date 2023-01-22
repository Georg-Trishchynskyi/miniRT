/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:28:28 by fstaryk           #+#    #+#             */
/*   Updated: 2023/01/22 21:22:13 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_p3 collorp_to_p3(t_color *pix){
    return new_vec(pix->r, pix->g, pix->b);
}

void cartesian_to_spherical(t_p3 p, double *rho, double *theta, double *phi) {
    *rho = sqrt(p.x*p.x + p.y*p.y + p.z*p.z);
    *theta = atan2(p.y, p.x);
    *phi = acos(p.z / *rho);
}


void get_sphere_texture_index(t_figures *fig, t_p3 inter_p, int ind[2]){
    double rho, theta, phi;
    cartesian_to_spherical(_substruct(inter_p, fig->figures.sp.centr), &rho, &theta, &phi);
    double u = (theta + M_PI) / (2 * M_PI);
    double v = phi / M_PI;
    ind[0] = (u * fig->material.texture->width);
    ind[1] = (v * fig->material.texture->height);
}

t_p3 apply_texture_sphere(t_p3 p, t_figures *fig) {
    int ind[2];
    
    get_sphere_texture_index(fig, p, ind);
    // if()
    // if(ind[1] < fig->material.texture->height && ind[0] < fig->material.texture->width )
    // fprintf(stderr, "\nheight is %d and width is %d\n0 is %d, 1 is %d\n", fig->material.texture->height, fig->material.texture->width, ind[0], ind[1]);
    return (int_to_rgb(fig->material.texture->pix_arr[ind[1] * fig->material.texture->width + ind[0]]));
    return new_vec(0, 0, 0);
}

t_p3 apply_checkerboard_sphere(t_figures *fig, t_p3 p, int checkered_w, int checkered_h)
{
    double rho, theta, phi;
    cartesian_to_spherical(_substruct(p, fig->figures.sp.centr), &rho, &theta, &phi);
    int u = (int)(phi / (2 * M_PI) * checkered_w);
    int v = (int)(theta / M_PI * checkered_h);

    if((u + v) % 2 == 0)
        return new_vec(250,250,250);
    return new_vec(5, 5, 5);
}


t_p3 get_collor_fig(t_figures *fig, t_p3 p)
{
    if(fig->material.texture == NULL)
        return fig->collor;
    else if(fig->flag == SP && fig->material.texture->width == 1 && fig->material.texture->height == 1)
        return apply_checkerboard_sphere(fig, p, 30, 15);  
    else if(fig->flag == SP)
        return apply_texture_sphere(p, fig);
    return fig->collor;
}