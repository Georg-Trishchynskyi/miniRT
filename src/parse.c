/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:01:23 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/12/10 14:26:47 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

void parse(char *str, t_scene *scene)
{
	if (*str == 'p' && *(str + 1) == 'l' && str++)
		parse_plane(&str, &scene->figures);
	else if (*str == 'l' && str++)
		parse_light(&str, &scene->lights);
	else if (*str == 'A' && str++)
		parse_ambient(&str, scene);
	else if (*str == 'c' &&*(str + 1) == 'y' && str++)
		parse_cylinder(&str, &scene->figures);
	else if (*str == 'c' && str++)
		parse_camera(&str, scene);
	else if (*str == 's' && *(str + 1) == 'p' && str++)
		parse_sphere(&str, &scene->figures);
	else if (*str == 't' && *(str + 1) == 'r' && str++)
		parse_triangle(&str, &scene->figures);
}

t_scene *parse_scene(char *file_name)
{
	int fd = open(file_name, O_RDONLY);
	char *str;
	t_scene *scene;
	if(fd == -1)
		fatal_error("no such file");
	scene = (t_scene *)malloc(sizeof(t_scene));
	scene->figures = NULL;
	scene->lights = NULL;
	str = get_next_line(fd);
	while (str)
	{
		parse(str, scene);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	return scene;
}
