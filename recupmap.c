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

int ft_recup_map_size(char *file_name)
{
    char    *line;
    int     total_nb_line;
    int     fd;

    total_nb_line = 0;
    fd = open(file_name, O_RDONLY);
    if (fd < 0)
    {
        printf("There is an error with the file descriptor");
        exit (1);
    }
    else
    {
        line = get_next_line(fd);
        while (line)
        {
            total_nb_line++;
            free(line);
            line = get_next_line(fd);
        }
        close(fd);
    }
    return (total_nb_line);
}

char    **ft_print_map(char *file_name, int nb_line)
{
    char **str_map;
    int  fd;
    int i;

    i = 0;
    fd = open(file_name, O_RDONLY);
    str_map = malloc(sizeof(char *) * (nb_line + 1));
    if (!str_map)
        exit (1);
    while (nb_line)
    {
        str_map[i] = get_next_line(fd);
        i++;
    }
    str_map[i] = '\0';
    close(fd);
    return (str_map);
}

int main()
{
    int i;
    int j;
    char **tab;

    j = 0;
    i = ft_recup_map_size("map/map.ber");
    printf("%d", i);
    while (tab)
    {
        tab[j] = ft_print_map("map/map.ber", i);
        printf("%s", tab[j]);
        j++;
    }
    

}