/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 15:34:13 by fstaryk           #+#    #+#             */
/*   Updated: 2022/12/13 14:16:20 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void print_p3(t_p3 x){
    printf("(%f;%f;%f)\n", x.x, x.y, x.z);
}

void print_sphere(t_figures *fig){
    printf("\n\t SPHERE\nradius is %f\n", fig->figures.sp.radius);
    print_p3(fig->figures.sp.centr);
}

void print_figures(t_figures *fig){
    while (fig)
    {
        if(fig->flag == SP)
            print_sphere(fig);
        fig = fig->next;
    }
    
}

void print_camera(t_cam *cam){
    printf("\n\tCAMERA\n");
    printf("directions is ");
    print_p3(cam->direct);
    printf("position is ");
    print_p3(cam->pos);
    printf("fov %f, fov actual %f\n", cam->fov, cam->fov_l);
}

void print_scene(t_scene *scene)
{
    printf("Aspect ratio %f\n background color is %d\nwidth is %d, height is %d\n", scene->aspect_ratio, scene->background, scene->width, scene->height);
    print_camera(scene->camera);
    print_figures(scene->figures);
    
}