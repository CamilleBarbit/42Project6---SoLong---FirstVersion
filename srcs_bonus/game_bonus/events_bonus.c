/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:19:59 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/28 10:12:44 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

/*
Function to ligthen the player's moves
*/

void	ft_replace_letters(t_map *map_ptr)
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
Closing all images + Closing window 
*/

int	ft_exit_game(t_map *map_ptr)
{
	ft_free_game(map_ptr);
	ft_printf("Thank you for playing! Come back soon!\n");
	ft_dealloc(map_ptr);
	exit (1);
}

/*
Dealing with player moves
*/

int	ft_handle_key(int keycode, t_map *map_ptr)
{
	if ((keycode == GO_UP)
		&& (map_ptr->map_tab[map_ptr->player_y - 1][map_ptr->player_x] != '1'))
		ft_move_up(map_ptr);
	else if ((keycode == GO_LEFT)
		&& (map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x - 1] != '1'))
		ft_move_left(map_ptr);
	else if ((keycode == GO_DOWN)
		&& (map_ptr->map_tab[map_ptr->player_y + 1][map_ptr->player_x] != '1'))
		ft_move_down(map_ptr);
	else if ((keycode == GO_RIGHT)
		&& (map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x + 1] != '1'))
		ft_move_right(map_ptr);
	else if (keycode == ESC)
		ft_exit_game(map_ptr);
	else
		ft_printf("Error\nCould not move the character!\n");
	return (0);
}

/*
Red cross + Keypress 
*/

void	ft_game_inputs(t_map *map_ptr)
{
	mlx_hook(map_ptr->mlx_window, 33, 1L << 5, &ft_exit_game, map_ptr);
	mlx_hook(map_ptr->mlx_window, 2, 1L << 0, &ft_handle_key, map_ptr);
}	
