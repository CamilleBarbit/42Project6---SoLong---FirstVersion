/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:46:15 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/21 14:16:45 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

/*
Getting player position
*/

void	get_player_position(struct s_Map *map_ptr)
{
    int x;
    int y;

    y = 0;
    while (map_ptr->map_tab[y])
    {
        x = 0;
        while (map_ptr->map_tab[y][x])
        {
            if (map_ptr->map_tab[y][x] == 'P')
            {
				
                map_ptr->player_x = x;
                map_ptr->player_y = y;
            }
            x++;
        }
        y++;
    }
}

/*
Getting number of items
*/

void	get_number_of_items(struct s_Map *map_ptr)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (map_ptr->map_tab[y])
	{
		x = 0;
		while (map_ptr->map_tab[y][x])
		{
			if (map_ptr->map_tab[y][x] == 'C')
				map_ptr->total_items += 1;
			x++;
		}
		y++;
	}
}

void	ft_get_items(struct s_Map *map_ptr)
{
	if (map_ptr->map_tab[map_ptr->player_y][map_ptr->player_y] == 'C')
		map_ptr->items_collected++;
	map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] == 'P';
}

void	ft_redraw_map(struct s_Map *map_ptr, )
{
	map_ptr->count_moves++;
	printf("You have made %d mouvements!", map_ptr->count_moves);
	mlx_destroy_image()
}