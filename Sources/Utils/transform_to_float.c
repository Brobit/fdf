/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_to_float.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 12:53:00 by almarico          #+#    #+#             */
/*   Updated: 2024/09/03 16:36:36 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

static void	skip_space(t_map_info *map, int column_index, int *i)
{
	while ((map->map_info[column_index][*i] != '\0')
		&& (ft_isspace(map->map_info[column_index][*i]) == 0))
		(*i)++;
}

static void	skip_number(t_map_info *map, int column_index, int *i)
{
	while ((map->map_info[column_index][*i] != '\0')
		&& (ft_isspace(map->map_info[column_index][*i]) != 0))
		(*i)++;
}

int	convert_map_to_int(t_map_info *map)
{
	t_convert_map_tools		p;

	p.column_index = 0;
	while (map->map_info[p.column_index] != NULL)
	{
		p.i = 0;
		p.line_index = map->line_size - 1;
		while (p.line_index >= 0)
		{
			skip_space(map, p.column_index, &p.i);
			p.tmp = ft_substr(map->map_info[p.column_index], p.i,
					ft_strlen(map->map_info[p.column_index]));
			map->map[p.column_index][p.line_index] = (t_map){
				.pos_x = p.column_index,
				.pos_y = p.line_index,
				.value = ft_atoi(p.tmp)};
			free(p.tmp);
			skip_number(map, p.column_index, &p.i);
			skip_space(map, p.column_index, &p.i);
			p.line_index--;
		}
		p.column_index++;
	}
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
			return (FAIL);
		index++;
	}
	if (convert_map_to_int(map) == FAIL)
		return (FAIL);
	return (SUCCESS);
}
