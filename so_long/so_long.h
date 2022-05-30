/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:41:50 by sayar             #+#    #+#             */
/*   Updated: 2022/02/07 14:35:24 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>

typedef struct s_map
{
	int		map_rows;
	int		map_columns;
	char	**map_load;
	int		playerx;
	int		playery;
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
	int		mapx;
	int		mapy;
}	t_map;

struct s_map_char
{
	int	player;
	int	collect;
	int	exit;
	int	moves;
}			map_c;

char	*get_next_line(int fd);
int		map_extenstion_check(char	*map);
void	ft_putstr(char *str);
void	ft_open_map(char *file, int *map_size);
void	ft_check_map_valid(int fd, int *map_size);
void	ft_check(char *line);
void	ft_invalid_char(char *line);
void	ft_count_char(char c);
void	ft_check_top_walls(char *line);
void	ft_check_side_walls(char *line);
int		ft_count_line(char *line);
void	ft_check_map_shape(char *line);
int		ft_strlen2(char *str);
char	**ft_load_map(char *file, int map_size, t_map *map);
char	*ft_strdup(char *src);
int		ft_open_mapfile(char *file);
void	*ft_close_mapfile(int fd, char **load[]);
char	**ft_load_map(char *file, int map_size, t_map *map);
void	ft_open_game(t_map *map);
char	*ft_pull_img(char c);
void	ft_put_img(char c, int x, int y, t_map *map);
void	ft_put_in_map(t_map *map);
int		ft_keybinds(int key, t_map *param);
int		ft_destroy_window(t_map *map);
int		ft_finished(t_map *param, int y, int x);

//********** get_next_line **********//
int		ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_next_line(char *lstr);
char	*get_left_str(int fd, char *lstr);

#endif