/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_drawing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:26:58 by almarico          #+#    #+#             */
/*   Updated: 2024/08/26 10:44:20 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

void	calculate_isometric_projection(t_point *pixel, double coef, t_window *mlx)
{
	double	x_isometric_pos;
	double	y_isometric_pos;
	double	x_rotated;
	double	y_rotated;
	double	theta;


	// Assuming 'theta' is the angle by which you want to rotate around the y-axis
	theta = 0.25; /* rotation angle in radians */
	x_rotated = pixel->x_start * cos(theta) + pixel->y_start * sin(theta);
	y_rotated = -pixel->x_start * sin(theta) + pixel->y_start * cos(theta);

	// Now apply the isometric transformation with the rotated coordinates
	x_isometric_pos = (x_rotated - pixel->y_start) * cos(theta) * coef + mlx->center_width;
	y_isometric_pos = ((pixel->z_start + (x_rotated + y_rotated)) * sin(theta)) * coef + mlx->center_height;


	// x_isometric_pos = -(pixel->x_start - pixel->y_start) * cos(0.523599) * coef + mlx->center_width;
	// y_isometric_pos = (-pixel->z_start + (pixel->x_start + pixel->y_start) * sin(0.523599)) * coef + mlx->center_height - (mlx->center_height / 2.0);
	//
	// x_isometric_pos = (pixel->x_start - pixel->y_start) * cos((sqrt(2) / 2)) * coef + mlx->center_width;
	// y_isometric_pos = (-pixel->z_start + (pixel->x_start + pixel->y_start) * sin(-(sqrt(2) / 2))) * coef + mlx->center_height + (mlx->center_height / 2.0);
	//
	// x_isometric_pos = (pixel->x_start - pixel->y_start) * cos(6) * coef + mlx->center_width;
	// y_isometric_pos = ((pixel->z_start + (pixel->x_start + pixel->y_start)) * sin(6)) * coef + mlx->center_height/*  + (mlx->center_height / 2.0) */;
	pixel->x_start = x_isometric_pos;
	pixel->y_start = y_isometric_pos;
	// x_isometric_pos = -(pixel->x_end - pixel->y_end) * cos(0.523599) * coef + mlx->center_width;
	// y_isometric_pos = (-pixel->z_end + (pixel->x_end + pixel->y_end) * sin(0.523599)) * coef + mlx->center_height - (mlx->center_height / 2.0);
	//
	// x_isometric_pos = (pixel->x_end - pixel->y_end) * cos((sqrt(2) / 2)) * coef + mlx->center_width;
	// y_isometric_pos = (-pixel->z_end + (pixel->x_end + pixel->y_end) * sin(-(sqrt(2) / 2))) * coef + mlx->center_height + (mlx->center_height / 2.0);
	//
	// x_isometric_pos = (pixel->x_end - pixel->y_end) * cos(-6) * coef + mlx->center_width;
	// y_isometric_pos = ((pixel->z_end + (pixel->x_end + pixel->y_end)) * sin(6)) * coef + mlx->center_height/*  + (mlx->center_height / 2.0) */;

	x_rotated = pixel->x_end * cos(theta) + pixel->y_end * sin(theta);
	y_rotated = -pixel->x_end * sin(theta) + pixel->y_end * cos(theta);

	// Now apply the isometric transformation with the rotated coordinates
	x_isometric_pos = (x_rotated - pixel->y_end) * cos(theta) * coef + mlx->center_width;
	y_isometric_pos = ((pixel->z_end + (x_rotated + y_rotated)) * sin(theta)) * coef + mlx->center_height;
	pixel->x_end = x_isometric_pos;
	pixel->y_end = y_isometric_pos;
	printf("x_start : %d\ty_start : %d\tx_end : %d\ty_end : %d\n", pixel->x_start, pixel->y_start, pixel->x_end, pixel->y_end);
}

