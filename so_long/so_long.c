/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:27:02 by sayar             #+#    #+#             */
/*   Updated: 2022/01/19 17:32:27 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "so_long.h"

int	map_extenstion_check(char	*map)
{
	int	i;

	i = 0;
	while (map[i] != '.')
		i++;
	if (map[i] != '.' || map[i + 1] != 'b' || map[i + 2] != 'e'
		|| map[i + 3] != 'r' || map[i + 4] != '\0')
	{
		return (-1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		map_size;
	t_map	map;

	if (ac != 2)
	{
		ft_putstr("Wrong Number of Args");
		return (0);
	}
	if (map_extenstion_check(av[1]) == -1)
	{
		ft_putstr("Wrong Map Extenstion!\n");
		ft_putstr("Please choose one with *.ber");
		return (0);
	}
	ft_open_map(av[1], &map_size);
	map.map_load = ft_load_map(av[1], map_size, &map);
	ft_open_game(&map);
}
