/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:46:15 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/14 15:50:05 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../so_long.h"

void	get_player_position(struct s_Map *map_ptr)
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

//option1
void	get_number_of_items(int	*tab_count)
{
	map_ptr->count_items = tab_count[1];
}

//option2
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

void	get_items(struct s_Map *map_ptr)
{
	if (map_ptr->map_tab[player_position_y][player_position_x] == 'C')
	{
		map_ptr->count_items--;
		map_ptr->map_tab[player_position_y][player_position_x] == '0';
	}
}