void	draw_bottom_and_right_line(t_window *mlx, t_map_info *map, double coef)
{
	int					x;
	int					y;
	t_point				pixel;

	pixel = (t_point){.x_start = 0, .y_start = 0, .z_start = 0, .x_end = 0, .y_end = 0, .z_end = 0};
	y = map->line_nb - 1;
	x = 0;
	while (x < map->line_size - 1 && (x + 1) < map->line_size - 1)
	{
		pixel = (t_point){.x_start = map->map[y][x].pos_x, .y_start = map->map[y][x].pos_y, .z_start = map->map[y][x].value, .x_end = map->map[y][x + 1].pos_x, .y_end = map->map[y][x + 1].pos_y, .z_end = map->map[y][x + 1].value};
		calculate_isometric_projection(&pixel, coef, mlx);
		if (check_coordonate_to_window(pixel, mlx) == FAIL)
		{
			refresh_image(&x, &y, &coef, mlx);
			printf("point out of map\n");
		}
		else
		{
			// set_pixel_color(mlx->img, pixel.x_start, pixel.y_start, map->map[y][x].color);
			// set_pixel_color(mlx->img, pixel.x_end, pixel.y_end, map->map[y][x + 1].color);
			draw_one_line(pixel.x_start, pixel.y_start, pixel.x_end, pixel.y_end, mlx);
		}
		x++;
		// printf("coef : %f\n", coef);
	}
	x = map->line_size - 1;
	y = 0;
	while (y < map->line_nb - 1 && (y + 1) < map->line_nb - 1)
	{
		pixel = (t_point){.x_start = map->map[y][x].pos_x, .y_start = map->map[y][x].pos_y, .z_start = map->map[y][x].value, .x_end = map->map[y + 1][x].pos_x, .y_end = map->map[y + 1][x].pos_y, .z_end = map->map[y + 1][x].value};
		calculate_isometric_projection(&pixel, coef, mlx);
		if (check_coordonate_to_window(pixel, mlx) == FAIL)
		{
			refresh_image(&x, &y, &coef, mlx);
			printf("point out of map\n");
		}
		else
		{
			// set_pixel_color(mlx->img, pixel.x_start, pixel.y_start, map->map[y][x].color);
			// set_pixel_color(mlx->img, pixel.x_end, pixel.y_end, map->map[y][x + 1].color);
			draw_one_line(pixel.x_start, pixel.y_start, pixel.x_end, pixel.y_end, mlx);
		}
		y++;
		// printf("coef : %f\n", coef);
	}
}

void	draw_point(t_window *mlx, t_map_info *map)
{
	int					x;
	int					y;
	double				coef;
	t_point				pixel;

	coef = 100;
	y = 0;
	pixel = (t_point){.x_start = 0, .y_start = 0, .z_start = 0, .x_end = 0, .y_end = 0, .z_end = 0};
	while (y < map->line_nb - 1)
	{
		x = 0;
		while (x < map->line_size - 1)
		{
			if (x + 1 < map->line_size - 1)
			{
				pixel = (t_point){.x_start = map->map[y][x].pos_x, .y_start = map->map[y][x].pos_y, .z_start = map->map[y][x].value, .x_end = map->map[y][x + 1].pos_x, .y_end = map->map[y][x + 1].pos_y, .z_end = map->map[y][x + 1].value};
				calculate_isometric_projection(&pixel, coef, mlx);
				if (check_coordonate_to_window(pixel, mlx) == FAIL)
				{
					refresh_image(&x, &y, &coef, mlx);
					printf("point out of map\n");
				}
				else
				{
					// set_pixel_color(mlx->img, pixel.x_start, pixel.y_start, map->map[y][x].color);
					// set_pixel_color(mlx->img, pixel.x_end, pixel.y_end, map->map[y][x + 1].color);
					draw_one_line(pixel.x_start, pixel.y_start, pixel.x_end, pixel.y_end, mlx);
				}
			}
			if (y + 1 < map->line_nb - 1)
			{
				pixel = (t_point){.x_start = map->map[y][x].pos_x, .y_start = map->map[y][x].pos_y, .z_start = map->map[y][x].value, .x_end = map->map[y + 1][x].pos_x, .y_end = map->map[y + 1][x].pos_y, .z_end = map->map[y + 1][x].value};
				calculate_isometric_projection(&pixel, coef, mlx);
				if (check_coordonate_to_window(pixel, mlx) == FAIL)
				{
					refresh_image(&x, &y, &coef, mlx);
					printf("point out of map\n");
				}
				else
				{
					// set_pixel_color(mlx->img, pixel.x_start, pixel.y_start, map->map[y][x].color);
					// set_pixel_color(mlx->img, pixel.x_end, pixel.y_end, map->map[y][x + 1].color);
					draw_one_line(pixel.x_start, pixel.y_start, pixel.x_end, pixel.y_end, mlx);
				}
			}
			x++;
			// printf("coef : %f\n", coef);
		}
		y++;
	}
	// draw_bottom_and_right_line(mlx, map, coef);
}
