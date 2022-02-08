/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recupmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:36:01 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/08 11:21:31 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// Pourquoi ne pas déclarer la size de mon char ** en variable globale?

int	ft_recup_map_size(char *file_name)
{
	char	*line;
	int		total_nb_line;
	int		fd;

	total_nb_line = 0;
	fd = open(file_name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		total_nb_line++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close (fd);
	if (total_nb_line < 3)
		return (write(1, "Error\nProblem with the lines in the file\n", 38), -1);
	return (total_nb_line);
}

char	**ft_print_map(char *file_name)
{
	char	**str_map;
	int		fd;
	int		i;
	int		nb_line;

	i = 0;
	fd = open(file_name, O_RDONLY);
	nb_line = ft_recup_map_size(file_name);
	if (nb < 0)
		return ;
	str_map = malloc(sizeof(char *) * (nb_line + 1));
	if (!str_map)
		return ;
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


int	main()
{
	char	**tab;
	char	*file_name = "map/map.ber";
	int		size;
	//int		nb_line;

	size = ft_recup_map_size(file_name);
	tab = ft_print_map(file_name);
	//ft_check_map_char(tab, size);
	//nb_line = ft_recup_map_size(file_name);
	//ft_check_map_walls(tab, file_name, size);
	//ft_check_map_form(tab, size);
	return (0);
}