# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 12:32:53 by camillebarb       #+#    #+#              #
#    Updated: 2022/02/25 17:54:35 by cbarbit          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

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
			srcs/errors/checkerror_file.c \
			srcs/errors/checkerror_map.c \
			srcs/game/game_utils.c \
			srcs/game/init_game.c \
			srcs/game/player.c \
			srcs/game/print_map.c \
			srcs/game/events.c \
			srcs/game/end_game.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \

C_FILES_BONUS = srcs_bonus/recupmap_bonus.c \
			srcs_bonus/utils_bonus.c \
			srcs_bonus/main_bonus.c \
			srcs_bonus/errors_bonus/checkerror_file_bonus.c \
			srcs_bonus/errors_bonus/checkerror_map_bonus.c \
			srcs_bonus/game_bonus/game_utils_bonus.c \
			srcs_bonus/game_bonus/init_game_bonus.c \
			srcs_bonus/game_bonus/player_bonus.c \
			srcs_bonus/game_bonus/print_map_bonus.c \
			srcs_bonus/game_bonus/events_bonus.c \
			srcs_bonus/game_bonus/end_game_bonus.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \


O_FILES = ${C_FILES:.c=.o}
O_FILES_BONUS = ${C_FILES_BONUS:.c=.o}

all: ${NAME}

%.o: %.c
	@${CC} ${CFLAGS} -c $< -o $@

${NAME} : ${O_FILES} ${PRINTF} ${MINILIBX}
	@${CC} ${O_FILES} -Imlx -Iminilibx ${FT_PRINTF} ${FT_MINILIBX} ${MLXFLAGS} -o ${NAME} 

bonus: ${NAME_BONUS}

${NAME_BONUS}: ${O_FILES_BONUS} ${PRINTF} ${MINILIBX}
	@${CC} ${O_FILES_BONUS} -Imlx -Iminilibx ${FT_PRINTF} ${FT_MINILIBX} ${MLXFLAGS} -o ${NAME_BONUS}
	
${PRINTF} :
	@(cd ${PRINTF_PATH} && ${MAKE})
	@cp ${PRINTF_PATH}/${PRINTF} .

${MINILIBX} :
	@(cd ${MINILIBX_PATH} && ${MAKE})
	@cp ${MINILIBX_PATH}/${MINILIBX} .

clean: 
	@${RM} ${O_FILES} ${O_FILES_BONUS}

fclean: clean
	@${RM} ${NAME} ${NAME_BONUS} ${PRINTF} ${MINILIBX}
	@cd ${PRINTF_PATH} && ${MAKE} $@
	@cd ${MINILIBX_PATH} && ${MAKE} $<
	@rm -rf ${FT_MINILIBX}
	@rm -rf ./minilibx/libmlx.a

re: fclean all

.PHONY: all clean fclean re