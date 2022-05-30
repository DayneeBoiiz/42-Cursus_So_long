/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:52:52 by sayar             #+#    #+#             */
/*   Updated: 2022/02/12 10:36:18 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_up(t_map *param)
{
	char	*photo;
	int		w;
	int		h;

	if (!map_c.collect)
		map_c.collect = 0;
	if (ft_finished(param, param->playery - 1, param->playerx) == 1)
	{
		photo = mlx_xpm_file_to_image(param->mlx, "./img/player.xpm", &w, &h);
		mlx_put_image_to_window(param->mlx, param->mlx_win, photo,
			param->x, param->y += 50);
		mlx_destroy_image(param->mlx, photo);
		param->map_load[param->playery][param->playerx] = '0';
		param->map_load[param->playery - 1][param->playerx] = 'P';
		printf("Mouvement : %d\n", map_c.moves += 1);
		ft_put_in_map(param);
	}
}

void	ft_move_down(t_map *param)
{
	char	*photo;
	int		w;
	int		h;

	if (!map_c.collect)
		map_c.collect = 0;
	if (ft_finished(param, param->playery + 1, param->playerx) == 1)
	{
		photo = mlx_xpm_file_to_image(param->mlx, "./img/player.xpm", &w, &h);
		mlx_put_image_to_window(param->mlx, param->mlx_win, photo,
			param->x, param->y += 50);
		mlx_destroy_image(param->mlx, photo);
		param->map_load[param->playery][param->playerx] = '0';
		param->map_load[param->playery + 1][param->playerx] = 'P';
		printf("Mouvement : %d\n", map_c.moves += 1);
		ft_put_in_map(param);
	}
}

void	ft_move_right(t_map *param)
{
	char	*photo;
	int		w;
	int		h;

	if (!map_c.collect)
		map_c.collect = 0;
	if (ft_finished(param, param->playery, param->playerx + 1) == 1)
	{
		photo = mlx_xpm_file_to_image(param->mlx, "./img/player.xpm", &w, &h);
		mlx_put_image_to_window(param->mlx, param->mlx_win, photo,
			param->x, param->y += 50);
		mlx_destroy_image(param->mlx, photo);
		param->map_load[param->playery][param->playerx] = '0';
		param->map_load[param->playery][param->playerx + 1] = 'P';
		printf("Mouvement : %d\n", map_c.moves += 1);
		ft_put_in_map(param);
	}
}

void	ft_move_left(t_map *param)
{
	char	*photo;
	int		w;
	int		h;

	if (!map_c.collect)
		map_c.collect = 0;
	if (ft_finished(param, param->playery, param->playerx - 1) == 1)
	{
		photo = mlx_xpm_file_to_image(param->mlx, "./img/player.xpm", &w, &h);
		mlx_put_image_to_window(param->mlx, param->mlx_win, photo,
			param->x, param->y += 50);
		mlx_destroy_image(param->mlx, photo);
		param->map_load[param->playery][param->playerx] = '0';
		param->map_load[param->playery][param->playerx - 1] = 'P';
		printf("Mouvement : %d\n", map_c.moves += 1);
		ft_put_in_map(param);
	}
}

int	ft_keybinds(int key, t_map *param)
{
	if (key == 13 && (param->map_load[param->playery - 1]
			[param->playerx] != '1'))
		ft_move_up(param);
	if (key == 1 && (param->map_load[param->playery + 1]
			[param->playerx] != '1'))
		ft_move_down(param);
	if (key == 2 && (param->map_load[param->playery]
			[param->playerx + 1] != '1'))
		ft_move_right(param);
	if (key == 0 && (param->map_load[param->playery]
			[param->playerx - 1] != '1'))
		ft_move_left(param);
	if (key == 53)
	{
		ft_putstr("u pressed 'ESC'");
		ft_destroy_window(param);
	}
	return (0);
}
