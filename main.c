/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:34:16 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/17 12:14:44 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* 
Filling my structure with basic variables
*/

void	ft_filler_basics(s_Map *map_ptr, char *str)
{
	map_ptr->file_name = ft_sdup(str); //nom de mon ficher .ber
	map_ptr->map_size = ft_recup_map_size(map_ptr->file_name); //taille de ma map (y)
	map_ptr->map_tab = ft_recup_map(map_ptr); //Je récupère la map dans un char **
	map_ptr->size_x = ft_len(map_ptr->map_tab[0]) - 1; //La taille de ma première ligne - le '\n'
	ft_strcpy(map_ptr->map_title, "so_long"); //Le nom de ma fenêtre de jeu
	map_ptr->width = 32;
	map_ptr->heigth = 32;
}

int	main(int argc, char **argv)
{
	s_Map	*map_ptr;

	if (argc == 2)
	{
		map_ptr = malloc(sizeof(struct s_Map));
		if (!map_ptr)
			return (1);
		if (ft_check_file_name(argv[1]) == 1)
			return (free(map_ptr), 1);
		ft_filler_basics(map_ptr, argv[1]);
		if (ft_check_all_errors(map_ptr) == 1)
			return (free(map_ptr), 1);
		ft_init_game(map_ptr);
		ft_game_inputs(map_ptr);
		mlx_loop(map_ptr->mlx_ptr);
	}
	else
		printf("Error\nMissing arguments!\n");
}
