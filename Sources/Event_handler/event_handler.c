/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:19:34 by almarico          #+#    #+#             */
/*   Updated: 2024/09/03 11:24:18 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

void	event_handler(t_window *mlx, t_map_info *map)
{
	t_pointer	*pointer;

	pointer = malloc(sizeof(t_pointer));
	if (!pointer)
		return (write_message(ERR_MALLOC));
	pointer->mlx = mlx;
	pointer->map = map;
	mlx_hook(mlx->window, ON_KEYDOWN, 1L << 0, key_handler, pointer);
	mlx_hook(mlx->window, ON_DESTROY, 1L << 17, closes, pointer);
	mlx_expose_hook(mlx->window, window_handler, mlx);
}
