/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 09:45:42 by almarico          #+#    #+#             */
/*   Updated: 2024/06/03 13:46:37 by almarico         ###   ########.fr       */
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

int	display(t_window *mlx, t_img_info *img)
{
	image_handler(mlx, img);
	mlx_put_image_to_window(mlx->init_ptr, mlx->window, img->img_ptr, 0, 0);
	event_handler(mlx, img);
	mlx_loop(mlx->init_ptr);
	return (SUCCESS);
}
