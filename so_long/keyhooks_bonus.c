/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 10:52:52 by sayar             #+#    #+#             */
/*   Updated: 2022/02/07 14:58:14 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
		ft_met_enemy(param, param->playery, param->playerx);
		param->map_load[param->playery][param->playerx] = '0';
		param->map_load[param->playery - 1][param->playerx] = 'P';
		ft_put_in_map(param);
		map_c.moves++;
		ft_put_str_in_img(param);
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
		ft_met_enemy(param, param->playery, param->playerx);
		param->map_load[param->playery][param->playerx] = '0';
		param->map_load[param->playery + 1][param->playerx] = 'P';
		ft_put_in_map(param);
		map_c.moves++;
		ft_put_str_in_img(param);
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
		ft_met_enemy(param, param->playery, param->playerx);
		param->map_load[param->playery][param->playerx] = '0';
		param->map_load[param->playery][param->playerx + 1] = 'P';
		ft_put_in_map(param);
		map_c.moves++;
		ft_put_str_in_img(param);
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
		ft_met_enemy(param, param->playery, param->playerx);
		param->map_load[param->playery][param->playerx] = '0';
		param->map_load[param->playery][param->playerx - 1] = 'P';
		ft_put_in_map(param);
		map_c.moves++;
		ft_put_str_in_img(param);
	}
}

int	ft_keybinds(int key, t_map *param)
{
	param->dir = key;
	if (key == 13 && (param->map_load[param->playery - 1]
			[param->playerx] != '1'))
	{
		ft_met_enemy(param, param->playery - 1, param->playerx);
		ft_move_up(param);
	}
	if (key == 1 && (param->map_load[param->playery + 1]
			[param->playerx] != '1'))
	{
		ft_met_enemy(param, param->playery + 1, param->playerx);
		ft_move_down(param);
	}
	if (key == 2 && (param->map_load[param->playery]
			[param->playerx + 1] != '1'))
	{
		ft_met_enemy(param, param->playery, param->playerx + 1);
		ft_move_right(param);
	}
	if (key == 0 && (param->map_load[param->playery]
			[param->playerx - 1] != '1'))
		move(param);
	if (key == 53)
		ft_destroy(param);
	return (0);
}
