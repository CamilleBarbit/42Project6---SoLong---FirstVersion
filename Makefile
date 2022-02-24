# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 12:32:53 by camillebarb       #+#    #+#              #
#    Updated: 2022/02/24 17:28:11 by cbarbit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

MLXFLAGS = -Lminilibx -lm -lmlx -lXext -lX11

PRINTF_PATH = ft_printf

PRINTF = libftprintf.a

FT_PRINTF = ft_printf/libftprintf.a

MINILIBX_PATH = minilibx

FT_MINILIBX = minilibx/libmlx_Linux.a

MINILIBX = libmlx_Linux.a

C_FILES = srcs/recupmap.c \
			srcs/utils.c \
			srcs/main.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
			srcs/errors/checkerror_file.c \
			srcs/errors/checkerror_map.c \
			srcs/game/game_utils.c \
			srcs/game/init_game.c \
			srcs/game/player.c \
			srcs/game/print_map.c \
			srcs/game/events.c \
			srcs/game/end_game.c \

O_FILES = ${C_FILES:.c=.o}

all: ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${O_FILES} ${PRINTF} ${MINILIBX}
	${CC} ${O_FILES} -Imlx -Iminilibx ${FT_PRINTF} ${FT_MINILIBX} ${MLXFLAGS} -o ${NAME} 


${PRINTF} :
	(cd ${PRINTF_PATH} && ${MAKE})
	cp ${PRINTF_PATH}/${PRINTF} .

${MINILIBX} :
	(cd ${MINILIBX_PATH} && ${MAKE})
	cp ${MINILIBX_PATH}/${MINILIBX} .

clean: 
	${RM} ${O_FILES} 

fclean: clean
	${RM} ${NAME} ${PRINTF} ${MINILIBX}
	cd ${PRINTF_PATH} && ${MAKE} $@

re: fclean all

.PHONY: all clean fclean re