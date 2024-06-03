/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:33:09 by almarico          #+#    #+#             */
/*   Updated: 2024/06/03 18:21:08 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	main(int argc, char **argv)
{
	t_window	mlx;
	t_img_info	img;

	(void)argc;
	(void)argv;
	img.color = 0x00FF0000;
	if (init_display(&mlx) == FAIL)
		return (FAIL);
	display(&mlx, &img);
	return (SUCCESS);
}
