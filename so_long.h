/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:34:06 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/08 14:54:46 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "minilibx/mlx.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct SoLong SoLong;
struct SoLong
{
    void        *mlx;
    void        *window;
    void        *image;
};

typedef struct Map Map;
struct  Map
{
    char	**map_tab;
	char	*file_name;
    int		map_size;
};

int		ft_recup_map_size(char *file_name);
void	ft_print_map(struct Map *map_ptr);
int		ft_check_map_form(char **tab, int size);
int		ft_check_walls(char **tab, char *file_name, int size);
void	ft_free_map(char **tab, int size);
char	*sdup(char *src);

#endif
