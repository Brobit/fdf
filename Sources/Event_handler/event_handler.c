/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:19:34 by almarico          #+#    #+#             */
/*   Updated: 2024/06/03 13:39:23 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

void	event_handler(t_window *mlx, t_img_info *img)
{
	mlx_hook(mlx->window, ON_KEYDOWN, 1L << 0, key_handler, mlx);
	mlx_hook(mlx->window, ON_DESTROY, 1L << 17, closes, mlx);
	(void)img;
}
