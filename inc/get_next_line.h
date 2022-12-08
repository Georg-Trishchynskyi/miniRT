/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 15:43:12 by fstaryk           #+#    #+#             */
/*   Updated: 2022/12/08 13:14:37 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

# define BUFFER_SIZE 1000

typedef struct s_save_read_data
{
	int		last_read;
	char	*left_over;
}			t_save_read_data;

//Main
char		*get_next_line(int fd);

//Utils
char		*get_untrimed(char *left_over, int fd);
char		*get_left_over(char *left_over);
char		*trim_ret_str(char *left_over);
int			get_char_ind_in_str(char c, char *str);
char		*ft_strjoin_del1(char *left_over, char *buff);
size_t		ft_strlen(const char *str);

#endif