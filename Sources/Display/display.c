/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:45:42 by almarico          #+#    #+#             */
/*   Updated: 2024/06/20 11:32:50 by almarico         ###   ########.fr       */
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

int	display(t_window *mlx, t_map_info *map)
{
	image_handler(mlx);
	fill_image_with_pixel(mlx, map);
	mlx_put_image_to_window(mlx->init_ptr, mlx->window, mlx->img.img_ptr, 0, 0);
	event_handler(mlx);
	mlx_loop(mlx->init_ptr);
	return (SUCCESS);
}
