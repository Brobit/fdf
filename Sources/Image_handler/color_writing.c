/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_writing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:18:11 by almarico          #+#    #+#             */
/*   Updated: 2024/09/02 11:12:19 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

void	set_pixel_color(t_img_info img, int pos_x, int pos_y, int color)
{
	int		offset;
	char	*dst;

	offset = (pos_y * img.size_line + pos_x * (img.bits_per_pixel / 8));
	dst = img.img_data_address + offset;
	*(unsigned int *)dst = color;
}

void	fill_border_of_image(t_window *mlx)
{
	int	x;
	int	y;
	int	color;

	x = -1;
	color = COLOR;
	while (++x <= mlx->width)
	{
		y = -1;
		while (++y <= mlx->height)
			if ((x <= mlx->width * 0.05) || (y <= mlx->height * 0.05)
				|| (x >= mlx->width * 0.95) || (y >= mlx->height * 0.95))
				set_pixel_color(mlx->img, x, y, color);
	}
}
