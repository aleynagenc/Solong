/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:14:58 by agenc             #+#    #+#             */
/*   Updated: 2023/06/19 19:14:59 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	wall_c(t_map *map)
{
	int	y;
	int	value;
	int	value2;

	y = 0;
	value = wall_first_end(map, y);
	if (value != 0)
	{
		ft_printf("Error!\n%d. satırda duvar hatası!", value);
		return (1);
	}
	y = 1;
	value2 = wall_middle(map, y);
	if (value2 != 0)
	{
		ft_printf("Error!\n%d. satırda duvar hatası!", value2);
		return (1);
	}
	return (0);
}

int	wall_first_end(t_map *map, int y)
{
	int	x;
	int	len;

	len = map->map_y_line;
	if (y == 0 || y == (len - 1))
	{
		x = 0;
		while (map->map_line[y][x] != '\n')
		{
			if (map->map_line[0][x] != '1')
				return (1);
			if (map->map_line[len - 1][x] != '1')
				return (len);
			x++;
		}
	}
	return (0);
}

int	wall_middle(t_map *map, int y)
{
	int	line_len;

	line_len = ft_strlen(map->map_line[0]) - 2;
	while (map->map_line[y] != 0)
	{
		if (map->map_line[y][0] != '1'
				|| map->map_line[y][line_len] != '1')
			return (y + 1);
		y++;
	}
	return (0);
}

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
