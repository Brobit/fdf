/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: almarico <almarico@student.42lehavre.fr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 10:54:12 by almarico          #+#    #+#             */
/*   Updated: 2024/06/11 11:01:19 by almarico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

// int	ft_strlen(const char *str)
// {
// 	int	i;
//
// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }
//
int	file_checker(char *str)
{
	int	i;

	i = ft_strlen(str);
	if (i < 5)
		return (FAIL);
	if ((str[i - 4] == '.') && (str[i - 3] == 'f') && (str[i - 2] == 'd') && (str[i - 1] == 'f'))
		return (SUCCESS);
	else
		return (FAIL);
	return (SUCCESS);
}

void	write_message(const char *msg)
{
	write(STDERR, msg, ft_strlen(msg));
}
