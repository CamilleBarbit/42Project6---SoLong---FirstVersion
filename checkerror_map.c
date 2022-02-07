/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerror_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 15:44:20 by cbarbit           #+#    #+#             */
/*   Updated: 2022/02/07 19:17:34 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "string.h"

int	ft_check_map_walls(char **tab, char *file_name, int size) //je lui envoie le nombre de lignes
{
	int	x;
	int	y;

	x = 0;
	while (tab[0][x + 1]) //tant que le caractère à (x + 1) != 0 -> il n'ira pas sur le \n car après il y a un \0
	{
		if (tab[0][x] != '1')
			return (write(1, "Error\nWalls are missing!\n", 25), 1);
		x++;
	}
	x = 0;
	while (tab[size - 1][x + 1])
	{
		if (tab[size - 1][x] != '1')
			return (write(1, "Error\nWalls are missing!\n", 25), 1);
		x++;
	}
	y = 1;
	while (y <= size - 2)
	{
		x = strlen(tab[y]); //strlen est la taille de la string en question - on ne veut pas la taille du tableau
		if(tab[y][0] != '1' || tab[y][x - 2] != '1') //je mets x - 2 car avant le \0, il y a un \n
			return (write(1, "Error\nWalls are missing!\n", 25), 1);
		y++;
	}
	return (0);
}

int	ft_check_map_form(char **tab, int size) //je lui envoie le nombre de lignes
{
	int		tempo;
	int		len;
	int		y;
	int		x;

	tempo = strlen(tab[0]);
	y = 1;
	x = 0;
	while (y <= size - 1)
	{
		len = strlen(tab[y]);
		if (len != tempo)
			return (write(1, "Error\nThe lengths are not the same!\n", 33), 1);
		y++;
	}
	return (0);
}


void	ft_free_map(char **tab, int size)
{
	int	y;

	y = 0;
	while (y < size)
	{
		free(tab[y]);
		y++;
	}
	free(tab);
}

// int	check_map_char(char **tab, int size)
// {
// 	int	x;
// 	int	y;
// 	int	count_p;
// 	int	count_e;
// 	int	count_item;

// 	x = 0;
// 	y = 1; //je ne vais pas vérifier ni la prem., ni la der. ligne car elles doivent contenir que des 1
// 	count_e = 0;
// 	count_p = 0;
// 	count_item = 0;
// 	while (y <= size - 2)
// 	{
// 		while (tab[y][x])
// 		{
// 			if (tab[y][x] == 'P')
// 				count_p += 1;
// 			if (tab[y][x] == 'E')
// 				count_e += 1;
// 			if(tab[y][x] == 'C')
// 				count_item += 1;
// 			x++;
// 		}
// 		x = 0;
// 		y++;
// 	}
// 	if (count_item < 1 || count_e < 1 || count_p != 1)
// 		return (write(1, "Error\nSome characters are missing!\n", 34), 1);
// 	return (0);
// }


// void	ft_handle_all_errors(char **tab, char *file_name, int size)
// {
// 	if (!tab)
// 		exit (1);
// 	if (!file_name)
// 		exit (1);
// 	if (size < 3)
// 		exit (1);
// 	if (!ft_check_walls)
// 	{

// 	}

// 	}
// }
