/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_strarr_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:57:53 by fstaryk           #+#    #+#             */
/*   Updated: 2022/12/08 17:03:30 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_str_arr_len(char **strarr)
{
	int	i;

	if (!strarr)
		return (0);
	i = 0;
	while (strarr[i] != NULL)
		i++;
	return (i);
}
