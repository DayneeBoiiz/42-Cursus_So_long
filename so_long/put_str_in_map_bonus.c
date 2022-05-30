/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str_in_map_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sayar <sayar@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 09:16:35 by sayar             #+#    #+#             */
/*   Updated: 2022/02/07 14:32:04 by sayar            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_put_str_in_img(t_map *param)
{
	char	*str;
	char	*str1;
	char	*moves;
	char	*text_in_img;

	str = "So_long";
	moves = ft_itoa(map_c.moves);
	str1 = "Moves :";
	text_in_img = ft_strjoin_text(str1, moves);
	mlx_string_put(param->mlx, param->mlx_win, 25, 15, 0xFFFFFF, str);
	mlx_string_put(param->mlx, param->mlx_win, 150, 15, 0xFFFFFF, text_in_img);
	free(moves);
	free(text_in_img);
}
