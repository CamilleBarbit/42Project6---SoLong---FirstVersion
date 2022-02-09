/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camillebarbit <camillebarbit@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:02:19 by cbarbit           #+#    #+#             */
/*   Updated: 2022/02/09 13:06:04 by camillebarb      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int ft_len(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_sdup(char *src)
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

void	ft_free_map(struct s_Map *map_ptr)
{
	int	y;

	y = 0;
	while (y < map_ptr->map_size)
	{
		free(map_ptr->map_tab[y]);
		y++;
	}
	free(map_ptr->map_tab);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}