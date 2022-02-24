/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:34:06 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/24 14:40:30 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* LIBRARIES */

# include "minilibx/mlx.h"
# include "get_next_line/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>

/* STRUCTURE */

typedef struct s_Map	t_map;
struct s_Map
{
	char	**map_tab;
	char	*file_name;
	int		map_size;
	int		player_x;
	int		player_y;
	void	*mlx_ptr;
	void	*mlx_window;
	void	*mlx_exit;
	void	*mlx_walls;
	void	*mlx_player;
	void	*mlx_items;
	void	*mlx_empty_spaces;
	char	map_title[100];
	int		size_x;
	int		count_moves;
	int		collected_items;
	int		total_items;
	int		im_width;
	int		im_heigth;
	int		temp;
};

/* KEY CODES */

# define ESC 65307
# define GO_UP 119
# define GO_DOWN 115
# define GO_LEFT 97
# define GO_RIGHT 100

/* FILES ASSOCIATED WITH IMAGES */

# define ITEMS_IM "images/items.xpm"
# define PLAYER_IM "images/player.xpm"
# define EXIT_IM "images/exit.xpm"
# define EMPTY_IM "images/empty_spaces.xpm"
# define WALLS_IM "images/walls.xpm"

/* FUNCTIONS */

int		ft_recup_map_size(char *file_name);
char	**ft_recup_map(t_map *map_ptr);
int		ft_check_map_form(t_map *map_ptr);
int		ft_check_map_walls(t_map *map_ptr, int x, int y);
int		ft_check_map_char(t_map *map_ptr);
void	ft_free_map(t_map *map_ptr);
int		ft_filler_basics(t_map *map_ptr, char *str);
void	ft_associate_files_to_images(t_map *map_ptr);
void	get_player_position(t_map *map_ptr);
void	get_number_of_items(t_map *map_ptr);
void	ft_draw_map(t_map *map_ptr);
char	*ft_sdup(char *src);
int		ft_len(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_check_file_name(char *file_name, int j, char *str, int count);
int		ft_check_all_errors(t_map *map_ptr);
char	*ft_strcpy(char *dest, char *src);
void	ft_init_game(t_map *map_ptr);
void	ft_game_inputs(t_map *map_ptr);
int		handle_key(int keycode, t_map *map_ptr);
void	ft_move_right(t_map *map_ptr);
void	ft_move_left(t_map *map_ptr);
void	ft_move_up(t_map *map_ptr);
void	ft_move_down(t_map *map_ptr);
void	ft_dealloc(t_map *map_ptr);
void	ft_free_game(t_map *map_ptr);
int		ft_exit_game(t_map *map_ptr);
int		ft_try_to_open_file(char *file_name);
int		ft_check_all_errors_file_name(char *file_name);
void	ft_replace_letters(t_map *map_ptr);
void	ft_making_the_move(t_map *map_ptr);
void	ft_function_to_draw(t_map *map_ptr, void *ptr_file, int x, int y);
int		ft_try_to_open_xpm(void);

#endif
