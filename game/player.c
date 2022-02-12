/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:24:05 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/12 19:56:43 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void    ft_move_up(struct s_Map *map_ptr)
{
    if(map_ptr->map_tab[map_ptr->player_position_y - 1][map_ptr->player_position_x] !=1)
    {
        map_ptr->player_position_y--;
    }
}

void    ft_move_left(struct s_Map *map_ptr)
{
    if(map_ptr->map_tab[map_ptr->player_position_y][map_ptr->player_position_x - 1] !=1)
    {
        map_ptr->player_position_x--;
    }
}

void    ft_move_down(struct s_Map *map_ptr)
{
    if(map_ptr->map_tab[map_ptr->player_position_y + 1][map_ptr->player_position_x] !=1)
    {
        map_ptr->player_position_y++;
    }
}

void    ft_move_right(struct s_Map *map_ptr)
{
    if(map_ptr->map_tab[map_ptr->player_position_y][map_ptr->player_position_x + 1] !=1)
    {
        map_ptr->player_position_x++;
    }
}

void    get_player_position(struct s_Map *map_ptr)
{
    int x;
    int y;

    x = 0;
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
                map_ptr->map_tab[y][x] = '0';
            }
            x++;
        }
        y++;
    }
}

int key_hook(int key code, struct s_Map *map_ptr) //This is the function called
{
    if (keycode == 119)
        ft_move_up(map_ptr);
    else if (keycode == 97)
        ft_move_left(map_ptr);
    else if (keycode == 115)
        ft_move_down(map_ptr);
    else if (keycode == 100)
        ft_move_right(map_ptr);
    else if (keycode == 65307) //esc button
        return (1);
    return (0);
}