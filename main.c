/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:34:16 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/09 16:06:39 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Je fais une fonction qui remplit les variables
que j'ai dans ma structure */

void	ft_filler(s_Map *map_ptr, char *argv1)
{
	map_ptr->file_name = ft_sdup(argv1);
	map_ptr->map_size = ft_recup_map_size(map_ptr->file_name);
	map_ptr->map_tab = ft_print_map(map_ptr);
	ft_strcpy(map_ptr->map_title, "so_long");
	//map_ptr->mlx_init = mlx_init();
	//map_ptr->mlx_window = mlx_new_window(map_ptr->mlx_init, int size_x, int size_y, )
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

// int main()
// {
//     map     so_long;

//     so_long.x = 0;
//     so_long.y = 0;
//     so_long.mlx = mlx_init();
//     if (!so_long.mlx)
//         return (0);
//     so_long.window = mlx_new_window(so_long.mlx, 800, 800, "First Window!");
//     //while (position.x < 400 && position.y < 400)
//     // {
//     //     mlx_pixel_put(mlx, window, position.x, position.y, 0x00CCFFCC);
//     //     position.x++;
//     //     position.y++;
//     // }
//     so_long.image = mlx_new_image(so_long.mlx, 800, 800);
//     mlx_put_image_to_window(so_long.mlx, so_long.window, so_long.image, so_long.x, so_long.y);
//     mlx_mouse_hook(so_long.window, handle_mouse, 0);
//     mlx_key_hook(so_long.window, handle_key, 0);
//     mlx_loop(so_long.mlx);
// }


int main(int argc, char **argv)
{
    struct s_Map	*map_ptr = NULL;

    if (argc == 2)
    {
		map_ptr = malloc(sizeof(struct s_Map));
		if (!map_ptr)
			return (1);
		if (ft_check_file_name(argv[1]) == 1)
			return (1);
		ft_filler(map_ptr, argv[1]);
		if (ft_check_all_errors(map_ptr) == 1)
			return (1);
		return (0);   
    }
	return (printf("Error\nMissing arguments!\n"), 1);
}