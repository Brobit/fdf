/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_other_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:39:14 by almarico          #+#    #+#             */
/*   Updated: 2024/08/06 10:39:59 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

void	draw_vertical(int start_x, int start_y, int end_y, t_window *mlx, char sign, int color)
{
	if (sign == '+')
		while (++start_y != end_y)
			set_pixel_color(mlx->img, start_x, start_y, color);
	else if (sign == '-')
		while (--start_y != end_y)
			set_pixel_color(mlx->img, start_x, start_y, color);
}

void	draw_horizontal(int start_x, int start_y, int end_x, t_window *mlx, char sign, int color)
{
	if (sign == '+')
		while (++start_x != end_x)
			set_pixel_color(mlx->img, start_x, start_y, color);
	else if (sign == '-')
		while (--start_x != end_x)
			set_pixel_color(mlx->img, start_x, start_y, color);
}

void	draw_right_side(int start_x, int start_y, int end_x, int end_y, t_window *mlx)
{
	int	x_distance;
	int	y_distance;

	x_distance = end_x - start_x;
	y_distance = end_y - start_y;
	if (y_distance == 0)
		draw_horizontal(start_x, start_y, end_x, mlx, '+', COLOR_GREY);
	if (y_distance != 0)
	{
		if (y_distance > 0)
		{
			if (x_distance > y_distance)
				draw_octant_zero(x_distance, y_distance, start_x, start_y, end_x, mlx);
			else
				draw_octant_one(x_distance, y_distance, start_x, start_y, end_y, mlx);
		}
		else if (y_distance < 0)
		{
			if (x_distance >= -y_distance)
				draw_octant_seven(x_distance, y_distance, start_x, start_y, end_x, mlx);
			else
				draw_octant_six(x_distance, y_distance, start_x, start_y, end_y, mlx);
		}
	}
}

void	draw_left_side(int start_x, int start_y, int end_x, int end_y, t_window *mlx)
{
	int	x_distance;
	int	y_distance;

	x_distance = end_x - start_x;
	y_distance = end_y - start_y;
	if (y_distance == 0)
		draw_horizontal(start_x, start_y, end_x, mlx, '-', COLOR_GREEN);
	else if (y_distance != 0)
	{
		if (y_distance > 0)
		{
			if (-x_distance > y_distance)
				draw_octant_three(x_distance, y_distance, start_x, start_y, end_x, mlx);
			else
				draw_octant_two(x_distance, y_distance, start_x, start_y, end_y, mlx);
		}
		else if (y_distance < 0)
		{
			if (x_distance < y_distance)
				draw_octant_four(x_distance, y_distance, start_x, start_y, end_x, mlx);
			else
				draw_octant_five(x_distance, y_distance, start_x, start_y, end_y, mlx);
		}
	}
}
