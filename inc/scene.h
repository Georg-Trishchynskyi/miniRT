/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:41:34 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/12/09 18:10:00 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "minirt.h"

typedef struct	s_cam
{
	t_p3		pos;
	t_p3		direct;
	float		angle;
}				t_cam;

typedef struct s_light
{
	t_p3		pos;
	t_p3		scale;
	t_p3		rgb;
}				t_light;


typedef struct	s_scene
{
	t_cam		*camera;
	t_figures	*figures;
	t_light		*lights;
	float		a_scale;
	t_p3		a_color;
}				t_scene;

//CMAERA
t_cam *new_camera(t_p3 pos, t_p3 dir, float angle);

//SCENE

#endif