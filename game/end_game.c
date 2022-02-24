/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:59:08 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/24 14:54:37 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
Freeing map
*/

void	ft_free_map(t_map *map_ptr)
{
	int	y;

	y = 0;
	while (y < map_ptr->map_size)
	{
		free(map_ptr->map_tab[y]);
		y++;
	}
	free(map_ptr->map_tab);
}

/*
Freeing game
*/

void	ft_free_game(t_map *map_ptr)
{
	mlx_destroy_image(map_ptr->mlx_ptr, map_ptr->mlx_walls);
	mlx_destroy_image(map_ptr->mlx_ptr, map_ptr->mlx_items);
	mlx_destroy_image(map_ptr->mlx_ptr, map_ptr->mlx_player);
	mlx_destroy_image(map_ptr->mlx_ptr, map_ptr->mlx_exit);
	mlx_destroy_image(map_ptr->mlx_ptr, map_ptr->mlx_empty_spaces);
	mlx_destroy_window(map_ptr->mlx_ptr, map_ptr->mlx_window);
	mlx_destroy_display(map_ptr->mlx_ptr);
	free(map_ptr->mlx_ptr);
}

/*
ENDING AND CLEARING ALL IN ANY CASE (FREEING STRUCT)
*/

void	ft_dealloc(t_map *map_ptr)
{
	ft_free_map(map_ptr);
	free(map_ptr->file_name);
	free(map_ptr);
}
