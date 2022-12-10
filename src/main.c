/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:12:34 by admin             #+#    #+#             */
/*   Updated: 2022/12/10 14:27:20 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main(int argc, char **argv)
{
	void *mlx;
	t_scene *scene;
	void *window;
	(void)argv;
	(void)argc;

	// if (argc < 2)
	// 	fatal_error("no map file");
	// if (!ft_strnstr(argv[1], ".rt", ft_strlen(argv[1])))
	// 	fatal_error("incorect file");
	scene = parse_scene("scene/basic.rt");
	mlx = mlx_init();
	window = mlx_new_window(mlx, 800, 400, "minirt");
	mlx_loop(mlx);

	return (1);
}