/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:46:15 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/17 14:40:49 by cbarbit          ###   ########.fr       */
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

int	get_number_of_items(struct s_Map *map_ptr)
{
	int	x;
	int	y;
	int	count;

	x = 0;
	y = 0;
	count = 0;
	while (map_ptr->map_tab[y])
	{
		x = 0;
		while (map_ptr->map_tab[y][x])
		{
			if (map_ptr->map_tab[y][x] == 'C')
				count += 1;
			x++;
		}
		y++;
	}
	return (count);
}

void	ft_redraw_map(struct s_Map *map_ptr, )
{
	map_ptr->map_tab[map_ptr->player_position_y][map_ptr->player_position_x] = '0';
	map_ptr->count_moves++;
	printf("You have made %d mouvements!", map_ptr->count_moves);
	
}