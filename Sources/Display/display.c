/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:45:42 by almarico          #+#    #+#             */
/*   Updated: 2024/06/09 10:13:39 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

int	init_display(t_window *mlx)
{
	mlx->width = 1200;
	mlx->height = 720;
	mlx->init_ptr = mlx_init();
	if (!mlx->init_ptr)
		return (FAIL);
	mlx->window = mlx_new_window(mlx->init_ptr, mlx->width, mlx->height, "fdf");
	if (!mlx->window)
		return (FAIL);
	return (SUCCESS);
}

int	display(t_window *mlx)
{
	int	x;
	int	y;

	x = -1;
	image_handler(mlx);
	while (++x < mlx->width)
	{
		y = -1;
		while (++y < mlx->height)
			fill_image_with_pixel(mlx->img, x, y, mlx->img.color);
	}
	mlx_put_image_to_window(mlx->init_ptr, mlx->window, mlx->img.img_ptr, 0, 0);
	event_handler(mlx);
	mlx_loop(mlx->init_ptr);
	return (SUCCESS);
}
