/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_drawing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:26:58 by almarico          #+#    #+#             */
/*   Updated: 2024/08/09 17:42:30 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

// void	calculate_isometric_projection(int *old_pos_x, int *old_pos_y, int value, t_inner_interval *value_of)
// {
// 	double	x_isometric_pos;
// 	double	y_isometric_pos;
//
// 	x_isometric_pos = ((cos(BETA) * *old_pos_x) + (-1 * sin(BETA) * value));
// 	y_isometric_pos = ((sin(ALPHA) * sin(BETA) * value) + (cos(ALPHA) * *old_pos_y) + (sin(ALPHA) * cos(BETA) * value));
// 	*old_pos_x = (value_of->min_horizontal + value_of->beggining_horizontal + ((int)x_isometric_pos + (*old_pos_x * value_of->step_horizontal)));
// 	*old_pos_y = (value_of->min_vertical + value_of->beggining_vertical + ((int)y_isometric_pos + (*old_pos_y * value_of->step_vertical)));
// 	// printf("x : %d , y : %d \npos_x : %d , pos_y : %d \n\n", (int)x_isometric_pos, (int)y_isometric_pos, *old_pos_x, *old_pos_y);
// }
//
void	calculate_isometric_projection(int *old_pos_x, int *old_pos_y, int value, double coef, t_window *mlx)
{
	double	x_isometric_pos;
	double	y_isometric_pos;

	// x_isometric_pos = ((cos(BETA) * *old_pos_x) + (-1 * sin(BETA) * value)) * coef;
	// y_isometric_pos = ((sin(ALPHA) * sin(BETA) * value) + (cos(ALPHA) * *old_pos_y) + (sin(ALPHA) * cos(BETA) * value)) * coef;
	// x_isometric_pos = *old_pos_x;
	// y_isometric_pos = *old_pos_y;
	// *old_pos_x = -(x_isometric_pos - y_isometric_pos) * cos(0.523599) * coef + mlx->center_width;
	// *old_pos_y = (-value + (x_isometric_pos + y_isometric_pos) * sin(0.523599)) * coef + mlx->center_height - (mlx->center_height / 2.0);
	x_isometric_pos = -(*old_pos_x - *old_pos_y) * cos(0.523599) * coef + mlx->center_width;
	y_isometric_pos = (-value + (*old_pos_x + *old_pos_y) * sin(0.523599)) * coef + mlx->center_height - (mlx->center_height / 2.0);
	printf("x : %d\ty : %d\n", *old_pos_x, *old_pos_y);
}

void	draw_point(t_window *mlx, t_map_info *map)
{
	int					x;
	int					y;
	double				coef;

	// coef = 15;
	coef = 100;
	y = 0;
	while (y < map->line_nb)
	{
		x = 0;
		while (x < map->line_size)
		{
			calculate_isometric_projection(&map->map[y][x].pos_x, &map->map[y][x].pos_y, map->map[y][x].value, coef, mlx);
			if (check_coordonate_to_window(&map->map[y][x]) == FAIL)
			{
				refresh_image(&x, &y, &coef, mlx);
				printf("point out of map\n");
			}
			else
				set_pixel_color(mlx->img, map->map[y][x].pos_x, map->map[y][x].pos_y, map->map[y][x].color);
			x++;
			printf("coef : %f\n", coef);
		}
		y++;
	}
	draw_line(mlx, map);
}

// void	draw_point(t_window *mlx, t_map_info *map)
// {
// 	// t_inner_interval	value_of;
// 	int					x;
// 	int					y;
// 	int					coef;
//
// 	// value_of = set_interval_to_fill(mlx, map);
// 	coef = 15;
// 	y = 0;
// 	while (y < map->line_nb)
// 	{
// 		x = 0;
// 		while (x < map->line_size)
// 		{
// 			// calculate_isometric_projection(&map->map[y][x].pos_x, &map->map[y][x].pos_y, map->map[y][x].value, &value_of);
// 			calculate_isometric_projection(&map->map[y][x].pos_x, &map->map[y][x].pos_y, map->map[y][x].value, coef);
// 			if (check_coordonate_to_window(&map->map[y][x]) == FAIL)
// 			{
// 				refresh_image(&x, &y, &coef, mlx);
// 				printf("point out of map\n");
// 			}
// 			else
// 				set_pixel_color(mlx->img, map->map[y][x].pos_x, map->map[y][x].pos_y, map->map[y][x].color);
// 			x++;
// 		}
// 		y++;
// 	}
// 	draw_line(mlx, map);
// }
