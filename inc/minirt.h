/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:41:25 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/12/13 13:41:17 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
#define MINIRT_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>

# include "vector.h"
# include "figures.h"
# include "get_next_line.h"
# include "libft.h"
# include "scene.h"

//#define PI_180 0.0174532925f

//ERRORS
int		print_error(char *str);
void	fatal_error(char *str);
void	exit_error(int code);

//PARSING
t_scene	*parse_scene(char *file_name);

//UTILS
void add_end_f(t_figures **figures);
t_figures *new_lst_f(void);
t_p3 read_vec(char **str);
float stof(char **str);
void next(char **str);

void	my_mlx_pixel_put(t_scene *scene, int x, int y, int color);


//Utils

int rgb_int(t_p3 col);

//render
void render_scene(t_scene *scene);

void print_p3(t_p3 x);
void print_scene(t_scene *scene);

#endif