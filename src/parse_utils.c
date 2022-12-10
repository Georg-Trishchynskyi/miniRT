/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 14:09:44 by gpinchuk          #+#    #+#             */
/*   Updated: 2022/12/10 14:45:34 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void next(char **str)
{
	while(!(ft_isdigit(**str)))
	{
		if(**str == '-')
			break;
		(*str)++;
	}
}

float stof(char **str)
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
	return (d * neg);
}

t_p3 read_vec(char **str)
{
	t_p3 new;

	new.x = stof(str);
	(*str)++;
	new.y = stof(str);
	(*str)++;
	new.z = stof(str);
	(*str)++;
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
