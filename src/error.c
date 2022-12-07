/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: admin <admin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:21:33 by admin             #+#    #+#             */
/*   Updated: 2022/12/06 18:50:22 by admin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int print_error(char *str)
{
	perror(str);
	return -1;
}

void fatal_error(char *str)
{
	//free something//
	perror(str);
	exit(0);
}

void exit_error(int code)
{
	perror("((((((((((((((((((((((((((");
	exit(code);
}