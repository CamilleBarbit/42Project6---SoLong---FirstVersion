/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerror_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:44:20 by cbarbit           #+#    #+#             */
/*   Updated: 2022/02/28 10:10:58 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

/*
Function checking that map is surrounded by '1's
*/

int	ft_check_map_walls(t_map *map_ptr, int x, int y)
{
	while (map_ptr->map_tab[0][x + 1])
	{
		if (map_ptr->map_tab[0][x] != '1')
			return (ft_printf("Error\nWalls are missing!\n"), 1);
		x++;
	}
	x = 0;
	while (map_ptr->map_tab[map_ptr->map_size - 1][x + 1])
	{
		if (map_ptr->map_tab[map_ptr->map_size - 1][x] != '1')
			return (ft_printf("Error\nWalls are missing!\n"), 1);
		x++;
	}
	y = 1;
	while (y <= map_ptr->map_size - 2)
	{
		x = ft_len(map_ptr->map_tab[y]);
		if (map_ptr->map_tab[y][0] != '1' || map_ptr->map_tab[y][x - 2] != '1')
			return (ft_printf("Error\nWalls are missing!\n"), 1);
		y++;
	}
	return (0);
}

static int	ft_count_char(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] == c)
			count += 1;
		i++;
	}
	return (count);
}

/*
Function counting starting position, exit and items to collect
*/

int	ft_check_map_char(t_map *map_ptr)
{
	int	y;
	int	tab_count[3];

	tab_count[0] = 0;
	tab_count[1] = 0;
	tab_count[2] = 0;
	y = 1;
	while (y <= map_ptr->map_size - 2)
	{
		tab_count[0] += ft_count_char(map_ptr->map_tab[y], 'P');
		tab_count[1] += ft_count_char(map_ptr->map_tab[y], 'C');
		tab_count[2] += ft_count_char(map_ptr->map_tab[y], 'E');
		y++;
	}
	if (tab_count[0] != 1 || tab_count[1] < 1 || tab_count[2] < 1)
		return (ft_printf("Error\nSome characters are missing!\n"), 1);
	return (0);
}

/*
Function checking that my map is rectangle
*/

int	ft_check_map_form(t_map *map_ptr)
{
	int		tempo;
	int		len;
	int		y;

	tempo = ft_len(map_ptr->map_tab[0]);
	y = 1;
	while (y < map_ptr->map_size)
	{
		len = ft_len(map_ptr->map_tab[y]);
		if (y == map_ptr->map_size - 1)
			len += 1;
		if (len != tempo)
			return (ft_printf("Error\nString lengths are not the same!\n"), 1);
		y++;
	}
	return (0);
}

/*
Checking all errors
*/

int	ft_check_all_errors(t_map *map_ptr)
{
	if (ft_check_map_form(map_ptr) == 1)
		return (1);
	if (ft_check_map_walls(map_ptr, 0, 1) == 1)
		return (1);
	if (ft_check_map_char(map_ptr) == 1)
		return (1);
	return (0);
}
