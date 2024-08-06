/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_octant_four_to_seven.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:35:24 by almarico          #+#    #+#             */
/*   Updated: 2024/08/06 10:38:15 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

void	draw_octant_four(int x_distance, int y_distance, int start_x, int start_y, int end_x, t_window *mlx)
{
	int	e;

	e = x_distance;
	x_distance = e * 2;
	y_distance *= 2;
	while (--start_x != end_x)
	{
		set_pixel_color(mlx->img, start_x, start_y, COLOR_OCTANT_4);
		if ((e = e - y_distance) >= 0)
		{
			start_y--;
			e = e + x_distance;
		}
	}
}

void	draw_octant_five(int x_distance, int y_distance, int start_x, int start_y, int end_y, t_window *mlx)
{
	int	e;

	e = y_distance;
	y_distance = e * 2;
	x_distance *= 2;
	while (--start_y != end_y)
	{
		set_pixel_color(mlx->img, start_x, start_y, COLOR_OCTANT_5);
		if ((e = e - x_distance) >= 0)
		{
			start_x--;
			e = e + y_distance;
		}
	}
}

void	draw_octant_six(int x_distance, int y_distance, int start_x, int start_y, int end_y, t_window *mlx)
{
	int	e;

	e = y_distance;
	y_distance = e * 2;
	while (--start_y != end_y)
	{
		set_pixel_color(mlx->img, start_x, start_y, COLOR_OCTANT_6);
		if ((e = e + x_distance) > 0)
		{
			start_x++;
			e = e + y_distance;
		}
	}
}

void	draw_octant_seven(int x_distance, int y_distance, int start_x, int start_y, int end_x, t_window *mlx)
{
	int	e;

	e = x_distance;
	x_distance *= 2;
	while (++start_x != end_x)
	{
		set_pixel_color(mlx->img, start_x, start_y, COLOR_OCTANT_7);
		if ((e = e + y_distance)  < 0)
		{
			start_y--;
			e = e + x_distance;
		}
	}
}
