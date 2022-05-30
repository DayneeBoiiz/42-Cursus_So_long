/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Map_read_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 13:01:40 by sayar             #+#    #+#             */
/*   Updated: 2022/02/12 10:36:48 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_count_char(char c)
{
	if (c == 'P')
		map_c.player += 1;
	if (c == 'C')
		map_c.collect += 1;
	if (c == 'E')
		map_c.exit += 1;
}

void	ft_check_top_walls(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		if (line[i] != '1')
		{
			ft_putstr("Error\n");
			ft_putstr("The map has to be surrounded by walls '1'");
			exit (0);
		}
		i++;
	}
}

void	ft_check_side_walls(char *line)
{
	int	len;

	len = ft_strlen(line) - 2;
	if (line[0] != '1' || line[len] != '1')
	{
		ft_putstr("Error\n");
		ft_putstr("The map has to be surrounded by walls '1'");
		exit (0);
	}
}

int	ft_count_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	return (i);
}

void	ft_check_map_shape(char *line)
{
	static int	line_len;

	if (!line_len)
		line_len = ft_count_line(line);
	else
	{
		if (line_len != ft_count_line(line))
		{
			ft_putstr("Error\n");
			ft_putstr("invalid map shape");
			exit (0);
		}
	}
}
