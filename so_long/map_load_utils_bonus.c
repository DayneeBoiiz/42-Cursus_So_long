/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_load_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 13:13:58 by sayar             #+#    #+#             */
/*   Updated: 2022/02/07 11:48:35 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_open_mapfile(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("Error\n");
		exit (0);
	}
	return (fd);
}

void	*ft_close_mapfile(int fd, char **load[])
{
	if (close(fd) == 0)
		return (*load);
	else
	{
		free(*load);
		perror("Error\n");
		exit (0);
	}
}

char	**ft_load_map(char *file, int map_size, t_map *map)
{
	int		i;
	int		fd;
	char	*line;
	char	**load;

	i = 0;
	fd = ft_open_mapfile(file);
	load = malloc(sizeof(char *) * map_size);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (i == 0)
		{
			map->map_columns = ft_count_line(line);
		}
		load[i] = ft_strdup(line);
		free((char *)line);
		i++;
	}
	map->map_rows = i;
	load[i] = NULL;
	return (ft_close_mapfile(fd, &load));
}
