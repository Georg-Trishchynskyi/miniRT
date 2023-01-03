/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:21:33 by admin             #+#    #+#             */
/*   Updated: 2022/12/30 16:55:22 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int print_error(char *str)
{
	write(2, str, ft_strlen(str));
	return -1;
}

void fatal_error(char *str)
{
	//free something//
	perror(str);
	exit(0);
}

void fatal_error_v2(t_scene *scene)
{
	ft_putstr_fd("error in map", 2);
	free_scene(scene);
	exit(0);
}

void check_stof(float num, t_scene *scene, int flag)
{
	if(flag == 0)
		return ;	
	else if (flag == 1 && (num < 0 || num > 1))
		fatal_error_v2(scene);	
	else if (flag == 2 && (num < 0 || num > 180))
		fatal_error_v2(scene);	
	else if (flag == 3 && (num < 1 || num > 5))
		fatal_error_v2(scene);
}