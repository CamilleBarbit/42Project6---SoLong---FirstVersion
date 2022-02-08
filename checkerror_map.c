/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerror_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:44:20 by cbarbit           #+#    #+#             */
/*   Updated: 2022/02/08 14:09:58 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "string.h"

int	ft_check_map_walls(char **tab, char *file_name, int size) //je lui envoie le nombre de lignes
{
	int	x;
	int	y;

	x = 0;
	while (tab[0][x + 1])
	{
		if (tab[0][x] != '1')
			return (ft_free_map(tab, size), write(1, "Error\nWalls are missing!\n", 25), 1);
		x++;
	}
	x = 0;
	while (tab[size - 1][x + 1])
	{
		if (tab[size - 1][x] != '1')
			return (ft_free_map(tab, size), write(1, "Error\nWalls are missing!\n", 25), 1);
		x++;
	}
	y = 1;
	while (y <= size - 2)
	{
		x = strlen(tab[y]); 
		if(tab[y][0] != '1' || tab[y][x - 2] != '1')
			return (ft_free_map(tab, size), write(1, "Error\nWalls are missing!\n", 25), 1);
		y++;
	}
	return (ft_free_map(tab, size), write(1, "Tout va bien\n", 12), 0);
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

int	ft_check_map_char(char **tab, int size)
{
	int	x;
	int	y;
	int	tab_count[3] = {0, 0, 0};

	x = 0;
	y = 1;
	while (y <= size - 2)
	{
		tab_count[0] += ft_count_char(tab[y], 'P');
		tab_count[1] += ft_count_char(tab[y], 'C');
		tab_count[2] += ft_count_char(tab[y], 'E');
		y++;
	}
	if (tab_count[0] != 1 || tab_count[1] < 1 || tab_count[2] < 1)
	{
		ft_free_map(tab, size);
		return (write(1, "Error\nSome characters are missing!\n", 34), 1);
	}
	ft_free_map(tab, size);	
	return (0);
}


int	ft_check_map_form(char **tab, int size)
{
	int		tempo;
	int		len;
	int		y;

	tempo = strlen(tab[0]);
	y = 1;
	while (y <= size - 1)
	{
		len = strlen(tab[y]);
		if (len != tempo)
		{
			ft_free_map(tab, size);
			return (write(1, "Error\nString lengths are not the same!\n", 33), 1);
		}
		y++;
	}
	ft_free_map(tab, size);
	return (0);
}
