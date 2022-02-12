/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:32:48 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/12 12:32:45 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void ft_draw_map(struct s_Map *map_ptr)
{
	int		x;
	int		y;

	y = 0;
	while (map_ptr->map_tab[y])
	{
		x = 0;
		while (map_ptr->map_tab[y][x])
		{
			if (map_ptr->map_tab == '1')
				mlx_put_image_to_window(map_ptr->mlx_ptr, map_ptr->mlx_window, map_ptr->mlx_walls, 32 * j, 32 * i);
			else if (map_ptr->map_tab == 'C')
				mlx_put_image_to_window(map_ptr->mlx_ptr, map_ptr->mlx_window, map_ptr->mlx_items, 32 * j, 32 * i);
			else if (map_ptr->map_tab == 'P')
				mlx_put_image_to_window(map_ptr->mlx_ptr, map_ptr->mlx_window, map_ptr->mlx_player, 32 * j, 32 * i);
			else if (map_ptr->map_tab == 'E')
				mlx_put_image_to_window(map_ptr->mlx_ptr, map_ptr->mlx_window, map_ptr->mlx_exit, 32 * j, 32 * i);
			else if (map_ptr->map_tab == '0')
				mlx_put_image_to_window(map_ptr->mlx_ptr, map_ptr->mlx_window, map_ptr->mlx_empty_spaces, 32 * j, 32 * i);
			x++;
		}
		y++;
	}
}