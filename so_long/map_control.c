/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 14:23:52 by agenc             #+#    #+#             */
/*   Updated: 2023/06/21 14:23:54 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	rectangle_c(t_map *map)
{
	int	y;
	int	x;
	int	len;

	len = ft_strlen(map->map_line[0]);
	y = 0;
	while (y < map->map_y_line)
	{
		x = 0;
		while (map->map_line[y] && map->map_line[y][x] != '\n' && \
			x < (int)(ft_strlen(map->map_line[y])))
			x++;
		if (x != len -1)
		{
			ft_printf("Error!\n%d. satırda dikdörtgen hatası!", y + 1);
			return (1);
		}
		y++;
	}
	return (0);
}
