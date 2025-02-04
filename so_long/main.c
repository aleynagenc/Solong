/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agenc <agenc@student.42istanbul.com.tr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 19:09:30 by agenc             #+#    #+#             */
/*   Updated: 2023/06/19 19:09:32 by agenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	file_control(int argc, char *argv)
{
	char	*a;

	a = argv;
	if (argc != 2)
	{
		ft_printf("Error!\ngeçersiz argüman sayısı!");
		return (1);
	}
	if (argv[ft_strlen(argv) - 1] != 'r' && argv[ft_strlen(argv) - 2] != 'e' && \
			argv[ft_strlen(a) - 3] != 'b' && argv[ft_strlen(a) - 4] != '.')
	{
		ft_printf("Error!\ndosya uzantısı hatası!");
		return (1);
	}
	return (0);
}

int	map_read_control(t_map *map, char *f_name)
{
	map_read_c(map, f_name);
	if (!(map->map_line))
	{
		ft_printf("Error!\ndosya okunamıyor!");
		return (1);
	}
	return (0);
}

int	map_control(t_map *map)
{
	if (rectangle_c(map) || char_c(map) || wall_c(map) || \
			element_c(map) || valid_c(map))
	{
		free_map(map);
		return (1);
	}
	free_map(map);
	return (0);
}

int	map_init(t_map *map, char *argc)
{
	int	x;

	map_read_control(map, argc);
	map->p_move_c = 0;
	map->mlx = mlx_init();
	x = ft_strlen(map->map_line[0]) - 1;
	map->mlx_win = mlx_new_window(map->mlx, \
		64 * x, 64 * map->map_y_line, "SO_LONG");
	if (!map->mlx || !map->mlx_win || create_xpm(map))
	{
		ft_printf("Error!\nMLX hatası!");
		return (1);
	}
	win_put_img(map);
	mlx_string_put(map->mlx, map->mlx_win, 15, 15, 16777215, "0");
	mlx_hook(map->mlx_win, 2, 1L << 2, ft_move, map);
	mlx_hook(map->mlx_win, 17, 1L << 2, ft_exit, map);
	mlx_loop(map->mlx);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_map	map;

	if (file_control(argc, argv[1]) || map_read_control(&map, argv[1]))
		return (1);
	if (map_control(&map))
		return (1);
	if (map_init(&map, argv[1]))
		return (1);
	return (0);
}
