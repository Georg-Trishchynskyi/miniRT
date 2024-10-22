/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:31:19 by gpinchuk          #+#    #+#             */
/*   Updated: 2023/01/24 16:34:45 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <pthread.h>

# include "vector.h"
# include "figures.h"
# include "get_next_line.h"
# include "libft.h"
# include "scene.h"

# define EPSILON 0.00001
# define NUM_THREADS 12

//ERRORS
int			print_error(char *str);
void		fatal_error(char *str);
void		fatal_error_v2(t_scene *scene);
void		free_scene(t_scene *scene);
void		exit_error(int code);
void		check_stof(double num, t_scene *scene, int flag);
void		parse_error(t_scene *scene, int fd);

//PARSING
t_scene		*parse_scene(char *file_name);
void		parse_sphere(char **str, t_scene *scene);
void		parse_plane(char **str, t_scene *scene);
void		parse_triangle(char **str, t_scene *scene);
void		parse_cylinder(char **str, t_scene *scene);
void		parse_hyperboloid(char **str, t_scene *scene);

//UTILS
void		add_end_f(t_figures **figures);
t_figures	*new_lst_f(void);
t_p3		ead_vec(char **str, t_scene *scene, int flag);
double		stof(char **str, t_scene *scene, int flag);
void		next(char **str, t_scene *scene);

void		my_mlx_pixel_put(t_scene *scene, int x, int y, int color);

//MATERIAL
t_material	fill_material(char **str, t_scene *scene);
t_material	init_material(void);

//LIGHTS

t_p3		calculate_base_reflection(t_p3 inter_p, t_p3 d, t_figures *fig);
int			calculate_light(t_inter i, t_scene *scene, \
						t_p3 view_vec, t_figures figure);

//COLORS
void		add_coeficient(t_p3 *rgb, double coef, t_p3 color);
int			rgb_to_int(t_p3 color, t_p3 rgb);
int			_cadd(int color_a, int color_b);
int			_cproduct(int color, double coef);
t_p3		color_x_light(t_p3 base_color, t_p3 light_collor);

double		vcos(t_p3 v1, t_p3 v2);

//intersections

double		try_intersections(t_p3 d, t_p3 cam_o, \
			t_figures *fig, t_figures *closest_fig);
double		sphere_intersection(t_p3 d, t_p3 o, t_figures *lst);
double		plane_intersection(t_p3 d, t_p3 cam_o, t_p3 pl_n, t_p3 pl_o);
double		trinagle_intersection(t_p3 d, t_p3 cam_o, t_triangle tri);

//render
void		render_scene_with_thread(t_scene *scene, int thread_id);
void		render_scene(t_scene *scene);

//Trace ray

int			trace_ray(t_p3 d, t_p3 O, t_scene *scene, int depth);

void		print_p3(t_p3 x);
void		print_scene(t_scene *scene);
double		trinagle_intersection(t_p3 d, t_p3 cam_o, t_triangle tri);
t_p3		calculate_triangle_normal(t_triangle tri);
//cylinder

double		cylinder_intersection(t_p3 d, t_p3 cam_o, t_figures *cy);

//keyhook
int			key(int key, t_scene *scene);
int			escape(t_scene *scene);
void		init_mlx(t_scene *scene);

//Hyperboloid
double		hyperboloid_intersection(t_p3 d, t_p3 cam_o, t_hyper_b hy);
t_p3		hyberboloid_normal(t_p3 inter_p, t_hyper_b hy);

//Texture
t_p3		apply_checkerboard_sphere(t_figures *fig, t_p3 p, \
							int checkered_w, int checkered_h);
t_p3		apply_texture_sphere(t_p3 p, t_figures *fig);
t_p3		sample_bump_map(t_p3 inter_p, t_figures *closest_figure);
t_texture	*load_textures(void *mlx, char *texture_path);
t_p3		get_collor_fig(t_figures *fig, t_p3 p);
void		get_sphere_texture_index(t_figures *fig, t_p3 inter_p, int ind[2]);

t_p3		int_to_rgb(int x);
t_texture	*read_xpm_file(void *mlx, char *filename);

//MULTI_THREADING
void		multithreaded_render(t_scene *scene);

//Utils

void		double_inter_case_cylinder(double *dist, double *x, \
									double *x2, t_figures *fig);
bool		is_thread_safe(t_figures *fig);

#endif