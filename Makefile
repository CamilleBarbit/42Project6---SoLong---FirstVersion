# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/14 12:32:53 by camillebarb       #+#    #+#              #
#    Updated: 2022/02/14 12:47:55 by camillebarb      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = CC

RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

C_FILES = recupmap.c \
			utils.c \
			main.c \
			get_next_line/get_next_line.c \
			get_next_line/get_next_line_utils.c \
			errors/checkerror_file.c \
			errors/checkerror_map.c \
			game/game_utils.c \
			game/init_game.c \
			game/player.c \
			game/print_map.c \

O_FILES = ${C_FILES:.c=.o}

all: ${NAME}

clean: 
	${RM} ${O_FILES}

fclean: clean
	${RM} 