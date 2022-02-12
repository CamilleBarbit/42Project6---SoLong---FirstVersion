/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:47:07 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/12 13:25:05 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	init_game(struct s_Map *map_ptr)
{
    map_ptr->mlx_ptr = mlx_init();
    map_ptr->mlx_window = (map_ptr->mlx_ptr, map_ptr->size_x * 32, map_ptr->map_size, map_ptr->map_title);
}	
	
	
	
	// map_ptr->mlx_items = mlx_xpm_file_to_image(map_ptr->mlx_ptr, "images/items.xpm", &width, &height);
	// mlx_ptr->mlx_player = mlx_xpm_file_to_image(map_ptr->mlx_ptr, "images/player.xpm", &width, &height);
	// mlx_ptr->mlx_exit = mlx_xpm_file_to_image(map_ptr->mlx_ptr, "images/exit.xpm", &width, &height);
	// mlx_ptr->mlx_empty_spaces = mlx_xpm_file_to_image(map_ptr->mlx_ptr, "images/empty_spaces.xpm", &width, &height);
	// mlx_ptr->mlx_walls = mlx_xpm_file_to_image(map_ptr->mlx_ptr, "images/walls.xpm", &width, &height);