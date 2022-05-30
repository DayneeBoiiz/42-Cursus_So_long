/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 19:02:31 by sayar             #+#    #+#             */
/*   Updated: 2022/02/12 10:24:39 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map_valid(int fd, int *map_size)
{
	char	*line;
	char	*prev;

	prev = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			ft_check("");
			break ;
		}
		*map_size += ft_strlen(line + 1);
		if (!prev)
			ft_check_top_walls(line);
		else
			ft_check_side_walls(line);
		ft_check_map_shape(line);
		ft_check(line);
		ft_invalid_char(line);
		prev = line;
		free(line);
	}
	ft_check_top_walls(prev);
	free(line);
}

void	ft_open_map(char *file, int *map_size)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Error\n");
		ft_putstr("Wrong file Path");
		exit (0);
	}
	else
	{
		ft_check_map_valid(fd, map_size);
		if (close(fd) == -1)
		{
			perror("Error\n");
			exit (0);
		}
	}
}

void	ft_check(char *line)
{
	int		i;

	i = 0;
	if (!map_c.player)
		map_c.player = 0;
	if (!map_c.collect)
		map_c.collect = 0;
	if (!map_c.exit)
		map_c.exit = 0;
	if (line[i] == '\0' && (map_c.player == 0 || map_c.player >= 2
			|| map_c.collect == 0 || map_c.exit == 0))
	{
		ft_putstr("Error\n");
		if (map_c.player == 0 || map_c.player >= 2)
			ft_putstr("you must have only one player");
		if (map_c.exit == 0)
			ft_putstr("you must have atleast one exit");
		if (map_c.collect == 0)
			ft_putstr("you must have atleast one collectibles");
		exit (0);
	}
	while (line[i++])
		ft_count_char(line[i]);
}

void	ft_invalid_char(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 'P' && line[i] != 'E' && line[i] != 'C'
			&& line[i] != '1' && line[i] != '0' && line[i] != '\n')
		{
			ft_putstr("Error\n");
			ft_putstr("Invalid Chatacter in the map");
			exit (0);
		}
		i++;
	}
}
