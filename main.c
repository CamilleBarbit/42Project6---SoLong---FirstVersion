/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:34:16 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/12 13:19:22 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"

/* Je fais une fonction qui remplit les variables
que j'ai dans ma structure */

void	ft_filler(s_Map *map_ptr, char *argv1)
{
	map_ptr->file_name = ft_sdup(argv1);
	map_ptr->map_size = ft_recup_map_size(map_ptr->file_name);
	map_ptr->map_tab = ft_recup_map(map_ptr);
	map_ptr->size_x = ft_len (map_ptr->map_tab[0]);
	ft_strcpy(map_ptr->map_title, "so_long");
}

// int handle_mouse(int keycode, void *param)
// {
//     // printf("the keycode is: %d\n", keycode);
//     return (0);
// }

// int handle_key(int keycode, void *param) //handle echap
// {
//     if (keycode == 65307)
//         exit(1);
//     return (0);
// }

// int main(int argc, char **argv)
// {
//     s_Map	*map_ptr = NULL;

//     if (argc == 2)
//     {
// 		map_ptr = malloc(sizeof(struct s_Map));
// 		if (!map_ptr)
// 			return (1);
// 		if (ft_check_file_name(argv[1]) == 1)
// 			return (1);
// 		ft_filler(map_ptr, argv[1]);
// 		if (ft_check_all_errors(map_ptr) == 1)
// 			return (1);
// 		return (0);   
//     }
// 	return (printf("Error\nMissing arguments!\n"), 1);
// }

int	main()
{
	s_Map	*map_ptr;

	init_game(map_ptr);
	return (0);
}
