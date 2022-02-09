/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recupmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:36:01 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/09 11:35:02 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


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
		return (write(1, "Error\nProblem with the number of lines\n", 36), -1);
	return (total_nb_line);
}

char	**ft_print_map(struct s_Map *map_ptr)
{
	int	fd;
	int	i;
	int	nb_line;

	i = 0;
	nb_line = map_ptr->map_size;
	fd = open(map_ptr->file_name, O_RDONLY);
	map_ptr->map_tab = malloc(sizeof(char *) * (nb_line + 1));
	if (!map_ptr->map_tab)
		return (NULL);
	while (nb_line > 0)
	{
		map_ptr->map_tab[i] = get_next_line(fd);
		//printf("%s", map_ptr->map_tab[i]);
		i++;
		nb_line--;
	}
	map_ptr->map_tab[i] = 0;
	close(fd);
	return (map_ptr->map_tab);
}


// int	main()
// {
// 	char	**tab;
// 	char	*file_name = "map/map.ber";
// 	int		size;
// 	int		nb_line;
	
// 	size = ft_recup_map_size(file_name);
// 	tab = ft_print_map(file_name);
// 	ft_check_map_char(tab, size);
// 	nb_line = ft_recup_map_size(file_name);
// 	ft_check_map_walls(tab, file_name, size);
// 	ft_check_map_form(tab, size);
// 	return (0);
// }