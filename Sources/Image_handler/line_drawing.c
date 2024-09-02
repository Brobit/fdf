/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:11:07 by almarico          #+#    #+#             */
/*   Updated: 2024/09/02 12:09:38 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

void	draw_one_line(t_point *pixel, t_window *mlx)
{
	int	x_distance;
	int	y_distance;

	x_distance = pixel->x_end - pixel->x_start;
	y_distance = pixel->y_end - pixel->y_start;
	if (x_distance == 0)
	{
		if (y_distance > 0)
			draw_vertical(pixel, mlx, '+', COLOR_GREY);
		else if (y_distance < 0)
			draw_vertical(pixel, mlx, '-', COLOR_GREEN);
	}
	else if (x_distance != 0)
	{
		if (x_distance > 0)
			draw_right_side(pixel, mlx);
		else if (x_distance < 0)
			draw_left_side(pixel, mlx);
	}
}

void	refresh_image(int *x, int *y, double *coef, t_window *mlx)
{
	mlx_destroy_image(mlx->init_ptr, mlx->img.img_ptr);
	image_handler(mlx);
	*x = -1;
	*y = 0;
	*coef *= 0.95;
}

int	check_coordonate_to_window(t_point pixel, t_window *mlx)
{
	if (pixel.x_start > 0 && pixel.x_start < mlx->width
		&& pixel.y_start > 0 && pixel.y_start < mlx->height
		&& pixel.x_end > 0 && pixel.x_start < mlx->width
		&& pixel.y_end > 0 && pixel.y_end < mlx->height)
		return (SUCCESS);
	return (FAIL);
}
