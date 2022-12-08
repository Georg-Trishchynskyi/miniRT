/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_strarr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinchuk <gpinchuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:50:56 by fstaryk           #+#    #+#             */
/*   Updated: 2022/12/08 14:58:13 by gpinchuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	free_strarr(char **strarr)
{
	int	i;

	i = 0;
	if (!strarr)
		return ;
	while (strarr[i] != NULL)
	{
		free(strarr[i]);
		i++;
	}
	free(strarr[i]);
	free(strarr);
}
