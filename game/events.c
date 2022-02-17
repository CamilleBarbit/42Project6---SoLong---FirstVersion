/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 16:19:59 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/17 13:48:54 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
Closing all images + Closing window 
*/

void	ft_exit_game(struct s_Map *map_ptr)
{
    mlx_destroy_image(map_ptr->mlx_ptr, map_ptr->mlx_walls);
	mlx_destroy_image(map_ptr->mlx_ptr, map_ptr->mlx_items);
	mlx_destroy_image(map_ptr->mlx_ptr, map_ptr->mlx_player);
	mlx_destroy_image(map_ptr->mlx_ptr, map_ptr->mlx_exit);
	mlx_destroy_image(map_ptr->mlx_ptr, map_ptr->mlx_empty_spaces);
	mlx_destroy_window(map_ptr->mlx_ptr, map_ptr->mlx_window);
	ft_free_map(map_ptr);	
}

void	ft_exit_game_properly(struct s_Map *map_ptr)
{
	
}

int	handle_key(int keycode, struct s_Map *map_ptr)
{
	if (keycode == GO_UP)
		ft_move_up(map_ptr);
	else if (keycode == GO_LEFT)
		ft_move_left(map_ptr);
	else if (keycode == GO_DOWN)
		ft_move_down(map_ptr);
	else if (keycode == GO_RIGHT)
		ft_move_right(map_ptr);
	else if (keycode == ESC)
		ft_exit_game(map_ptr);
	return (0);
}

/*
Red cross + Keypress 
*/

void	ft_game_inputs(struct s_Map *map_ptr)
{
	mlx_hook(map_ptr->mlx_window, 33, 1L << 5, ft_exit_game, map_ptr);
	mlx_hook(map_ptr->mlx_window, 2, 1L << 0, handle_key, map_ptr);
	//mlx_hook(game->mlx_win, 9, 1L << 21, &init_resume_window, game);
}	
