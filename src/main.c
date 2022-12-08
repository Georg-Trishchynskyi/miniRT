/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:12:34 by admin             #+#    #+#             */
/*   Updated: 2022/12/08 16:52:54 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int main(int argc, char **argv)
{
	void *mlx;
	t_scene *scene;
	void *window;

	if (argc < 2)
		fatal_error("no map file");
	if (!ft_strcmp(argv[1], ".rt"))
		fatal_error("incorect file");
	scene = parse_scene(argv[1]);
	mlx = mlx_init();
	window = mlx_new_window(mlx, 800, 400, "minirt");
	mlx_loop(mlx);

	return (1);
}