/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:34:16 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/14 16:30:08 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"

/* Je fais une fonction qui remplit les variables
que j'ai dans ma structure */

void	ft_filler_basics(s_Map *map_ptr, char *str)
{
	map_ptr->file_name = ft_sdup(str); //nom de mon ficher .ber
	map_ptr->map_size = ft_recup_map_size(map_ptr->file_name); //taille de ma map (y)
	map_ptr->map_tab = ft_recup_map(map_ptr); //Je récupère la map dans un char **
	map_ptr->size_x = ft_len (map_ptr->map_tab[0]); //La taille de ma première ligne
	ft_strcpy(map_ptr->map_title, "so_long"); //Le nom de ma fenêtre de jeu
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
		ft_filler(map_ptr, argv[1]);
		if (ft_check_all_errors(map_ptr) == 1)
			return (free(map_ptr), 1);
		ft_init_game(map_ptr);
		mlx_key_hook(map_ptr->mlx_window, key_hook, map_ptr);
		mlx_mouse_hook(map_ptr->mlx_window, mouse hook, map_ptr);
		mlx_loop(map_ptr->mlx_ptr, key_hook, );
		return (0);
	}
}
