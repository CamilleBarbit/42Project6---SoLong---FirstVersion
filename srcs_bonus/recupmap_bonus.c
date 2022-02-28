/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recupmap_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:36:01 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/28 10:11:53 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_recup_map_size(char *file_name)
{
	char	*line;
	int		total_nb_line;
	int		fd;

	total_nb_line = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (1);
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
		return (ft_printf("Error\nProblem with the number of lines!\n"), -1);
	return (total_nb_line);
}

char	**ft_recup_map(t_map *map_ptr)
{
	int	fd;
	int	i;
	int	nb_line;

	i = 0;
	nb_line = map_ptr->map_size;
	fd = open(map_ptr->file_name, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map_ptr->map_tab = malloc(sizeof(char *) * (nb_line + 1));
	if (!map_ptr->map_tab)
		return (NULL);
	while (nb_line > 0)
	{
		map_ptr->map_tab[i] = get_next_line(fd);
		i++;
		nb_line--;
	}
	map_ptr->map_tab[i] = 0;
	close(fd);
	return (map_ptr->map_tab);
}
