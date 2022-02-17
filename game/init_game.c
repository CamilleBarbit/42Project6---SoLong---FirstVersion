/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:47:07 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/17 12:14:40 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
Function to associate a file to an image
*/

void	ft_associate_files_to_images(struct s_Map *map_ptr)
{
	map_ptr->mlx_items = mlx_xpm_file_to_image(map_ptr->mlx_ptr, "images/items.xpm", &map_ptr->width, &map_ptr->heigth);
	if (map_ptr->mlx_items == NULL)
		printf("Error\nFile could not be converted into image!");
	map_ptr->mlx_player = mlx_xpm_file_to_image(map_ptr->mlx_ptr, "images/player.xpm", &map_ptr->width, &map_ptr->heigth);
	if (map_ptr->mlx_player == NULL)
		printf("Error\nFile could not be converted into image!");
	map_ptr->mlx_exit = mlx_xpm_file_to_image(map_ptr->mlx_ptr, "images/exit.xpm", &map_ptr->width, &map_ptr->heigth);
	if (map_ptr->mlx_exit == NULL)
		printf("Error\nFile could not be converted into image!");
	map_ptr->mlx_empty_spaces = mlx_xpm_file_to_image(map_ptr->mlx_ptr, "images/empty_spaces.xpm", &map_ptr->width, &map_ptr->heigth);
	if (map_ptr->mlx_empty_spaces == NULL)
		printf("Error\nFile could not be converted into image!");
	map_ptr->mlx_walls = mlx_xpm_file_to_image(map_ptr->mlx_ptr, "images/walls.xpm", &map_ptr->width, &map_ptr->heigth);
	if (map_ptr->mlx_walls == NULL)
		printf("Error\nFile could not be converted into image!");
}

/* 
Initializing the game
*/

void	ft_init_game(struct s_Map *map_ptr)
{
    map_ptr->mlx_ptr = mlx_init();
	if (map_ptr->mlx_ptr == NULL)
		printf("Error\nConnection could not be established!");
    map_ptr->mlx_window = mlx_new_window(map_ptr->mlx_ptr, map_ptr->size_x * 32, map_ptr->map_size * 32, map_ptr->map_title);
	if (map_ptr->mlx_window == NULL)
		printf("Error\nFailed to create a new window!");
	ft_associate_files_to_images(map_ptr);
	ft_draw_map(map_ptr);
}