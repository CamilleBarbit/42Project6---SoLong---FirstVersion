/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerror_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:44:20 by cbarbit           #+#    #+#             */
/*   Updated: 2022/02/09 16:01:32 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "string.h"

int	ft_check_map_walls(struct s_Map *map_ptr)
{
	int	x;
	int	y;

	x = 0;
	while (map_ptr->map_tab[0][x + 1])
	{
		if (map_ptr->map_tab[0][x] != '1')
			return (printf("Error\nWalls are missing!\n"), 1);
		x++;
	}
	x = 0;
	while (map_ptr->map_tab[map_ptr->map_size - 1][x + 1])
	{
		if (map_ptr->map_tab[map_ptr->map_size - 1][x] != '1')
			return (printf("Error\nWalls are missing!\n"), 1);
		x++;
	}
	y = 1;
	while (y <= map_ptr->map_size - 2)
	{
		x = ft_len(map_ptr->map_tab[y]); 
		if(map_ptr->map_tab[y][0] != '1' || map_ptr->map_tab[y][x - 2] != '1')
			return (printf("Error\nWalls are missing!\n"), 1);
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

int	ft_check_map_char(struct s_Map *map_ptr)
{
	int	y;
	int	tab_count[3] = {0, 0, 0};

	y = 1;
	while (y <= map_ptr->map_size - 2)
	{
		tab_count[0] += ft_count_char(map_ptr->map_tab[y], 'P');
		tab_count[1] += ft_count_char(map_ptr->map_tab[y], 'C');
		tab_count[2] += ft_count_char(map_ptr->map_tab[y], 'E');
		y++;
	}
	if (tab_count[0] != 1 || tab_count[1] < 1 || tab_count[2] < 1)
		return (printf("Error\nSome characters are missing!\n"), 1);
	return (0);
}


int	ft_check_map_form(struct s_Map *map_ptr)
{
	int		tempo;
	int		len;
	int		y;

	tempo = ft_len(map_ptr->map_tab[0]);
	y = 1;
	while (y < map_ptr->map_size)
	{
		len = ft_len(map_ptr->map_tab[y]);
		if (len != tempo)
			return (printf("Error\nString lengths are not the same!\n"), 1);	
		y++;
	}
	return (0);
}

int	ft_check_all_errors(struct s_Map *map_ptr)
{
	if (ft_check_map_form(map_ptr) == 1)
		return (ft_free_map(map_ptr), 1);
	if (ft_check_map_walls(map_ptr) == 1)
		return (ft_free_map(map_ptr), 1);
	if (ft_check_map_char(map_ptr) == 1)
		return (ft_free_map(map_ptr), 1);
	return (0);
}