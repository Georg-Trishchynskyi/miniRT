/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:09:59 by fstaryk           #+#    #+#             */
/*   Updated: 2023/01/26 17:27:02 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"

t_texture	*read_xpm_file(void *mlx, char	*filename)
{
	t_texture	*ret;
	t_temp_img	im;

	ret = calloc(1, sizeof(t_texture));
	im.img_data = mlx_xpm_file_to_image(mlx, \
		filename, &ret->width, &ret->height);
	ret->pix_arr = (int *)mlx_get_data_addr(im.img_data, \
		&im.img_bp, &im.img_sl, &im.img_e);
	// mlx_destroy_image(mlx, im.img_data);
	return (ret);
}
