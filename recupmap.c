/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recupmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:36:01 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/03 13:26:09 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Pourquoi ne pas déclarer la size de mon char ** en variable globale?

int	ft_recup_map_size(char *file_name)
{
	char	*line;
	int		total_nb_line;
	int		fd;

	if (!file_name)
		exit (1);
	total_nb_line = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit (1);
	line = get_next_line(fd);
	while (line)
	{
		total_nb_line++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close (fd);
	return (total_nb_line);
}

char	**ft_print_map(char *file_name)
{
	char	**str_map;
	int		fd;
	int		i;
	int		nb_line;

	if (!file_name)
		exit (1);
	i = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		exit (1);
	nb_line = ft_recup_map_size(file_name);
	str_map = malloc(sizeof(char *) * (nb_line + 1));
	if (!str_map)
		exit (1);
	while (nb_line > 0)
	{
		str_map[i] = get_next_line(fd);
		printf("%s", str_map[i]);
		i++;
		nb_line--;
	}
	str_map[i] = 0;
	close(fd);
	return (str_map);
}


// int main()
// {
// 	// int     fd;
// 	// int     nb;
// 	int     index;
// 	char    **tab;

// 	// fd = open("map/map.ber", O_RDONLY);
// 	// printf("%d", ft_recup_map_size(fd));
// 	// return (0);

// 	index = 0;
// 	tab = ft_print_map("map/map.ber");
// 	while (tab[index])
// 	{
// 		// putstr(tab[index]);
// 		// putstr("\n");
// 		// index++;
// 	}
// 	return (0);
// }

int	main()
{
	char	**tab;
	char	*file_name = "map/map.ber";
	int		size;
	//int		nb_line;

	size = ft_recup_map_size(file_name);
	tab = ft_print_map(file_name);
	//nb_line = ft_recup_map_size(file_name);
	//ft_check_walls(tab, file_name, size);
	return (0);
}