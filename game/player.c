/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:24:05 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/12 12:29:43 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
                map_ptr->map[y][x] = '0';
            }
            x++;
        }
        y++;
    }
}