/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:34:06 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/09 13:10:01 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "minilibx/mlx.h"
#include "get_next_line/get_next_line.h"
#include <stdlib.h>


typedef struct s_Map s_Map;
struct  s_Map
{
    char	**map_tab;
	char	*file_name;
    int		map_size;
    void    *mlx_init;
    void	*mlx_window;
    char    map_title[100];
};

int		ft_recup_map_size(char *file_name);
char	**ft_print_map(struct s_Map *map_ptr);
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

#endif
