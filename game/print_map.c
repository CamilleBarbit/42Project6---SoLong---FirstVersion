/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 11:32:48 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/24 14:28:39 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_function_to_draw(t_map *map_ptr, void *ptr_file, int x, int y)
{
	mlx_put_image_to_window(map_ptr->mlx_ptr, map_ptr->mlx_window,
		ptr_file, map_ptr->im_width * x, map_ptr->im_heigth * y);
}

void	ft_draw_map(t_map *map_ptr)
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
				ft_function_to_draw(map_ptr, map_ptr->mlx_walls, x, y);
			else if (map_ptr->map_tab[y][x] == 'C')
				ft_function_to_draw(map_ptr, map_ptr->mlx_items, x, y);
			else if (map_ptr->map_tab[y][x] == 'P')
				ft_function_to_draw(map_ptr, map_ptr->mlx_player, x, y);
			else if (map_ptr->map_tab[y][x] == 'E')
				ft_function_to_draw(map_ptr, map_ptr->mlx_exit, x, y);
			else if (map_ptr->map_tab[y][x] == '0')
				ft_function_to_draw(map_ptr, map_ptr->mlx_empty_spaces, x, y);
			x++;
		}
		y++;
	}
}
