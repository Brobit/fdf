/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_drawing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:26:58 by almarico          #+#    #+#             */
/*   Updated: 2024/06/24 10:28:00 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

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
			map->map[x][y].pos_x = (value_of.min_horizontal + value_of.beggining_horizontal + (map->map[x][y].pos_x * value_of.step_horizontal));
			map->map[x][y].pos_y = (value_of.min_vertical + value_of.beggining_vertical + (map->map[x][y].pos_y * value_of.step_vertical));
			set_pixel_color(mlx->img, map->map[x][y].pos_x, map->map[x][y].pos_y, map->map[x][y].color);
			x++;
		}
		y++;
	}
}
