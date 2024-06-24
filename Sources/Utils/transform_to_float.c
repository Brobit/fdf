/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_to_float.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:53:00 by almarico          #+#    #+#             */
/*   Updated: 2024/06/20 11:15:22 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

void	print_map(t_map_info *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->line_nb)
	{
		j = 0;
		while (j < map->line_size)
		{
			printf(" %d ", map->map[i][j].value);
			j++;
		}
		printf("\n");
		i++;
	}
}

static void	skip_space(t_map_info *map)
{
	while ((**map->map_info != '\0') && (ft_isspace(**map->map_info) == 0))
		(*map->map_info)++;
}

static void	skip_number(t_map_info *map)
{
	while ((**map->map_info != '\0') && (ft_isspace(**map->map_info) != 0))
		(*map->map_info)++;
}

int	convert_map_to_int(t_map_info *map)
{
	int	column_index;
	int	line_index;

	column_index = 0;
	while (*map->map_info != NULL)
	{
		line_index = 0;
		while (**map->map_info != '\0')
		{
			skip_space(map);
			map->map[column_index][line_index] = (t_map){
				.pos_x = column_index,
				.pos_y = line_index,
				.value = ft_atoi(*map->map_info),
				.color = get_color_value(map)};
			skip_number(map);
			skip_space(map);
			line_index++;
		}
		column_index++;
		map->map_info++;
	}
	print_map(map);
	return (SUCCESS);
}

int	transform_to_int(t_map_info *map)
{
	int	index;

	map->map = malloc((map->line_nb + 1) * sizeof(t_map *));
	if (!map->map)
		return (write_message(ERR_MALLOC), FAIL);
	map->map[map->line_nb] = NULL;
	map->line_size = ft_count_word_with_string(*map->map_info, " \n") - 1;
	index = 0;
	while (index < map->line_nb)
	{
		map->map[index] = malloc(map->line_size * sizeof(t_map));
		if (!map->map[index])
			return (free_map_info(map), free_map(map), FAIL);
		index++;
	}
	if (convert_map_to_int(map) == FAIL)
		return (free_map_info(map), free_map(map), FAIL);
	return (SUCCESS);
}
