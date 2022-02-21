/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:47:07 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/21 17:26:57 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
Associating each file to an image
*/

void	ft_associate_files_to_images(struct s_Map *map_ptr)
{
	map_ptr->mlx_items = mlx_xpm_file_to_image(map_ptr->mlx_ptr, ITEMS_IM, &map_ptr->im_width, &map_ptr->im_heigth);
	if (!map_ptr->mlx_items)
		printf("Error\nFile could not be converted into image!\n");
	map_ptr->mlx_player = mlx_xpm_file_to_image(map_ptr->mlx_ptr, PLAYER_IM, &map_ptr->im_width, &map_ptr->im_heigth);
	if (!map_ptr->mlx_player)
		printf("Error\nFile could not be converted into image!\n");
	map_ptr->mlx_exit = mlx_xpm_file_to_image(map_ptr->mlx_ptr, EXIT_IM, &map_ptr->im_width, &map_ptr->im_heigth);
	if (!map_ptr->mlx_exit)
		printf("Error\nFile could not be converted into image!\n");
	map_ptr->mlx_empty_spaces = mlx_xpm_file_to_image(map_ptr->mlx_ptr, EMPTY_IM, &map_ptr->im_width, &map_ptr->im_heigth);
	if (!map_ptr->mlx_empty_spaces)
		printf("Error\nFile could not be converted into image!\n");
	map_ptr->mlx_walls = mlx_xpm_file_to_image(map_ptr->mlx_ptr, WALLS_IM, &map_ptr->im_width, &map_ptr->im_heigth);
	if (!map_ptr->mlx_walls)
		printf("Error\nFile could not be converted into image!\n");
}

/* 
Initializing the game
*/

void	ft_init_game(struct s_Map *map_ptr)
{
	get_player_position(map_ptr);
	get_number_of_items(map_ptr);
    map_ptr->mlx_ptr = mlx_init();
	if (!map_ptr->mlx_ptr)
		printf("Error\nConnection could not be established!\n");
    map_ptr->mlx_window = mlx_new_window(map_ptr->mlx_ptr, map_ptr->size_x * map_ptr->im_width, map_ptr->map_size * map_ptr->im_heigth, map_ptr->map_title);
	if (!map_ptr->mlx_window)
		printf("Error\nFailed to create a new window!\n");
	ft_associate_files_to_images(map_ptr);
	ft_draw_map(map_ptr);
	printf("Ready to play? Come on!\n");
}