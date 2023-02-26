/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:21:33 by admin             #+#    #+#             */
/*   Updated: 2023/01/24 16:34:56 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_error(t_scene *scene, int fd)
{
	close(fd);
	fatal_error_v2(scene);
}

int	print_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (-1);
}

void	fatal_error(char *str)
{
	perror(str);
	exit(0);
}

void	fatal_error_v2(t_scene *scene)
{
	ft_putstr_fd("error in map", 2);
	free_scene(scene);
	exit(0);
}

void	check_stof(double num, t_scene *scene, int flag)
{
	if (flag == 0)
		return ;
	else if (flag == 1 && (num < 0 || num > 1))
		fatal_error_v2(scene);
	else if (flag == 2 && (num < 0 || num > 180))
		fatal_error_v2(scene);
	else if (flag == 3 && (num < 1 || num > 10))
		fatal_error_v2(scene);
}
