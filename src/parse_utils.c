/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:09:44 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/12/28 14:11:11 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void next(char **str, t_scene *scene)
{
	while(!(ft_isdigit(**str)))
	{
		if(**str == ',' || **str == '.')
			fatal_error_v2(scene);
		if(**str == '-')
			break;
		(*str)++;
	}
}

float stof(char **str, t_scene *scene, int flag)
{
	int		w;
	float	d;
	int		neg;

	w = 0;
	neg = 1;
	if (**str == '-' && *((*str)++))
		neg = -1;
	while (ft_isdigit(**str))
	{
		w = w * 10 + ((**str) - '0');
		(*str)++;
	}
	if (**str == '.')
		(*str)++;
	d = 0.0;
	while (ft_isdigit(**str))
		d = d * 10 + (*((*str)++) - '0');
	while (d >= 1)
		d /= 10;
	d += w;
	check_stof(d * neg, scene, flag);
	return (d * neg);
}

t_p3 read_vec(char **str, t_scene *scene, int flag)
{
	t_p3 new;

	(void)scene;
	new.x = stof(str, scene, 0);
	(*str)++;
	new.y = stof(str, scene, 0);
	(*str)++;
	new.z = stof(str, scene, 0);
	if (flag == 1 && (new.x > 255 || new.x < 0 || new.y > 255 || \
			new.y < 0 || new.z > 255 || new.z < 0))
			fatal_error_v2(scene);
	else if (flag == 2 && (new.x > 5 || new.x < -2 || new.y > 1 || \
			new.y < -1 || new.z > 1 || new.z < -1))
			fatal_error_v2(scene);
	return new;
}

t_figures *new_lst_f(void)
{
	t_figures *new;

	new = (t_figures *)malloc(sizeof(t_figures));
	new->next = NULL;
	return new;
}

void add_end_f(t_figures **figures)
{
	t_figures *temp;

	if(!(*figures))
	{
		*figures = new_lst_f();
		return ;
	}
	temp = *figures;
	while(temp->next)
		temp = temp->next;
	temp->next = new_lst_f();
}
