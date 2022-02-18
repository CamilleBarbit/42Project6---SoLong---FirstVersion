/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:34:06 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/18 11:27:33 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* LIBRARIES */

#include "mlx.h"
#include "get_next_line/get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

/* STRUCTURE */

typedef struct s_Map s_Map;
struct  s_Map
{
	char	**map_tab; //défini dans filler
	char	*file_name; //défini dans filler
	int		map_size; //défini dans filler
	int		player_position_x; //défini dans init_game
	int		player_position_y; //défini dans init_game
	void	*mlx_ptr; //défini dans ft_init_game
	void	*mlx_window; //défini dans ft_init_game
	void	*mlx_exit; //défini dans ft_associate_files_to_images
	void	*mlx_walls; //défini dans ft_associate_files_to_images
	void	*mlx_player; //défini dans ft_associate_files_to_images
	void	*mlx_items; //défini dans ft_associate_files_to_images
	void	*mlx_empty_spaces; //défini dans ft_associate_files_to_images
	char	map_title[100]; //défini dans filler
	int		size_x; //défini dans filler
	int		count_mouv;
	int		remaining_items;
	int		total_items; //définir dans check_map_char
};

/* PIXELS PER IMAGE */

# define WIDTH 32
# define HEIGTH 32

/* KEY CODES */

# define ESC 65307
# define GO_UP 119
# define GO_DOWN 115
# define GO_LEFT 97
# define GO_RIGHT 100

/* FUNCTIONS */

int		ft_recup_map_size(char *file_name);
char	**ft_recup_map(struct s_Map *map_ptr);
int		ft_check_map_form(struct s_Map *map_ptr);
int		ft_check_walls(struct s_Map *map_ptr);
int		ft_check_map_char(struct s_Map *map_ptr);
void	ft_free_map(struct s_Map *map_ptr);
void	ft_filler_basics(s_Map *map_ptr, char *str);
void	ft_associate_files_to_images(struct s_Map *map_ptr);
void	get_player_position(struct s_Map *map_ptr);
int		get_number_of_items(struct s_Map *map_ptr);
void	ft_draw_map(struct s_Map *map_ptr);
char	*ft_sdup(char *src);
int		ft_len(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_check_file_name(char *file_name);
int		ft_check_all_errors(struct s_Map *map_ptr);
char	*ft_strcpy(char *dest, char *src);
void	ft_init_game(struct s_Map *map_ptr);
void	ft_game_inputs(struct s_Map *map_ptr);
int 	handle_key(int keycode, struct s_Map *map_ptr);
void    ft_move_right(struct s_Map *map_ptr);
void    ft_move_left(struct s_Map *map_ptr);
void    ft_move_up(struct s_Map *map_ptr);
void    ft_move_down(struct s_Map *map_ptr);

#endif
