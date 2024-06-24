/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_writing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:18:11 by almarico          #+#    #+#             */
/*   Updated: 2024/06/24 10:28:03 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

void	set_pixel_color(t_img_info img, int pos_x, int pos_y, int color)
{
	int		offset;
	char	*dst;

	offset = (pos_y * img.size_line + pos_x * (img.bits_per_pixel / 8));
	dst = img.img_data_address + offset;
	*(unsigned int *)dst = color;
}

void	fill_border_of_image(t_window *mlx)
{
	int	x;
	int	y;
	int	color;

	x = -1;
	color = COLOR;
	while (++x <= mlx->width)
	{
		y = -1;
		while (++y <= mlx->height)
			if ((x <= mlx->width * 0.05) || (y <= mlx->height * 0.05) || (x >= mlx->width * 0.95) || (y >= mlx->height * 0.95))
				set_pixel_color(mlx->img, x, y, color);
	}
}

t_inner_interval	set_interval_to_fill(t_window *mlx, t_map_info *map)
{
	t_inner_interval	value_of;

	value_of = (t_inner_interval){
		.min_horizontal = mlx->width * 0.05,
		.max_horizontal = mlx->width * 0.95,
		.min_vertical = mlx->height * 0.05,
		.max_vertical = mlx->height * 0.95,
		.horizontal_interval = (mlx->width * 0.95) - (mlx->width * 0.05),
		.vertical_interval = (mlx->height * 0.95) - (mlx->height * 0.05),
		.step_horizontal = ((mlx->width * 0.95) - (mlx->width * 0.05)) / map->line_size,
		.step_vertical = ((mlx->height * 0.95) - (mlx->height * 0.05)) / map->line_nb,
		.offset_horizontal = (((mlx->width * 0.95) - (mlx->width * 0.05)) / map->line_size) * 0.5,
		.offset_vertical = (((mlx->height * 0.95) - (mlx->height * 0.05)) / map->line_nb) * 0.5,
		.beggining_horizontal = (((mlx->width * 0.95) - (mlx->width * 0.05)) / map->line_size) * 0.5,
		.beggining_vertical = (((mlx->height * 0.95) - (mlx->height * 0.05)) / map->line_nb) * 0.5,
	};
	return (value_of);
}
