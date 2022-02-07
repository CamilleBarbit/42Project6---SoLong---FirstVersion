/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recupmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:36:01 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/07 17:43:39 by cbarbit          ###   ########.fr       */
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
	nb_line = ft_recup_map_size(file_name); //si nb_line < 3, alors il y a une erreur
	str_map = malloc(sizeof(char *) * (nb_line + 1));
	if (!str_map)
		exit (1);
	while (nb_line > 0)
	{
		str_map[i] = get_next_line(fd);
		//printf("%s", str_map[i]);
		i++;
		nb_line--;
	}
	str_map[i] = 0;
	close(fd);
	return (str_map);
}

int	ft_count_char(char *str, char c)
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
	int	*tab_count[3] = {0, 0, 0};

	x = 0;
	y = 1;
	while (y <= size - 2)
	{
		tab_count[0] += ft_count_char(tab[y], 'P');
		tab_count[1] += ft_count_char(tab[y], 'C');
		tab_count[2] += ft_count_char(tab[y], 'E');
		y++;
	}
	printf("PP %d\n", tab_count[0]);
	printf("CC %d\n", tab_count[1]);
	printf("EE %d\n", tab_count[2]);
	if (tab_count[0] != 1 || tab_count[1] < 1 || tab_count[2] < 1)
		return (write(1, "Error\nSome characters are missing!\n", 34), 1);
	return (write(1, "TOTO BEN\n", 9), 0);
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
	ft_check_map_char(tab, size);
	//nb_line = ft_recup_map_size(file_name);
	//ft_check_walls(tab, file_name, size);
	return (0);
}