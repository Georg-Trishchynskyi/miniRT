/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 17:14:41 by gpinchuk          #+#    #+#             */
/*   Updated: 2023/01/22 21:24:14 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	key(int key, t_scene *scene)
{
	if (key == 53)
	{
		free_scene(scene);
		exit(0);
	}
	return (0);
}

int escape(t_scene *scene)
{
	free_scene(scene);
	exit(0);
	return (0);
}