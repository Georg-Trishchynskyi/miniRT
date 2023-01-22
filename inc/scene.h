/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:41:34 by gpinchuk          #+#    #+#             */
/*   Updated: 2023/01/22 20:57:16 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "minirt.h"

typedef struct	s_cam
{
	t_p3		pos;
	t_p3		direct;
	double		fov;
	double		fov_l;
}				t_cam;

typedef struct s_light
{
	t_p3		pos;
	double		scale;
	t_p3		rgb;
}				t_light;

typedef struct s_lights
{
	t_light			light;
	struct s_lights	*next;
}				t_lights;

typedef struct s_mlx
{
	void		*mlx;
	void		*window;
	void		*img;
	int			bits_per_pixel;
	int			line_length;
	char		*addr;	
	int			endian;
}				t_mlx;

typedef struct s_temp_img
{
	char	*img_data;
	int		img_bp;
	int		img_sl;
	int		img_e;
}				t_temp_img;



typedef struct	s_scene
{
	t_cam		*camera;
	t_figures	*figures;
	t_lights	*lights;
	t_mlx		*mlx;
	double		aspect_ratio;
	int			height;
	int			width;
	double		a_scale;
	t_p3		a_color;
	int			background;
	
}				t_scene;

typedef struct	s_thread_data
{
	t_scene		*scene;
	int			index;	
}				t_thread_data;

//PARSE
void	parse_ambient(char **str, t_scene *scene);
void	parse_camera(char **str, t_scene *scene);
void	parse_light(char **str, t_scene *scene);

//CMAERA
// t_cam *new_camera();

//SCENE

#endif