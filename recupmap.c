/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recupmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 11:36:01 by camillebarb       #+#    #+#             */
/*   Updated: 2022/02/03 13:26:09 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_recup_map_size(int fd)
{
    char    *line;
    int     total_nb_line;
    // int     fd;

    total_nb_line = 0;
    // fd = open(file_name, O_RDONLY);
    if (fd < 0)
        exit (1);
    
    line = get_next_line(fd);
    while (line)
    {
        total_nb_line++;
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
return (total_nb_line);
}

char    **ft_print_map(char *file_name)
{
    char **str_map;
    int  fd;
    int i;
    int nb_line;

    i = 0;
    fd = open(file_name, O_RDONLY);
    nb_line = ft_recup_map_size(fd);
    if (fd < 0)
        exit (1);
    str_map = malloc(sizeof(char *) * (nb_line + 1));
    if (!str_map)
        exit (1);
    while (nb_line > 0)
    {
        // printf("coucou, je rentre là\n");
        str_map[i] = get_next_line(fd);
        i++;
    }
    str_map[i] = 0;
    close(fd);
    return (str_map);
}

// int strlen(char *str)
// {
//     int i;
    
//     i = 0;
//     while (str[i])
//         i++;
//     return (i);
// }

// void    putstr(char *str)
// {
//     int i;

//     i = 0;
//     while (str[i])
//     {
//         write(1, str, strlen(str));
//         i++;
//     }
// }

int main()
{
    int     fd;
    int     nb;


    fd = open("map/map.ber", O_RDONLY);
    printf("%d", ft_recup_map_size(fd));
    return (0);
    // char    **tab;

    // index = 0;
    // // i = ft_recup_map_size("map/map.ber");
    // // printf("%d", i);
    // tab = ft_print_map("map/map.ber");
    // while (tab)
    // {
    //     printf("%s\n", tab[index]);
    //     index++;
    // }
}
