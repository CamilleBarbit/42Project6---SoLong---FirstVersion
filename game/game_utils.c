/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:46:15 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/18 11:59:05 by camillebarb      ###   ########.fr       */
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
				
                map_ptr->player_position_x = x;
                map_ptr->player_position_y = y;
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

void	ft_redraw_map(struct s_Map *map_ptr, )
{
	map_ptr->map_tab[map_ptr->player_position_y][map_ptr->player_position_x] = '0';
	map_ptr->count_moves++;
	printf("You have made %d mouvements!", map_ptr->count_moves);
	
}