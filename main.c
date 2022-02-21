/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:34:16 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/21 15:30:50 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* 
Filling my structure with basic variables
*/

void	ft_filler_basics(s_Map *map_ptr, char *str)
{
	map_ptr->count_moves = 0;
	map_ptr->total_items = 0;
	map_ptr->items_collected = 0;
	map_ptr->player_x = 0;
	map_ptr->player_y = 0;
	map_ptr->im_heigth = 80;
	map_ptr->im_width = 80;
	map_ptr->file_name = ft_sdup(str);
	map_ptr->map_size = ft_recup_map_size(map_ptr->file_name);
	map_ptr->map_tab = ft_recup_map(map_ptr);
	map_ptr->size_x = ft_len(map_ptr->map_tab[0]) - 1;
	ft_strcpy(map_ptr->map_title, "so_long");
	map_ptr->mlx_ptr = NULL;
	map_ptr->mlx_window = NULL;
	map_ptr->mlx_exit = NULL;
	map_ptr->mlx_walls = NULL;
	map_ptr->mlx_player = NULL;
	map_ptr->mlx_items = NULL;
	map_ptr->mlx_empty_spaces = NULL;
}


int	main(int argc, char **argv)
{
	s_Map	*map_ptr;

	if (argc == 2)
	{
		map_ptr = malloc(sizeof(struct s_Map));
		if (!map_ptr)
			return (printf("Error\nFailed to allocate memory\n!"), 1);
		if (ft_check_file_name(argv[1]) == 1)
			return (1);//ft_free_map(map_ptr), 1);
		ft_filler_basics(map_ptr, argv[1]);
		if (ft_check_all_errors(map_ptr) == 1)
			return (1);//ft_free_map(map_ptr), 1);
		ft_init_game(map_ptr);
		ft_game_inputs(map_ptr);
		mlx_loop(map_ptr->mlx_ptr);
		ft_dealloc(map_ptr);
	}
	else
		printf("Error\nMissing a <map>.ber as second argument!\n");
	return (0);
}
