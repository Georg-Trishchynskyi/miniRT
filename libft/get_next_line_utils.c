/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 13:12:33 by fstaryk           #+#    #+#             */
/*   Updated: 2022/05/11 14:18:41 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

char	*ft_strjoin_del1(char *left_over, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_over)
	{
		left_over = (char *)malloc(1 * sizeof(char));
		left_over[0] = '\0';
	}
	if (!left_over || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_over) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_over)
		while (left_over[++i] != '\0')
			str[i] = left_over[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(left_over) + ft_strlen(buff)] = '\0';
	free(left_over);
	return (str);
}

int	get_char_ind_in_str(char c, char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

//Function should return a string of leftover for next itteration
//Use this function ONLY after trim_ret_str
char	*get_left_over(char *left_over)
{
	int		ind;
	int		count;
	int		str_len;
	char	*ret;

	ind = 0;
	while (left_over[ind] && left_over[ind] != '\n')
		ind++;
	if (!left_over[ind])
	{
		free(left_over);
		return (NULL);
	}
	str_len = ft_strlen(left_over);
	ret = (char *)malloc(sizeof(char) * (str_len - ind + 1));
	if (!ret)
		return (NULL);
	ind += 1;
	count = 0;
	while (left_over[ind])
		ret[count++] = left_over[ind++];
	ret[count] = 0;
	free(left_over);
	return (ret);
}

char	*get_untrimed(char *left_over, int fd)
{
	char	*buf;
	int		red;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	red = 1;
	while (get_char_ind_in_str('\n', left_over) == -1 && red != 0)
	{
		red = read(fd, buf, BUFFER_SIZE);
		if (red == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[red] = 0;
		left_over = ft_strjoin_del1(left_over, buf);
	}
	free(buf);
	return (left_over);
}
