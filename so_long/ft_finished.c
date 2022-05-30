/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finished.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:13:10 by sayar             #+#    #+#             */
/*   Updated: 2022/02/07 12:39:25 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_finished(t_map *param, int y, int x)
{
	static int	i;

	if (!i)
		i = 0;
	if (param->map_load[y][x] == 'C')
		i++;
	if (param->map_load[y][x] == 'E')
	{
		if (map_c.collect == i)
		{
			printf("GG You win!!");
			ft_destroy_window(param);
		}
		return (0);
	}
	return (1);
}
