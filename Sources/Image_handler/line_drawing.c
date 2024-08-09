/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 11:11:07 by almarico          #+#    #+#             */
/*   Updated: 2024/08/09 10:19:41 by almarico         ###   ########.fr       */
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

void	draw_bottom_and_right_line(int x, int y, t_map_info *map, t_window *mlx)
{
	if (y == map->line_size -1)
	{
		if (check_coordonate_to_window(&map->map[x - 1][y]) == FAIL
			|| check_coordonate_to_window(&map->map[x][y]) == FAIL)
			printf("point coordonate out of the map to draw the bottom line\n");
		else
			draw_one_line(map->map[x - 1][y].pos_x, map->map[x - 1][y].pos_y, map->map[x][y].pos_x, map->map[x][y].pos_y, mlx);
	}
	if (x == map->line_nb -1)
	{
		y = 0;
		while (y < map->line_size -1)
		{
			if (check_coordonate_to_window(&map->map[x][y]) == FAIL
				|| check_coordonate_to_window(&map->map[x][y + 1]) == FAIL)
				printf("point coordonate out of the map to draw the right line\n");
			else
				draw_one_line(map->map[x][y].pos_x, map->map[x][y].pos_y, map->map[x][y + 1].pos_x, map->map[x][y + 1].pos_y, mlx);
			y++;
		}
	}
}

void	refresh_image(int *x, int *y, double *coef, t_window *mlx)
{
	mlx_destroy_image(mlx->init_ptr, mlx->img.img_ptr);
	image_handler(mlx);
	*x = -1;
	*y = 0;
	*coef /= 2;
	printf("point coodonate out of map to draw line\n");
}

// int	check_coordonate_to_window(t_map *start, t_inner_interval *value_of)
// {
// 	if (!start)
// 	{
// 		printf("coordonate do not exist\n");
// 		return (FAIL);
// 	}
// 	else if (start->pos_x >= value_of->min_horizontal && start->pos_x <= value_of->max_horizontal
// 		&& start->pos_y >= value_of->min_vertical && start->pos_y <= value_of->max_vertical)
// 		return (SUCCESS);
// 	return (FAIL);
// }

int	check_coordonate_to_window(t_map *start)
{
	if (!start)
	{
		printf("coordonate do not exist\n");
		return (FAIL);
	}
	else if (start->pos_x > 0 && start->pos_x < 1280
		&& start->pos_y > 0 && start->pos_y < 720)
		return (SUCCESS);
	// else if (start->pos_x > 0 && start->pos_x < 1900
	// 	&& start->pos_y > 0 && start->pos_y < 1080)
	// 	return (SUCCESS);
	return (FAIL);
}

// void	check_coordonate(int *x, int *y, t_window *mlx, t_map_info *map, t_inner_interval *value_of)
// {
// 	if (check_coordonate_to_window(&map->map[*x][*y]) == FAIL
// 		|| check_coordonate_to_window(&map->map[*x][*y + 1]) == FAIL)
// 		printf("error\n");
// 		// refresh_image(x, y, mlx);
// 	else
// 		draw_one_line(map->map[*x][*y].pos_x, map->map[*x][*y].pos_y, map->map[*x][*y + 1].pos_x, map->map[*x][*y + 1].pos_y, mlx);
// 	if (check_coordonate_to_window(&map->map[*x][*y]) == FAIL
// 		|| check_coordonate_to_window(&map->map[*x + 1][*y]) == FAIL)
// 		printf("error\n");
// 		// refresh_image(x, y, mlx);
// 	else
// 		draw_one_line(map->map[*x][*y].pos_x, map->map[*x][*y].pos_y, map->map[*x + 1][*y].pos_x, map->map[*x + 1][*y].pos_y, mlx);
// }
//
void	check_coordonate(int *x, int *y, t_window *mlx, t_map_info *map)
{
	if (check_coordonate_to_window(&map->map[*x][*y]) == FAIL
		|| check_coordonate_to_window(&map->map[*x][*y + 1]) == FAIL)
		printf("error\n");
		// refresh_image(x, y, mlx);
	else
		draw_one_line(map->map[*x][*y].pos_x, map->map[*x][*y].pos_y, map->map[*x][*y + 1].pos_x, map->map[*x][*y + 1].pos_y, mlx);
	if (check_coordonate_to_window(&map->map[*x][*y]) == FAIL
		|| check_coordonate_to_window(&map->map[*x + 1][*y]) == FAIL)
		printf("error\n");
		// refresh_image(x, y, mlx);
	else
		draw_one_line(map->map[*x][*y].pos_x, map->map[*x][*y].pos_y, map->map[*x + 1][*y].pos_x, map->map[*x + 1][*y].pos_y, mlx);
}

void	draw_line(t_window *mlx, t_map_info *map)
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
			check_coordonate(&x, &y, mlx, map);
			y++;
		}
		x++;
		draw_bottom_and_right_line(x, y, map, mlx);
	}
}
