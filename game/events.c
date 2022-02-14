/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:19:59 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/14 16:29:35 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

int key_hook(int keycode, struct s_Map *map_ptr) //This is the function called
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

int mouse_hook()