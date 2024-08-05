/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 11:18:54 by almarico          #+#    #+#             */
/*   Updated: 2024/08/02 10:55:30 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

void	fill_image_with_pixel(t_window *mlx, t_map_info *map)
{
	fill_border_of_image(mlx);
	draw_point(mlx, map);
}

void	image_handler(t_window *mlx)
{
	mlx->img.img_ptr = mlx_new_image(mlx->init_ptr, mlx->width, mlx->height);
	mlx->img.img_data_address = mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bits_per_pixel, &mlx->img.size_line, &mlx->img.endian);
}
