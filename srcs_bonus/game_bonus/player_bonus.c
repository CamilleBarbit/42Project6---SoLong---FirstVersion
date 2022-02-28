/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:24:05 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/28 10:15:27 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

/*
Functions ensuring that player can move
*/

void	ft_move_up(t_map *map_ptr)
{
	ft_replace_letters(map_ptr);
	map_ptr->player_y--;
	if (map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] == 'C')
	{
		map_ptr->collected_items += 1;
		map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] = 'P';
	}
	else if ((map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] == 'E')
		&& (map_ptr->collected_items == map_ptr->total_items))
	{
		map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] = 'P';
		ft_exit_game(map_ptr);
		ft_printf("Congratulations, you are done playing! Come back soon!\n");
	}
	else if (map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] == '0')
		map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] = 'P';
	else if ((map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] == 'E')
		&& (map_ptr->collected_items != map_ptr->total_items))
	{
		map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] = 'P';
		map_ptr->temp = 1;
		ft_printf("Please, go collect all items!\n");
	}
	ft_making_the_move(map_ptr);
}

void	ft_move_left(t_map *map_ptr)
{
	ft_replace_letters(map_ptr);
	map_ptr->player_x--;
	if (map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] == 'C')
	{
		map_ptr->collected_items += 1;
		map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] = 'P';
	}
	else if ((map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] == 'E')
		&& (map_ptr->collected_items == map_ptr->total_items))
	{
		map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] = 'P';
		ft_exit_game(map_ptr);
		ft_printf("Congratulations, you are done playing! Come back soon!\n");
	}
	else if (map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] == '0')
		map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] = 'P';
	else if ((map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] == 'E')
		&& (map_ptr->collected_items != map_ptr->total_items))
	{
		map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] = 'P';
		map_ptr->temp = 1;
		ft_printf("Please, go collect all items!\n");
	}
	ft_making_the_move(map_ptr);
}

void	ft_move_down(t_map *map_ptr)
{
	ft_replace_letters(map_ptr);
	map_ptr->player_y++;
	if (map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] == 'C')
	{
		map_ptr->collected_items += 1;
		map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] = 'P';
	}
	else if ((map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] == 'E')
		&& (map_ptr->collected_items == map_ptr->total_items))
	{
		map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] = 'P';
		ft_exit_game(map_ptr);
		ft_printf("Congratulations, you are done playing! Come back soon!\n");
	}
	else if (map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] == '0')
		map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] = 'P';
	else if ((map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] == 'E')
		&& (map_ptr->collected_items != map_ptr->total_items))
	{
		map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] = 'P';
		map_ptr->temp = 1;
		ft_printf("Please, go collect all items!\n");
	}
	ft_making_the_move(map_ptr);
}

void	ft_move_right(t_map *map_ptr)
{
	ft_replace_letters(map_ptr);
	map_ptr->player_x++;
	if (map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] == 'C')
	{
		map_ptr->collected_items += 1;
		map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] = 'P';
	}
	else if ((map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] == 'E')
		&& (map_ptr->collected_items == map_ptr->total_items))
	{
		map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] = 'P';
		ft_exit_game(map_ptr);
		ft_printf("Congratulations, you are done playing!\nCome back soon!\n");
	}
	else if (map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] == '0')
		map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] = 'P';
	else if ((map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] == 'E')
		&& (map_ptr->collected_items != map_ptr->total_items))
	{
		map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] = 'P';
		map_ptr->temp = 1;
		ft_printf("Please, go collect all items!\n");
	}
	ft_making_the_move(map_ptr);
}
