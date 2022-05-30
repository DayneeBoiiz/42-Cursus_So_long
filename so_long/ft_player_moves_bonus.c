/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_moves_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 13:44:30 by sayar             #+#    #+#             */
/*   Updated: 2022/02/07 11:49:47 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_player_moves(t_map *map)
{
	if (map->dir == 13)
	{
		return ("./img/playerw.xpm");
	}
	if (map->dir == 1)
		return ("./img/players.xpm");
	if (map->dir == 0)
		return ("./img/playera.xpm");
	if (map->dir == 2)
		return ("./img/playerd.xpm");
	return ("./img/player.xpm");
}
