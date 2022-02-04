/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:34:06 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/03 13:10:13 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include "minilibx/mlx.h"
#include "get_next_line/get_next_line.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct map map;
struct map
{
    void        *mlx;
    void        *window;
    void        *image;
    int         x; //pour les absisses - les colonnes
    int         y; //pour les ordonnées - les lignes
};

int	ft_check_map_form(char **tab, char *file_name, int size);
int	ft_check_walls(char **tab, char *file_name, int size);

#endif
