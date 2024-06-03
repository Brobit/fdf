/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:18:54 by almarico          #+#    #+#             */
/*   Updated: 2024/06/03 18:13:11 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

void	fill_image_with_pixel(t_img_info *img, int pos_x, int pos_y, int color)
{
	int		offset;
	char	*dst;

	offset = (pos_y * img->size_line + pos_x * (img->bits_per_pixel / 8));
	dst = img->img_data_address + offset;
	*(unsigned int *)dst = color;
}

void	image_handler(t_window *mlx, t_img_info *img)
{
	img->img_ptr = mlx_new_image(mlx->init_ptr, mlx->width, mlx->height);
	img->img_data_address = mlx_get_data_addr(img->img_ptr, &img->bits_per_pixel, &img->size_line, &img->endian);
}
