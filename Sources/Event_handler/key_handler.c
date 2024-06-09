/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:12:03 by almarico          #+#    #+#             */
/*   Updated: 2024/06/09 10:15:53 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

int	closes(t_window *mlx)
{
	mlx_destroy_window(mlx->init_ptr, mlx->window);
	exit(0);
	return (0);
}

int	key_handler(int keycode, t_window *mlx)
{
	int	x;
	int	y;

	x = -1;
	printf("%d\n", keycode);
	if (keycode == XK_Escape)
	{
		mlx_destroy_window(mlx->init_ptr, mlx->window);
		exit(0);
	}
	else if (keycode == XK_r)
	{
		mlx->img.color = (mlx->img.color == 0x00FF0000) ? 0x0000FF00 : 0x00FF0000;
		image_handler(mlx);
		while (++x < mlx->width)
		{
			y = -1;
			while (++y < mlx->height)
				fill_image_with_pixel(mlx->img, x, y, mlx->img.color);
		}
		mlx_put_image_to_window(mlx->init_ptr, mlx->window, mlx->img.img_ptr, 0, 0);
	}
	return (0);
}
