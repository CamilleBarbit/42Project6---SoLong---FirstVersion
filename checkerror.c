/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 15:48:21 by cbarbit           #+#    #+#             */
/*   Updated: 2022/02/04 15:48:30 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_walls(char **tab, char *file_name,int size) //je lui envoie le nombre de lignes
{
	int	x;
	int	y;

	if (!tab)
		exit (1);
	x = 0;
	while (tab[0][x + 1]) //tant que le caractère à (x + 1) != 0 -> il n'ira pas sur le \n car après il y a un \0
	{
		if (tab[0][x] != '1')
			exit(1);
		x++;
	}
	x = 0;
	while (tab[size - 1][x + 1])
	{
		if (tab[size - 1][x] != '1')
			exit(1);
		x++;
	}
	y = 1;
	while (y <= size - 2)
	{
		x = strlen(tab[y]); //strlen est la taille de la string en question - on ne veut pas la taille du tableau
		if(tab[y][0] != '1' || tab[y][x - 2] != '1') //je mets x - 2 car avant le \0, il y a un \n
			exit(1);
		y++;
	}
}

int	main()
{
	char	**tab;
	char	*file_name = "map/map.ber";
	int		size;
	//int		nb_line;

	size = ft_recup_map_size(file_name);
	tab = ft_print_map(file_name);
	//nb_line = ft_recup_map_size(file_name);
	ft_check_walls(tab, file_name, size);
	return (0);
}
