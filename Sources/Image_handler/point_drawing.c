/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_drawing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:26:58 by almarico          #+#    #+#             */
/*   Updated: 2024/08/02 13:23:37 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

void	calculate_isometric_projection(int *old_pos_x, int *old_pos_y, int value, t_inner_interval *value_of)
{
	double	x_isometric_pos;
	double	y_isometric_pos;

	x_isometric_pos = ((cos(BETA) * *old_pos_x) + (-1 * sin(BETA) * value));
	y_isometric_pos = ((sin(ALPHA) * sin(BETA) * value) + (cos(ALPHA) * *old_pos_y) + (sin(ALPHA) * cos(BETA) * value));
	*old_pos_x = (value_of->min_horizontal + value_of->beggining_horizontal + ((int)x_isometric_pos + (*old_pos_x * value_of->step_horizontal)));
	*old_pos_y = (value_of->min_vertical + value_of->beggining_vertical + ((int)y_isometric_pos + (*old_pos_y * value_of->step_vertical)));
	// printf("x : %d , y : %d \npos_x : %d , pos_y : %d \n\n", (int)x_isometric_pos, (int)y_isometric_pos, *old_pos_x, *old_pos_y);
}

void	draw_point(t_window *mlx, t_map_info *map)
{
	t_inner_interval	value_of;
	int					x;
	int					y;

	value_of = set_interval_to_fill(mlx, map);
	y = 0;
	while (y < map->line_nb)
	{
		x = 0;
		while (x < map->line_size)
		{
			calculate_isometric_projection(&map->map[y][x].pos_x, &map->map[y][x].pos_y, map->map[y][x].value, &value_of);
			if (check_coordonate(&map->map[y][x], &value_of) == SUCCESS)
				set_pixel_color(mlx->img, map->map[y][x].pos_x, map->map[y][x].pos_y, map->map[y][x].color);
			x++;
		}
		y++;
	}
	draw_line(mlx, map, &value_of);
}
