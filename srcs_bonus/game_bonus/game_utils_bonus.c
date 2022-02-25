/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:46:15 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/25 16:21:03 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

/*
Getting player position
*/

void	get_player_position(t_map *map_ptr)
{
	int	x;
	int	y;

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

void	get_number_of_items(t_map *map_ptr)
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
ITOA 
*/

static int	ft_count_char(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		count = 1;
	if (n < 0)
	{
		n = n * -1;
		count = 1;
	}
	while (n > 0)
	{
		n = n / 10;
		count += 1;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*string;
	int		i;

	if (n == -2147483648)
		return (ft_substr("-2147483648", 0, 11));
	i = ft_count_char(n);
	string = malloc(sizeof(char) * i + 1);
	if (!string)
		return (NULL);
	string[i] = '\0';
	i--;
	if (n == 0)
		string[i] = 48;
	if (n < 0)
	{
		n = n * -1;
		string[0] = '-';
	}
	while (n > 0)
	{
		string[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (string);
}

/*
Function to lighten the player's moves
*/

void	ft_making_the_move(t_map *map_ptr)
{
	char *str1;
	char *str2;
	
	str1 = "You have made: ";
	str2 = ft_itoa(map_ptr->count_moves++);
	map_ptr->count_moves++;
	printf("You have made: %d moves!\n", map_ptr->count_moves);
	mlx_string_put(map_ptr->mlx_ptr, 1, 1, 0x224DDE, str1);
	mlx_string_put(map_ptr->mlx_ptr, 2, 1, 0x224DDE, str2);
	ft_draw_map(map_ptr);
	free(str1);
	free(str2);
}
