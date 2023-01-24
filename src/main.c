/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:12:34 by admin             #+#    #+#             */
/*   Updated: 2023/01/24 16:27:12 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_mlx(t_scene *scene)
{
	scene->mlx = malloc(sizeof(t_mlx));
	scene->mlx->bits_per_pixel = 0;
	scene->mlx->line_length = 0;
	scene->mlx->endian = 0;
	scene->mlx->mlx = mlx_init();
	scene->mlx->window = mlx_new_window(scene->mlx->mlx, \
	scene->width, scene->height, "minirt");
	scene->mlx->img = mlx_new_image(scene->mlx->mlx, \
	scene->width, scene->height);
	scene->mlx->addr = mlx_get_data_addr(scene->mlx->img, \
	&scene->mlx->bits_per_pixel, &scene->mlx->line_length, &scene->mlx->endian);
}

int	main(int argc, char **argv)
{
	t_scene	*scene;

	if (argc < 2)
		fatal_error("no map file");
	if (!ft_strnstr(argv[1], ".rt", ft_strlen(argv[1])))
		fatal_error("incorect file");
	scene = parse_scene(argv[1]);
	fprintf(stderr, "after parse\n");
	if (is_thread_safe(scene->figures))
		multithreaded_render(scene);
	else
		render_scene(scene);
	mlx_put_image_to_window(scene->mlx->mlx, \
		scene->mlx->window, scene->mlx->img, 0, 0);
	mlx_hook(scene->mlx->window, 2, 0, key, scene);
	mlx_hook(scene->mlx->window, 17, 0, escape, scene);
	mlx_loop(scene->mlx->mlx);
	return (1);
}
