/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:32:48 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/21 14:27:15 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_draw_map(struct s_Map *map_ptr)
{
	int		x;
	int		y;

	y = 0;
	while (map_ptr->map_tab[y])
	{
		x = 0;
		while (map_ptr->map_tab[y][x])
		{
			if (map_ptr->map_tab[y][x] == '1')
				mlx_put_image_to_window(map_ptr->mlx_ptr, map_ptr->mlx_window, map_ptr->mlx_walls, map_ptr->im_width * x, map_ptr->im_heigth * y);
			else if (map_ptr->map_tab[y][x] == 'C')
				mlx_put_image_to_window(map_ptr->mlx_ptr, map_ptr->mlx_window, map_ptr->mlx_items, map_ptr->im_width * x, map_ptr->im_heigth * y);
			else if (map_ptr->map_tab[y][x] == 'P')
				mlx_put_image_to_window(map_ptr->mlx_ptr, map_ptr->mlx_window, map_ptr->mlx_player, map_ptr->im_width * x, map_ptr->im_heigth * y);
			else if (map_ptr->map_tab[y][x] == 'E')
				mlx_put_image_to_window(map_ptr->mlx_ptr, map_ptr->mlx_window, map_ptr->mlx_exit, map_ptr->im_width * x, map_ptr->im_heigth * y);
			else if (map_ptr->map_tab[y][x] == '0')
				mlx_put_image_to_window(map_ptr->mlx_ptr, map_ptr->mlx_window, map_ptr->mlx_empty_spaces, map_ptr->im_width * x, map_ptr->im_heigth * y);
			x++;
		}
		y++;
	}
}