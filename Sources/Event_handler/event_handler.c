/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:19:34 by almarico          #+#    #+#             */
/*   Updated: 2024/06/02 13:55:56 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

void	event_handler(t_window *mlx)
{
	mlx_hook(mlx->window, ON_KEYDOWN, 1L << 0, key_handler, mlx);
	mlx_hook(mlx->window, ON_DESTROY, 1L << 17, closes, mlx);
}
