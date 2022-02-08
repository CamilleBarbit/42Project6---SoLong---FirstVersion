/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:34:16 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/08 11:36:48 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
    struct s_bonjour *bonjour;
    if (argc == 2)
    {
        if (ft_check_file_name(argv[1]) == 1)
            return (1);
        if (ft_print_map(argv[1]))
        
    }
}