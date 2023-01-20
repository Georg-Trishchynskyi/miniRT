/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 13:28:28 by fstaryk           #+#    #+#             */
/*   Updated: 2023/01/20 19:00:07 by gpinchuk         ###   ########.fr       */
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

// void apply_sphere_texture(t_p3 p, double *o_x, double *o_y, double *o_z, int *texture, int texture_width, int texture_height, int *red, int *green, int *blue) {
//     double rho, theta, phi;
//     cartesian_to_spherical(x - *o_x, y - *o_y, z - *o_z, &rho, &theta, &phi);
//     double u = (theta + M_PI) / (2 * M_PI);
//     double v = phi / M_PI;
//     int texture_x = u * texture_width;
//     int texture_y = v * texture_height;
//     int pixel = texture[texture_y * texture_width + texture_x];
//     *red = (pixel >> 16) & 0xff;
//     *green = (pixel >> 8) & 0xff;
//     *blue = pixel & 0xff;
// }


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
    fprintf(stderr, "\nheight is %d and width is %d\n0 is %d, 1 is %d\n", fig->material.texture->height, fig->material.texture->width, ind[0], ind[1]);
    return (int_to_rgb(fig->material.texture->pix_arr[ind[1] * fig->material.texture->width + ind[0]]));
    return new_vec(0, 0, 0);
}

t_p3 apply_checkerboard(t_figures *fig, t_p3 p, int checkered_w, int checkered_h)
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
    // else if(fig->flag == SP)
    //     return apply_checkerboard(fig, p, 30, 15);  
    else if(fig->flag == SP)
        return apply_texture_sphere(p, fig);
    return fig->collor;
}