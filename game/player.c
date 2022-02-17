/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:24:05 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/17 14:30:13 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
Functions ensuring that player can move
*/

void    ft_move_up(struct s_Map *map_ptr)
{
	if (map_ptr->map_tab[map_ptr->player_position_y - 1][map_ptr->player_position_x] != '1')
	{
		if (map_ptr->map_tab[map_ptr->player_position_y - 1][map_ptr->player_position_x] == 'C')
		{
			map_ptr->map_tab[map_ptr->player_position_y - 1][map_ptr->player_position_x] == 'P';
			map_ptr->count_items--;
			ft_redraw_map();
		}
		else if (map_ptr->map_tab[map_ptr->player_position_y - 1][map_ptr->player_position_x] == '0')
		{
			map_ptr->map_tab[map_ptr->player_position_y - 1][map_ptr->player_position_x] == 'P';
			ft_redraw_map();
		}
		else if (map_ptr->map_tab[map_ptr->player_position_y - 1][map_ptr->player_position_x] == 'E' 
		&& map_ptr->count_items == 0)
		{
			
		}
	}
	else
		printf("Error\nMoving forward is impossible!");
}



















void    ft_move_left(struct s_Map *map_ptr)
{
    if(map_ptr->map_tab[map_ptr->player_position_y][map_ptr->player_position_x - 1] !=1)
    {
        map_ptr->player_position_x--;
		get_items(map_ptr);
    }
	else
		printf("Error\nMoving left is impossible!");
}

void    ft_move_down(struct s_Map *map_ptr)
{
    if(map_ptr->map_tab[map_ptr->player_position_y + 1][map_ptr->player_position_x] !=1)
    {
        map_ptr->player_position_y++;
		get_items(map_ptr);
    }
	else
		printf("Error\nMoving down is impossible!");
}

void    ft_move_right(struct s_Map *map_ptr)
{
    if(map_ptr->map_tab[map_ptr->player_position_y][map_ptr->player_position_x + 1] !=1)
    {
        map_ptr->player_position_x++;
		get_items(map_ptr);
    }
	else
		printf("Error\nMoving right is impossible!");
}