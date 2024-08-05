/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:11:07 by almarico          #+#    #+#             */
/*   Updated: 2024/08/05 18:57:01 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

void	draw_octant_zero(int x_distance, int y_distance, int start_x, int start_y, int end_x, t_window *mlx)
{
	int	e;

	e = x_distance;
	x_distance = e * 2;
	y_distance *= 2;
	while (++start_x != end_x)
	{
		set_pixel_color(mlx->img, start_x, start_y, COLOR_OCTANT_0);
		if ((e = e - y_distance) < 0)
		{
			start_y++;
			e = e + x_distance;
		}
	}
}

void	draw_octant_one(int x_distance, int y_distance, int start_x, int start_y, int end_y, t_window *mlx)
{
	int e;

	e = y_distance;
	y_distance = e * 2;
	x_distance *= 2;
	while (++start_y != end_y)
	{
		set_pixel_color(mlx->img, start_x, start_y, COLOR_OCTANT_1);
		if ((e = e - x_distance) < 0)
		{
			start_x++;
			e = e + y_distance;
		}
	}
}

void	draw_octant_two(int x_distance, int y_distance, int start_x, int start_y, int end_y, t_window *mlx)
{
	int	e;

	e = y_distance;
	y_distance = e * 2;
	x_distance *= 2;
	while (++start_y != end_y)
	{
		set_pixel_color(mlx->img, start_x, start_y, COLOR_OCTANT_2);
		if ((e = e + x_distance) <= 0)
		{
			start_x--;
			e = e + y_distance;
		}
	}
}

void	draw_octant_three(int x_distance, int y_distance, int start_x, int start_y, int end_x, t_window *mlx)
{
	int	e;

	e = x_distance;
	x_distance = e * 2;
	y_distance *= 2;
	while (--start_x != end_x)
	{
		set_pixel_color(mlx->img, start_x, start_y, COLOR_OCTANT_3);
		if ((e = e + y_distance) >= 0)
		{
			start_y++;
			e = e + x_distance;
		}
	}
}

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
