/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbarbit <cbarbit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:02:19 by cbarbit           #+#    #+#             */
/*   Updated: 2022/02/08 14:53:38 by cbarbit          ###   ########.fr       */
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

char	*ft_sdup(const char *src)
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


void	ft_free_map(char **tab, int size)
{
	int	y;

	y = 0;
	while (y < size)
	{
		free(tab[y]);
		y++;
	}
	free(tab);
}