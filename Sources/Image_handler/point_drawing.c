/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_drawing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:26:58 by almarico          #+#    #+#             */
/*   Updated: 2024/09/04 16:54:34 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

void	calculate_isometric_projection(t_point *pixel, double coef,
									t_window *mlx)
{
	double	x_isometric_pos;
	double	y_isometric_pos;
	double	theta;
	double	iso_x;
	double	iso_y;

	theta = -M_PI / 3;
	iso_x = cos((sqrt(2) / 2)) * sin(-theta) * coef;
	iso_y = sin(-(sqrt(2) / 2)) * cos(theta) * coef;
	x_isometric_pos = (pixel->x_start - pixel->y_start) * iso_x \
		+ mlx->center_width;
	y_isometric_pos = (pixel->z_start - (pixel->x_start + pixel->y_start)) \
		* iso_y + mlx->center_height;
	pixel->x_start = x_isometric_pos;
	pixel->y_start = y_isometric_pos;
	x_isometric_pos = (pixel->x_end - pixel->y_end) * iso_x + mlx->center_width;
	y_isometric_pos = (pixel->z_end - (pixel->x_end + pixel->y_end)) \
		* iso_y + mlx->center_height;
	pixel->x_end = x_isometric_pos;
	pixel->y_end = y_isometric_pos;
}

int	draw_x_line(t_map_info *map, t_window *mlx, int *x, int *y)
{
	t_point				pixel;

	pixel = (t_point){
		.x_start = map->map[*y][*x].pos_x,
		.y_start = map->map[*y][*x].pos_y,
		.z_start = map->map[*y][*x].value,
		.x_end = map->map[*y][*x + 1].pos_x,
		.y_end = map->map[*y][*x + 1].pos_y,
		.z_end = map->map[*y][*x + 1].value};
	calculate_isometric_projection(&pixel, map->coef, mlx);
	if (check_coordonate_to_window(pixel, mlx) == FAIL)
		return (FAIL);
	else
		draw_one_line(&pixel, mlx);
	return (SUCCESS);
}

int	draw_y_line(t_map_info *map, t_window *mlx, int *x, int *y)
{
	t_point				pixel;

	pixel = (t_point){
		.x_start = map->map[*y][*x].pos_x,
		.y_start = map->map[*y][*x].pos_y,
		.z_start = map->map[*y][*x].value,
		.x_end = map->map[*y + 1][*x].pos_x,
		.y_end = map->map[*y + 1][*x].pos_y,
		.z_end = map->map[*y + 1][*x].value};
	calculate_isometric_projection(&pixel, map->coef, mlx);
	if (check_coordonate_to_window(pixel, mlx) == FAIL)
		return (FAIL);
	else
		draw_one_line(&pixel, mlx);
	return (SUCCESS);
}

int	draw_bottom_and_right_line(t_window *mlx, t_map_info *map)
{
	int					x;
	int					y;

	y = map->line_nb - 1;
	x = 0;
	while (x < map->line_size - 1 && (x + 1) <= map->line_size - 1)
	{
		if (draw_x_line(map, mlx, &x, &y) == FAIL)
			return (FAIL);
		x++;
	}
	x = map->line_size - 1;
	y = 0;
	while (y < map->line_nb - 1 && (y + 1) <= map->line_nb - 1)
	{
		if (draw_y_line(map, mlx, &x, &y) == FAIL)
			return (FAIL);
		y++;
	}
	return (SUCCESS);
}

void	draw_point(t_window *mlx, t_map_info *map)
{
	int					x;
	int					y;

	y = 0;
	while (y < map->line_nb - 1)
	{
		x = 0;
		while (x < map->line_size - 1)
		{
			if (x + 1 <= map->line_size - 1)
				if (draw_x_line(map, mlx, &x, &y) == FAIL)
					refresh_image(&x, &y, &map->coef, mlx);
			if (y + 1 <= map->line_nb - 1 && x >= 0)
				if (draw_y_line(map, mlx, &x, &y) == FAIL)
					refresh_image(&x, &y, &map->coef, mlx);
			x++;
		}
		y++;
	}
	if (draw_bottom_and_right_line(mlx, map) == FAIL)
		refresh_image(&x, &y, &map->coef, mlx);
}
