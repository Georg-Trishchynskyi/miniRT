/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: statvej <statvej@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:12:19 by fstaryk           #+#    #+#             */
/*   Updated: 2022/05/10 18:38:34 by statvej          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// //Function should return a string trimed of reminder after nl or '\0'
char	*trim_ret_str(char *left_over)
{
	int		ind;
	char	*ret;

	ind = 0;
	if (!left_over[0])
		return (NULL);
	while (left_over[ind] && left_over[ind] != '\n')
		ind++;
	ret = (char *)malloc(sizeof(char) * (ind + 2));
	if (!ret)
		return (NULL);
	ind = 0;
	while (left_over[ind] && left_over[ind] != '\n')
	{
		ret[ind] = left_over[ind];
		ind++;
	}
	if (left_over[ind] == '\n')
	{
		ret[ind] = left_over[ind];
		ind++;
	}
	ret[ind] = 0;
	return (ret);
}

char	*get_next_line(int fd)
{
	static char	*left_over;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left_over = get_untrimed(left_over, fd);
	if (!left_over)
	{
		return (NULL);
	}
	ret = NULL;
	ret = trim_ret_str(left_over);
	left_over = get_left_over(left_over);
	return (ret);
}
