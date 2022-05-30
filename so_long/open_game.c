/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 16:27:24 by sayar             #+#    #+#             */
/*   Updated: 2022/02/07 14:29:20 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_destroy_window(t_map *map)
{
	mlx_destroy_window(map->mlx, map->mlx_win);
	free(map->map_load);
	exit (0);
}

char	*ft_pull_img(char c)
{
	if (c == 'P')
		return ("./img/playerd.xpm");
	if (c == '1')
		return ("./img/wall.xpm");
	if (c == 'C')
		return ("./img/coin.xpm");
	if (c == 'E')
		return ("./img/exit.xpm");
	return ("./img/bg.xpm");
}

void	ft_put_img(char c, int x, int y, t_map *map)
{
	char	*photo;
	char	*bg_parser;
	int		w;
	int		h;

	bg_parser = mlx_xpm_file_to_image(map->mlx, "./img/bg.xpm", &w, &h);
	mlx_put_image_to_window(map->mlx, map->mlx_win, bg_parser, map->x, map->y);
	mlx_destroy_image(map->mlx, bg_parser);
	photo = mlx_xpm_file_to_image(map->mlx, ft_pull_img(c), &w, &h);
	mlx_put_image_to_window(map->mlx, map->mlx_win, photo, x, y);
	mlx_destroy_image(map->mlx, photo);
}

void	ft_put_in_map(t_map *map)
{
	int	y;
	int	x;

	y = 0;
	map->y = 0;
	while (map->map_load[y])
	{
		x = 0;
		map->x = 0;
		while (map->map_load[y][x] != '\0')
		{
			if (map->map_load[y][x] != '\n')
				ft_put_img(map->map_load[y][x], map->x, map->y, map);
			if (map->map_load[y][x] == 'P')
			{
				map->playerx = x;
				map->playery = y;
			}
			map->x += 50;
			x++;
		}
		map->y += 50;
		y++;
	}
}

void	ft_open_game(t_map *map)
{
	int	window_w;
	int	window_h;

	window_w = map->map_columns * 50;
	window_h = map->map_rows * 50;
	if (window_h > 1080 || window_w > 1920)
	{
		ft_putstr("Error\n");
		exit (0);
	}
	else
	map->mlx = mlx_init();
	map->mlx_win = mlx_new_window(map->mlx, window_w, window_h, "So_long");
	mlx_key_hook(map->mlx_win, ft_keybinds, map);
	mlx_hook(map->mlx_win, 17, 0, ft_destroy_window, map);
	ft_put_in_map(map);
	mlx_loop(map->mlx);
}
