# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sayar <sayar@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 11:52:13 by sayar             #+#    #+#              #
#    Updated: 2022/02/12 10:38:06 by sayar            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

FLAGS = -Wall -Wextra -Werror

W_FLAGS = -lmlx -framework OpenGL -framework AppKit

NAME = so_long

NAME_B = so_long_bonus

SRC = so_long.c

SRC_B = so_long_bonus.c

UTILS = get_next_line.c ft_finished.c get_next_line_utils.c keyhooks.c libft_utils.c map_load_utils.c map_read_utils.c map_read_utils1.c open_game.c

UTILS_B = enemy_bonus.c ft_finished_bonus.c ft_itoa_bonus.c ft_player_moves_bonus.c player_enemy_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c keyhooks_bonus.c libft_utils_bonus.c map_load_utils_bonus.c map_read_utils_bonus.c map_read_utils1_bonus.c open_game_bonus.c put_str_in_map_bonus.c

OBJ = ${patsubst %.c, %.o, ${UTILS}}

OBJ_B = ${patsubst %.c, %.o, ${UTILS_B}}

.PHONY : all re clean fclean

all : ${NAME}

${NAME} : so_long.h ${OBJ}
	${CC} ${FLAGS} ${W_FLAGS} ${SRC} ${OBJ} -o ${NAME}

${NAME_B} : so_long_bonus.h ${OBJ_B}
	${CC} ${FLAGS} ${W_FLAGS} ${SRC_B} ${OBJ_B} -o ${NAME_B}

bonus : ${NAME} ${NAME_B}

clean :
	rm -rf ${OBJ} ${OBJ_B}

fclean : clean
	rm -rf ${NAME} ${NAME_B}

re : fclean all