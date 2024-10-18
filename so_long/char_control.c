/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 18:34:01 by agenc             #+#    #+#             */
/*   Updated: 2023/06/19 18:34:03 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	char_control(t_map *map, int x, int y)
{
	map->p_count = 0;
	map->e_count = 0;
	map->c_count = 0;
	y = 0;
	while (map->map_line[y])
	{
		x = 0;
		while (map->map_line[y][x])
		{
			if (map->map_line[y][x] == 'E')
				map->e_count++;
			if (map->map_line[y][x] == 'C')
				map->c_count++;
			if (map->map_line[y][x] == 'P')
			{
				map->p_y_loc = y;
				map->p_x_loc = x;
				map->p_count++;
			}
			x++;
		}
		y++;
	}
}

int	char_c(t_map *map)
{
	char_control(map, 0, 0);
	if (map->e_count != 1)
	{
		ft_printf("Error!\nÇıkış sayısı 1 değil!");
		return (1);
	}
	if (map->c_count == 0)
	{
		ft_printf("Error!\nToplanabilir sayısı 0!");
		return (1);
	}
	if (map->p_count != 1)
	{
		ft_printf("Error!\nOyuncu sayısı 1 değil!");
		return (1);
	}
	return (0);
}

int	element_c(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->map_line[y])
	{
		x = 0;
		while (map->map_line[y][x] != '\n' && map->map_line[y][x] != '\0')
		{
			if (ft_strchr(MAP_CHAR, map->map_line[y][x]))
				x++;
			else
			{
				ft_printf("Error!\n%d. satırda '%c' harfi var!", y, \
					map->map_line[y][x]);
				return (1);
			}
		}
		y++;
	}
	return (0);
}
