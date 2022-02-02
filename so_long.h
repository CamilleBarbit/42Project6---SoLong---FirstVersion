#ifndef SO_LONG_H
# define SO_LONG_H

#include "minilibx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct map map;
struct map
{
    void    *mlx;
    void    *window;
    void    *image;
    int     x; //pour les absisses - les colonnes
    int     y; //pour les ordonnées - les lignes
    char    *str_map;
};

#endif
