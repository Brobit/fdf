/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_other_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:39:14 by almarico          #+#    #+#             */
/*   Updated: 2024/09/02 12:25:03 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

void	draw_vertical(t_point *pixel, t_window *mlx, char sign, int color)
{
	if (sign == '+')
		while (++pixel->y_start != pixel->y_end)
			set_pixel_color(mlx->img, pixel->x_start, pixel->y_start, color);
	else if (sign == '-')
		while (--pixel->y_start != pixel->y_end)
			set_pixel_color(mlx->img, pixel->x_start, pixel->y_start, color);
}

void	draw_horizontal(t_point *pixel, t_window *mlx, char sign, int color)
{
	if (sign == '+')
		while (++pixel->x_start != pixel->x_end)
			set_pixel_color(mlx->img, pixel->x_start, pixel->y_start, color);
	else if (sign == '-')
		while (--pixel->x_start != pixel->x_end)
			set_pixel_color(mlx->img, pixel->x_start, pixel->y_start, color);
}

void	draw_right_side(t_point *pixel, t_window *mlx)
{
	int	x_distance;
	int	y_distance;

	x_distance = pixel->x_end - pixel->x_start;
	y_distance = pixel->y_end - pixel->y_start;
	if (y_distance == 0)
		draw_horizontal(pixel, mlx, '+', COLOR_GREY);
	if (y_distance != 0)
	{
		if (y_distance > 0)
		{
			if (x_distance > y_distance)
				draw_octant_zero(x_distance, y_distance, pixel, mlx);
			else
				draw_octant_one(x_distance, y_distance, pixel, mlx);
		}
		else if (y_distance < 0)
		{
			if (x_distance >= -y_distance)
				draw_octant_seven(x_distance, y_distance, pixel, mlx);
			else
				draw_octant_six(x_distance, y_distance, pixel, mlx);
		}
	}
}

void	draw_left_side(t_point *pixel, t_window *mlx)
{
	int	x_distance;
	int	y_distance;

	x_distance = pixel->x_end - pixel->x_start;
	y_distance = pixel->y_end - pixel->y_start;
	if (y_distance == 0)
		draw_horizontal(pixel, mlx, '-', COLOR_GREEN);
	else if (y_distance != 0)
	{
		if (y_distance > 0)
		{
			if (-x_distance > y_distance)
				draw_octant_three(x_distance, y_distance, pixel, mlx);
			else
				draw_octant_two(x_distance, y_distance, pixel, mlx);
		}
		else if (y_distance < 0)
		{
			if (x_distance < y_distance)
				draw_octant_four(x_distance, y_distance, pixel, mlx);
			else
				draw_octant_five(x_distance, y_distance, pixel, mlx);
		}
	}
}
