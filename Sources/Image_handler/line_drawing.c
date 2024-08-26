/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:11:07 by almarico          #+#    #+#             */
/*   Updated: 2024/08/22 12:49:32 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

void	draw_one_line(int start_x, int start_y, int end_x, int end_y, t_window *mlx)
{
	int	x_distance;
	int	y_distance;

	x_distance = end_x - start_x;
	y_distance = end_y - start_y;
	if (x_distance == 0)
	{
		if (y_distance > 0)
			draw_vertical(start_x, start_y, end_y, mlx, '+', COLOR_GREY);
		else if (y_distance < 0)
			draw_vertical(start_x, start_y, end_y, mlx, '-', COLOR_GREEN);
	}
	else if (x_distance != 0)
	{
		if (x_distance > 0)
			draw_right_side(start_x, start_y, end_x, end_y, mlx);
		else if (x_distance < 0)
			draw_left_side(start_x, start_y, end_x, end_y, mlx);
	}
}

void	refresh_image(int *x, int *y, double *coef, t_window *mlx)
{
	mlx_destroy_image(mlx->init_ptr, mlx->img.img_ptr);
	image_handler(mlx);
	*x = -1;
	*y = 0;
	// *coef *= 0.95;
	*coef /= 2;
	printf("point coodonate out of map to draw line\n");
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
