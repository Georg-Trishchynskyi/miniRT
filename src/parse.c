/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:01:23 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/12/08 16:19:23 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_scene *parse(char *file_name)
{
	int fd = open(file_name, O_RDONLY);
	char *str;
	t_scene *scene;
	if(!fd)
		return NULL;
	scene = (t_scene *)malloc(sizeof(t_scene));
	str = get_next_line(fd);
	while (str)
	{      
		temp_parse(str, scene);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	return scene;
}

void temp_parse(char *str, t_scene *scene)
{
	
}