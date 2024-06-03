/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:12:03 by almarico          #+#    #+#             */
/*   Updated: 2024/06/03 19:04:43 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

int	closes(t_window *mlx)
{
	mlx_destroy_window(mlx->init_ptr, mlx->window);
	exit(0);
	return (0);
}

int	key_handler(int keycode, t_window *mlx, t_img_info *img)
{
	printf("%d\n", keycode);
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(mlx->init_ptr, mlx->window);
		exit(0);
	}
	else if (keycode == XK_r)
	{
		img->color = (img->color == 0x00FF0000) ? 0x0000FF00 : 0x00FF0000;
		image_handler(mlx, img);
		for (int i = 0; i < mlx->width; i++)
			for (int j = 0; j < (mlx->height / 2); j++)
				fill_image_with_pixel(img, i, j, img->color);
		mlx_put_image_to_window(mlx->init_ptr, mlx->window, img->img_ptr, 0, 0);
	}
	return (0);
}
