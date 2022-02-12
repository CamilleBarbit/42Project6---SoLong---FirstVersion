/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:34:06 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/12 13:11:32 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "minilibx/mlx.h"
#include "get_next_line/get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct s_Map s_Map;
struct  s_Map
{
    char	**map_tab;
	char	*file_name;
	int		map_size;
	int		player_position_x;
	int		player_position_y;
	void	*mlx_ptr;
	void	*mlx_window;
	void	*mlx_exit;
	void	*mlx_walls;
	void	*mlx_player;
	void	*mlx_items;
	void	*mlx_empty_spaces;
	char	map_title[100];
	int		size_x;
};

int		ft_recup_map_size(char *file_name);
char	**ft_recup_map(struct s_Map *map_ptr);
int		ft_check_map_form(struct s_Map *map_ptr);
int		ft_check_walls(struct s_Map *map_ptr);
int		ft_check_map_char(struct s_Map *map_ptr);
void	ft_free_map(struct s_Map *map_ptr);
char	*ft_sdup(char *src);
int		ft_len(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_check_file_name(char *file_name);
int		ft_check_all_errors(struct s_Map *map_ptr);
char	*ft_strcpy(char *dest, char *src);
void    init_game(struct s_Map *map_ptr);
void    get_player_position(struct s_Map *map_ptr);

#endif
