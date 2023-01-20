/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_textures.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fstaryk <fstaryk@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:09:59 by fstaryk           #+#    #+#             */
/*   Updated: 2023/01/20 17:42:45 by fstaryk          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minirt.h"
// t_color	*set_color_fstr(t_temp_img *img, int x, int y)
// {
// 	int	*pix_pos;

// 	pix_pos = (int *)(img->img_data
// 			+ (y * img->img_sl + x * (img->img_bp / 8)));
// 	return ((t_color *)pix_pos);
// }

// t_color	***create_color_arr(t_temp_img *img, int height, int width)
// {
// 	t_color    ***color_arr;
// 	int		i;
// 	int		j;

// 	color_arr = calloc(sizeof(t_color **), height + 1);
// 	j = 0;
// 	while (j < height)
// 	{
// 		color_arr[j] = calloc(sizeof(t_color *), width + 1);
// 		i = 0;
// 		while (i < width)
// 		{
// 			color_arr[j][i] = set_color_fstr(img, j, i);
// 			i++;
// 		}
// 		j++;
// 	}
// 	return (color_arr);
// }

// t_texture	*load_textures(void *mlx, char *texture_path)
// {
//     t_texture *ret;
//     void *temp_mlx_im;
//     t_temp_img im;
    
//     ret = malloc(sizeof(t_texture));
//     temp_mlx_im = mlx_xpm_file_to_image(mlx,
//             texture_path,
//             &ret->width,
//             &ret->height);
//     fprintf(stderr, "after file to image\n");
//     im.img_data = mlx_get_data_addr(temp_mlx_im,
//             &im.img_bp,
//             &im.img_sl,
//             &im.img_e);
//     fprintf(stderr, "after get data addr\n");
//     ret->pix_arr = create_color_arr(&im,
//             ret->height,
//             ret->width);
//     return ret;
// }

t_texture* read_xpm_file(void *mlx, char* filename) {
    t_texture *ret;
    t_temp_img im;
    
    ret = malloc(sizeof(t_texture));
	im.img_data = mlx_xpm_file_to_image(mlx, filename, &ret->width, &ret->height);
    ret->texture = (int*)mlx_get_data_addr(im.img_data, &im.img_bp, &im.img_sl, &im.img_e);
    return ret;
}
