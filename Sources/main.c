/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 18:33:09 by almarico          #+#    #+#             */
/*   Updated: 2024/06/14 12:50:13 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	main(int argc, char **argv)
{
	t_window	mlx;
	t_map_info	map;

	if (argc != 2)
		return (write_message(ERR_ARGC), FAIL);
	if (file_checker(argv[1]) == FAIL)
		return (write_message(ERR_FILE_FORMAT), FAIL);
	if (file_opener(argv[1], &map) == FAIL)
		return (write_message(ERR_FILE_OPENING), FAIL);
	if (transform_to_float(&map) == FAIL)
		return (write_message(ERR_TRANSFORM_TO_FLOAT), FAIL);
	if (init_display(&mlx) == FAIL)
		return (write_message(ERR_STRUC_OR_DISPLAY_FAIL), FAIL);
	display(&mlx);
	return (SUCCESS);
}
