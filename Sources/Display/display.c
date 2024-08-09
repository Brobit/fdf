/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:45:42 by almarico          #+#    #+#             */
/*   Updated: 2024/08/09 10:20:34 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

int	init_display(t_window *mlx)
{
	mlx->width = 1280;
	mlx->height = 720;
	// mlx->width = 1900;
	// mlx->height = 1080;
	mlx->center_width = mlx->width / 2 - 1;
	mlx->center_height = mlx->height / 2 - 1;
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
