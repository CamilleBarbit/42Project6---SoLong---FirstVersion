/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 12:24:05 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/21 17:41:13 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
Functions ensuring that player can move
*/

void    ft_move_up(struct s_Map *map_ptr)
{
	map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] = '0';
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
		printf("Congratulations, you are done playing! Come back soon!\n");
	}
	else if (map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] == '0')
		map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] = 'P';
	else if ((map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] == 'E')
		&& (map_ptr->collected_items != map_ptr->total_items))
	{
		printf("Collect all items!");
	}
	map_ptr->count_moves++;
	printf("You have made: %d moves!\n", map_ptr->count_moves);
	ft_draw_map(map_ptr);
}


void    ft_move_left(struct s_Map *map_ptr)
{
	map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] = '0';
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
		printf("Congratulations, you are done playing! Come back soon!\n");
	}
	else if (map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] == '0')
		map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] = 'P';
	else if ((map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] == 'E')
		&& (map_ptr->collected_items != map_ptr->total_items))
	{
		printf("Collect all items!");
	}
	map_ptr->count_moves++;
	printf("You have made: %d moves!\n", map_ptr->count_moves);
	ft_draw_map(map_ptr);
}

void    ft_move_down(struct s_Map *map_ptr)
{
	map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] = '0';
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
		printf("Congratulations, you are done playing! Come back soon!\n");
	}
	else if (map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] == '0')
		map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] = 'P';
	else if ((map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] == 'E')
		&& (map_ptr->collected_items != map_ptr->total_items))
	{
		printf("Collect all items!");
	}
	map_ptr->count_moves++;
	printf("You have made: %d moves!\n", map_ptr->count_moves);
	ft_draw_map(map_ptr);
}

void    ft_move_right(struct s_Map *map_ptr)
{
	map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] = '0';
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
		printf("Congratulations, you are done playing! Come back soon!\n");
	}
	else if (map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] == '0')
		map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] = 'P';
	else if ((map_ptr->map_tab[map_ptr->player_y][map_ptr->player_x] == 'E')
		&& (map_ptr->collected_items != map_ptr->total_items))
	{
		printf("Collect all items!");
	}
	map_ptr->count_moves++;
	printf("You have made: %d moves!\n", map_ptr->count_moves);
	ft_draw_map(map_ptr);
}