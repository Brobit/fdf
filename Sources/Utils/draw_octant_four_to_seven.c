/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_octant_four_to_seven.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:35:24 by almarico          #+#    #+#             */
/*   Updated: 2024/09/02 13:51:33 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

void	draw_octant_four(int x_distance, int y_distance, t_point *pixel, \
					t_window *mlx)
{
	int	e;

	e = x_distance;
	x_distance = e * 2;
	y_distance *= 2;
	while (--pixel->x_start != pixel->x_end)
	{
		set_pixel_color(mlx->img, pixel->x_start, pixel->y_start, \
				COLOR_OCTANT_4);
		e = e - y_distance;
		if (e >= 0)
		{
			pixel->y_start--;
			e = e + x_distance;
		}
	}
}

void	draw_octant_five(int x_distance, int y_distance, t_point *pixel, \
					t_window *mlx)
{
	int	e;

	e = y_distance;
	y_distance = e * 2;
	x_distance *= 2;
	while (--pixel->y_start != pixel->y_end)
	{
		set_pixel_color(mlx->img, pixel->x_start, pixel->y_start, \
				COLOR_OCTANT_5);
		e = e - x_distance;
		if (e >= 0)
		{
			pixel->x_start--;
			e = e + y_distance;
		}
	}
}

void	draw_octant_six(int x_distance, int y_distance, t_point *pixel, \
					t_window *mlx)
{
	int	e;

	e = y_distance;
	y_distance = e * 2;
	while (--pixel->y_start != pixel->y_end)
	{
		set_pixel_color(mlx->img, pixel->x_start, pixel->y_start, \
				COLOR_OCTANT_6);
		e = e + x_distance;
		if (e > 0)
		{
			pixel->x_start++;
			e = e + y_distance;
		}
	}
}

void	draw_octant_seven(int x_distance, int y_distance, t_point *pixel, \
					t_window *mlx)
{
	int	e;

	e = x_distance;
	x_distance *= 2;
	while (++pixel->x_start != pixel->x_end)
	{
		set_pixel_color(mlx->img, pixel->x_start, pixel->y_start, \
				COLOR_OCTANT_7);
		e = e + y_distance;
		if (e < 0)
		{
			pixel->y_start--;
			e = e + x_distance;
		}
	}
}
