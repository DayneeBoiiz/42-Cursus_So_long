/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_enemy_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 14:37:24 by sayar             #+#    #+#             */
/*   Updated: 2022/02/07 14:57:47 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player(t_map *map, int x, int y)
{
	map->playerx = x;
	map->playery = y;
}

void	enemy(t_map *map, int x, int y)
{
	map->enemy_x = x;
	map->enemy_y = y;
}

void	ft_destroy(t_map *param)
{
	ft_putstr("u pressed 'ESC'");
	ft_destroy_window(param);
}

void	move(t_map *param)
{
	ft_met_enemy(param, param->playery, param->playerx - 1);
	ft_move_left(param);
}
