/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:11:07 by almarico          #+#    #+#             */
/*   Updated: 2024/08/06 10:42:56 by almarico         ###   ########.fr       */
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

int	check_coordonate(t_map *start, t_inner_interval *value_of)
{
	if (!start)
		return (FAIL);
	else if (start->pos_x >= value_of->min_horizontal && start->pos_x <= value_of->max_horizontal
		&& start->pos_y >= value_of->min_vertical && start->pos_y <= value_of->max_vertical)
		return (SUCCESS);
	return (FAIL);
}

void	draw_bottom_and_right_line(int x, int y, t_map_info *map, t_inner_interval *value_of, t_window *mlx)
{
	if (y == map->line_size -1
		&& check_coordonate(&map->map[x - 1][y], value_of) == SUCCESS
		&& check_coordonate(&map->map[x][y], value_of) == SUCCESS)
		draw_one_line(map->map[x - 1][y].pos_x, map->map[x - 1][y].pos_y, map->map[x][y].pos_x, map->map[x][y].pos_y, mlx);
	if (x == map->line_nb -1)
	{
		y = 0;
		while (y < map->line_size -1)
		{
			if (check_coordonate(&map->map[x][y], value_of) == SUCCESS
				&& check_coordonate(&map->map[x][y + 1], value_of) == SUCCESS)
				draw_one_line(map->map[x][y].pos_x, map->map[x][y].pos_y, map->map[x][y + 1].pos_x, map->map[x][y + 1].pos_y, mlx);
			y++;
		}
	}
}

void	draw_line(t_window *mlx, t_map_info *map, t_inner_interval *value_of)
{
	int			x;
	int			y;

	x = 0;
	y = 0;
	while (x < map->line_nb -1)
	{
		y = 0;
		while (y < map->line_size -1)
		{
			if (check_coordonate(&map->map[x][y], value_of) == SUCCESS
				&& check_coordonate(&map->map[x][y + 1], value_of) == SUCCESS)
				draw_one_line(map->map[x][y].pos_x, map->map[x][y].pos_y, map->map[x][y + 1].pos_x, map->map[x][y + 1].pos_y, mlx);
			if (check_coordonate(&map->map[x][y], value_of) == SUCCESS
				&& check_coordonate(&map->map[x + 1][y], value_of) == SUCCESS)
				draw_one_line(map->map[x][y].pos_x, map->map[x][y].pos_y, map->map[x + 1][y].pos_x, map->map[x + 1][y].pos_y, mlx);
			y++;
		}
		x++;
		draw_bottom_and_right_line(x, y, map, value_of, mlx);
	}
}
