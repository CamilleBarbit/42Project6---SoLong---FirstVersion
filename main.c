/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:34:16 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/08 14:51:12 by cbarbit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Je fais une fonction qui remplit les variables
que j'ai dans ma structure */

int ft_len(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

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

void	ft_print_map(struct Map *map_ptr)
{
	int		fd;
	int		i;
	int		nb_line;

	i = 0;
	nb_line = map_ptr->map_size;
	if (nb_line == -1)
		return ;
	fd = open(map_ptr->file_name, O_RDONLY);
	map_ptr->map_tab[i] = malloc(sizeof(char *) * (nb_line + 1));
	if (!map_ptr->map_tab)
		return ;
	while (nb_line > 0)
	{
		map_ptr->map_tab[i] = get_next_line(fd);
		printf("%s", map_ptr->map_tab[i]);
		i++;
		nb_line--;
	}
	map_ptr->map_tab[i] = 0;
	close(fd);
}

char	*sdup(char *src)
{
	char	*dest;
	int		i;
	int		j;

	i = 0;
	j = ft_len(src);
	dest = malloc(sizeof(char) * j + 1);
	if (!dest)
		return (0);
	while (i < j)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}



void	ft_filler(Map *map_ptr, char *argv1)
{
	map_ptr->file_name = ft_sdup(argv1);
	map_ptr->map_size = ft_recup_map_size(map_ptr->file_name);
	map_ptr->map_tab = ft_print_map(map_ptr);
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
    struct Map	*map_ptr = NULL;

    if (argc == 2)
    {
		map_ptr = malloc(sizeof(struct Map));
		if (!map_ptr)
			return (1);
		ft_filler(map_ptr, argv[1]); //je lui envoie l'adresse de ma struct 






        // if (ft_check_file_name(argv[1]) == 1)
        //     return (1);
        // if (ft_print_map(argv[1]))
        
    }
	return (0);
}