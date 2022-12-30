/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:12:34 by admin             #+#    #+#             */
/*   Updated: 2022/12/17 17:33:14 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void init_mlx(t_scene *scene)
{
	scene->mlx = malloc(sizeof(t_mlx));
	scene->mlx->bits_per_pixel = 0;
	scene->mlx->line_length = 0;
	scene->mlx->endian = 0;
	scene->mlx->mlx = mlx_init();
	scene->mlx->window = mlx_new_window(scene->mlx->mlx, scene->width, scene->height, "minirt");	
	scene->mlx->img = mlx_new_image(scene->mlx->mlx, scene->width, scene->height);
	scene->mlx->addr = mlx_get_data_addr(scene->mlx->img, \
	&scene->mlx->bits_per_pixel, &scene->mlx->line_length, &scene->mlx->endian);
}

int main(int argc, char **argv)
{
	// void *mlx;
	t_scene *scene;
	// void *window;
	(void)argv;
	(void)argc;

	if (argc < 2)
		fatal_error("no map file");
	if (!ft_strnstr(argv[1], ".rt", ft_strlen(argv[1])))
		fatal_error("incorect file");
	scene = parse_scene(argv[1]);
	// while(scene->figures)
	// {
	// 	fprintf(stderr, "|||| %f, %f ,%f ||||\n", scene->figures->collor.x, scene->figures->collor.y, scene->figures->collor.z);
	// 	scene->figures = scene->figures->next;
	// }
	init_mlx(scene);
	print_scene(scene);
	render_scene(scene);
	mlx_put_image_to_window(scene->mlx->mlx, scene->mlx->window, scene->mlx->img, 0, 0);
	mlx_loop(scene->mlx->mlx);
	return (1);
}