/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:46:15 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/23 15:15:43 by cbarbit          ###   ########.fr       */
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
				map_ptr->total_items ++;
			x++;
		}
		y++;
	}
}


/*
Function to ligthen the player's moves
*/

void	ft_replace_letters(struct s_Map *map_ptr)
{
    if (map_ptr->temp == 0)
		map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] = '0';
	if (map_ptr->temp == 1)
	{
		map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] = 'E';
		map_ptr->temp = 0;
	}
}

/*
Function t lighten the player's moves
*/

void	ft_making_the_move(struct s_Map *map_ptr)
{
	map_ptr->count_moves++;
	printf("You have made: %d moves!\n", map_ptr->count_moves);
	ft_draw_map(map_ptr);
}