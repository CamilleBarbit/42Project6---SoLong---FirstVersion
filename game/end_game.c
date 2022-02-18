/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:59:08 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/18 12:01:28 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
Freeing map
*/

void	ft_free_map(struct s_Map *map_ptr)
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

void    ft_free_game(struct s_Map *map_ptr)
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