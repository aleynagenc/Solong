/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:13:52 by agenc             #+#    #+#             */
/*   Updated: 2023/06/19 19:13:54 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_c(t_map *map)
{
	recursive_p(map, map->p_y_loc, map->p_x_loc);
	if (coin_c(map) || exit_c(map))
		return (1);
	return (0);
}

void	recursive_p(t_map *map, int y, int x)
{
	if (map->map_line[y][x + 1] == '0' || map->map_line[y][x + 1] == 'C')
	{
		map->map_line[y][x + 1] = 'P';
		recursive_p(map, y, x + 1);
	}
	if (map->map_line[y][x - 1] == '0' || map->map_line[y][x - 1] == 'C')
	{
		map->map_line[y][x - 1] = 'P';
		recursive_p(map, y, x - 1);
	}
	if (map->map_line[y + 1][x] == '0' || map->map_line[y + 1][x] == 'C')
	{
		map->map_line[y + 1][x] = 'P';
		recursive_p(map, y + 1, x);
	}
	if (map->map_line[y - 1][x] == '0' || map->map_line[y - 1][x] == 'C')
	{
		map->map_line[y - 1][x] = 'P';
		recursive_p(map, y - 1, x);
	}
}

int	coin_c(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->map_line[y])
	{
		x = 0;
		while (map->map_line[y][x] != 0 && map->map_line[y][x] != '\n')
		{
			if (map->map_line[y][x] == 'C')
			{
				ft_printf("Error!\nOyuncu toplanabilir eşyaya ulaşamıyor!");
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	exit_c(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	while (map->map_line[y] != 0)
	{
		x = 0;
		while (map->map_line[y][x] != '\n')
		{
			if (map->map_line[y][x] == 'E')
				break ;
			x++;
		}
		if (map->map_line[y][x] == 'E')
			break ;
		y++;
	}
	if (map->map_line[y][x + 1] == 'P' || map->map_line[y][x - 1] == 'P' || \
			map->map_line[y + 1][x] == 'P' || map->map_line[y - 1][x] == 'P')
		return (0);
	ft_printf("Error!\nOyuncu çıkışa ulaşamıyor!");
	return (1);
}
